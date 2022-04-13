#include "order_controller.h"

using namespace Services;

System::Boolean OrderController::add_request(System::Void)
{
	Services::OrderControllerDbScheme^ request_data = gcnew Services::OrderControllerDbScheme();

	request_data->address = this->order_token.OrderAddress;
	request_data->car_class = this->order_token.CarModelClass->Name;
	request_data->car_type = this->order_token.CarModelType.ToString();
	
	request_data->driver_guid = this->order_token.DriverTokenGuid.ToString();
	request_data->order_guid = this->order_token.OrderTokenGuid.ToString();
	request_data->date_time = this->order_token.OrderDate.ToString();
	request_data->order_status = Convert::ToBoolean(0).ToString();

	this->service_sql_manager->TableName = "order_collection";
	return this->service_sql_manager
		->set_scheme_struct<Services::OrderControllerDbScheme^>()
		->send_database_data(request_data);
}

System::Boolean OrderController::accept_request(System::Guid order_id, System::Guid driver_id)
{
	this->service_sql_manager->TableName = "order_collection";
	auto request_keys_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_keys_list->Add(gcnew IDatabaseManager::KeyValuePair("order_guid", order_id.ToString()));

	List<IDatabaseManager::RequestRow^>^ request_row = this->service_sql_manager
		->set_scheme_struct<Services::OrderControllerDbScheme^>()->get_database_data(request_keys_list);
	if (request_row->Count > 1 || request_row == nullptr)
		throw gcnew Services::OrderControllerTokenException("From OrderController: order_guid accept_request");

	OrderControllerDbScheme^ request_result = safe_cast<OrderControllerDbScheme^>(request_row[0]);
	bool delete_check = this->service_sql_manager->set_scheme_struct<Services::OrderControllerDbScheme^>()
		->delete_database_data(gcnew Services::IDatabaseManager::KeyValuePair("order_guid", order_id.ToString()));
	if (delete_check != false)
	{
		request_result->driver_guid = driver_id.ToString();
		request_result->order_status = Convert::ToBoolean(1).ToString();

		bool send_check = this->service_sql_manager->set_scheme_struct<Services::OrderControllerDbScheme^>()
			->send_database_data(request_result);
		if (send_check != true) return false;
	}
	else return false;

	this->order_token.DriverTokenGuid = driver_id;
	this->order_token.OrderStatus = true;
	return true;
}

generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
Task<System::Boolean>^ OrderController::registration_order(System::String^ request_address, Models::CarModelTypes car_type)
{
	this->order_token = OrderControllerToken(request_address, car_type, TCarModelClass::typeid);
	this->cancel_source = gcnew CancellationTokenSource();
	this->request_cancel_token = cancel_source->Token;

	if (this->add_request() != true) return nullptr;
	Task<System::Boolean>^ order_processing = gcnew Task<System::Boolean>(
		gcnew System::Func<bool>(this, &Services::OrderController::order_process), this->request_cancel_token);

	order_processing->ContinueWith(gcnew System::Action<Task<bool>^>(this, &Services::OrderController::order_callback));
	order_processing->Start();

	return order_processing;
}

System::Boolean OrderController::cancellation_order(System::Void)
{
	this->service_sql_manager->TableName = "order_collection";
	System::Boolean check = this->service_sql_manager
		->set_scheme_struct<Services::OrderControllerDbScheme^>()
		->delete_database_data(gcnew IDatabaseManager::KeyValuePair("order_guid", this->order_token.OrderTokenGuid.ToString()));

	try { this->cancel_source->Cancel(); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	this->order_token.DriverTokenGuid = System::Guid::Empty;
	this->order_token.OrderStatus = false;
	return check;
}

System::Boolean OrderController::order_process(System::Void)
{
	for (System::UInt32 seconds = 0; seconds < ORDER_REQUEST_SECOND; seconds++)
	{
		if (this->request_cancel_token.IsCancellationRequested) { break; }
		List<IDatabaseManager::KeyValuePair^>^ search_param = gcnew List<IDatabaseManager::KeyValuePair^>();
		search_param->Add(gcnew IDatabaseManager::KeyValuePair("order_guid", this->order_token.OrderTokenGuid.ToString()));

		this->service_sql_manager->TableName = "order_collection";
		List<IDatabaseManager::RequestRow^>^ request_result = this->service_sql_manager
			->set_scheme_struct<Services::OrderControllerDbScheme^>()
			->get_database_data(search_param);
		if (request_result == nullptr) return false;

		// ������� ������ ��������� � ������� (�.� guid ���������� ����)
		IDatabaseManager::RequestRow^ request_row = request_result->default[0];
		Services::OrderControllerDbScheme^ request_obj = safe_cast<Services::OrderControllerDbScheme^>(request_row);

		if(System::Boolean::Parse(request_obj->order_status) == true) return true;
		Thread::Sleep(System::TimeSpan(0, 0, 1));
	}
	return false;
}