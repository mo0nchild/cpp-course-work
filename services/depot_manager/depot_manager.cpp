#include "depot_manager.h"

using namespace Services;

generic <class TCarClass> where TCarClass : Models::CarBaseModel
System::Boolean DepotManager::rent_car_model(Models::CarBaseModel^ car_model)
{
	/*List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_class", TCarClass::typeid->Name));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_type", car_model->CarType.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_speed", car_model->CarSpeed.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_color", car_model->CarColor.ToString()));

	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items == nullptr || request_items->Count <= 0) return false;

	Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);
	Models::CarModelTypes car_type;
	try { car_type = convert_to_enum<Models::CarModelTypes>(item->car_type); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	Models::CarBaseModel^ car_class = nullptr;
	if (item->car_class == Models::CarLightModel::typeid->Name) 
		car_class = gcnew Models::CarLightModel(car_type, );
	else if (item->car_class == Models::CarHeavyModel::typeid->Name) car_class = gcnew Models::CarHeavyModel();
	else return false;

	this->drive_complex = gcnew DriveComplexToken();*/
	return true;
}

System::Boolean DepotManager::return_car_model(System::Void)
{
	return true;
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
		throw gcnew Services::DriveComplexTokenException("From DepotManager: get_driver_complexs");
	return safe_cast<Services::DriveComplexDbScheme^>(response_param[0]);
}