#include "depot_manager.h"

using namespace Services;

generic <class TEnum> TEnum convert_to_enum(System::String^ value)
{ return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true)); }

generic <class TCarClass> where TCarClass : Models::CarBaseModel
	System::Boolean DepotManager::rent_car_model(TCarClass car_model, System::Guid driver_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_class", TCarClass::typeid->Name));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_type", car_model->CarType.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_speed", car_model->CarSpeed.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_color", car_model->CarColor.ToString()));

	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items == nullptr || request_items->Count <= 0) return false;
	Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);
	
	System::Int32 db_model_count(0);
	try { db_model_count = System::Int32::Parse(item->car_count) - 1; }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); }

	if (service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()->delete_database_data(
		gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid))) return false;
	if (db_model_count > 0) 
	{
		item->car_count = db_model_count.ToString();
		this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->send_database_data(item);
	}
	this->drive_complex = gcnew DriveComplexToken(car_model, driver_guid);
	return true;
}

System::Boolean DepotManager::return_car_model(System::Void)
{


	this->drive_complex = nullptr;
	return true;
}

System::Boolean DepotManager::update_drive_token(System::Guid driver_guid)
{

}

generic <class TCarClass> where TCarClass : Models::CarBaseModel
	System::Boolean DepotManager::add_car_model(TCarClass car_model, System::UInt16 count)
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_class", TCarClass::typeid->Name));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_type", car_model->CarType.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_speed", car_model->CarSpeed.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_color", car_model->CarColor.ToString()));

	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items == nullptr || request_items->Count <= 0) return false;


}

System::Guid DepotManager::DriverGuid::get(System::Void)
{
	if (this->drive_complex != nullptr) return this->drive_complex->DriverGuid;
	return System::Guid::Empty;
}

DriveComplexToken::DriverStateType DepotManager::DriverState::get(System::Void)
{
	if (this->drive_complex != nullptr) return this->drive_complex->DriverState;
	throw gcnew Services::DriveComplexTokenException(DepotManager::typeid, "drive complex not found");
}

List<System::Guid>^ DepotManager::get_drivers_guid(System::Void)
{
	List<System::Guid>^ driver_list = gcnew List<System::Guid>();
	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();

	request_key->Add(gcnew IDatabaseManager::KeyValuePair("car_class", "CarLightModel"));
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("car_class", "CarHeavyModel"));

	auto response_param = this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(request_key, true);

	for each (IDatabaseManager::RequestRow^ item in response_param) 
	{
		try { 
			System::Guid value = System::Guid::Parse(safe_cast<Services::DriveComplexDbScheme^>(item)->driver_guid);
			driver_list->Add(value);
		} 
		catch (System::Exception^ error) { Console::WriteLine(error->Message); }
	}
	return driver_list;
}

Services::DriveComplexDbScheme^ DepotManager::get_driver_complexs(System::Guid driver_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ request_param = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_param->Add(gcnew IDatabaseManager::KeyValuePair("driver_guid", driver_guid.ToString()));

	auto response_param = this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(request_param, true);

	if (request_param == nullptr || request_param->Count > 1)
		throw gcnew Services::DriveComplexTokenException(DepotManager::typeid, "get_driver_complexs");
	return safe_cast<Services::DriveComplexDbScheme^>(response_param[0]);
}