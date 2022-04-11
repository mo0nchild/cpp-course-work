#include "order_controller.h"

using namespace Services;

generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
System::Void OrderController::registration_order(String^ request_address, Models::CarModelTypes car_type)
{
	this->order_toker = OrderControllerToken(request_address, car_type);
	this->cancel_source = gcnew CancellationTokenSource();
	this->request_cancel_token = cancel_source->Token;

	this->service_depot_manager->add_request(order_toker);
	Task<System::Boolean>^ order_processing = gcnew Task<System::Boolean>(
		gcnew System::Func<bool>(this, &Services::OrderController::order_process), 
		this->request_cancel_token
	);

	order_processing->ContinueWith(gcnew System::Action<Task<bool>^>(
		this, &Services::OrderController::order_callback));
	order_processing->Start();
}

System::Void OrderController::cancellation_order(System::Void)
{
	this->service_depot_manager->check_request(
		this->order_toker.OrderTokenGuid, DepotManager::RequestType::Delete);

	try { this->cancel_source->Cancel(); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); }
}

System::Boolean OrderController::order_process(System::Void)
{
	for (System::UInt32 seconds = 0; seconds < ORDER_REQUEST_SECOND; seconds++)
	{
		if (this->request_cancel_token.IsCancellationRequested) { break; }
		else if (this->service_depot_manager->check_request(this->order_toker.OrderTokenGuid, 
			DepotManager::RequestType::Process)) { return true; }

		Thread::Sleep(System::TimeSpan(0, 0, 1));
	}
	return false;
}