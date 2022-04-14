#include "depot_manager.h"

using namespace Services;

generic <class TCarClass> where TCarClass : Models::CarBaseModel
System::Boolean DepotManager::rent_car_model(Models::CarBaseModel^ car_model)
{
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

	this->service_sql_manager->TableName = "drive_complex";
	auto response_param = this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(request_key);

	for each (auto item in response_param) 
	{ driver_list->Add(System::Guid::Parse(safe_cast<Services::DriveComplexDbScheme^>(item)->driver_guid)); }

	return driver_list;
}

Services::DriveComplexDbScheme^ DepotManager::get_driver_complexs(System::Guid driver_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ request_param = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_param->Add(gcnew IDatabaseManager::KeyValuePair("driver_guid", driver_guid.ToString()));

	this->service_sql_manager->TableName = "drive_complex";
	auto response_param = this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(request_param);

	if (request_param == nullptr || request_param->Count > 1)
		throw gcnew Services::DriveComplexTokenException("From DepotManager: get_driver_complexs");
	return safe_cast<Services::DriveComplexDbScheme^>(response_param[0]);
}