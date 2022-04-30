#include "depot_manager.h"

using namespace Services;

generic <class TEnum> TEnum convert_to_enum(System::String^ value)
{ return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true)); }

List<IDatabaseManager::KeyValuePair^>^ create_car_request(Models::CarBaseModel^ car_model, System::Type^ car_class)
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_class", car_class->Name));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_type", car_model->CarType.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_speed", car_model->CarSpeed.ToString()));
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("car_color", car_model->CarColor.ToString()));

	return key_pair;
}

System::UInt32 DepotManager::CarTypePrice::get(Models::CarModelTypes car_type_value)
{
	switch (car_type_value)
	{
	case Models::CarModelTypes::CarTypeChild:
		return System::UInt32::Parse((System::String^)this->configuration["car_child_type_price"]);
	case Models::CarModelTypes::CarTypeEconom:
		return System::UInt32::Parse((System::String^)this->configuration["car_econom_type_price"]);
	case Models::CarModelTypes::CarTypePremium:
		return System::UInt32::Parse((System::String^)this->configuration["car_premium_type_price"]);
	}
}

Manager::IServiceBase::ServiceQuery^ DepotManager::service_query_handler(System::TimeSpan work_time)
{
	Manager::IServiceBase::ServiceQuery^ service_query = gcnew Manager::IServiceBase::ServiceQuery();

	service_query->Message = "Message from Depot Manager";
	service_query->ServiceType = this->GetType();
	service_query->State = this->ServiceState;

	return service_query;
}

System::Boolean DepotManager::delete_car_process(Services::CarModelDbScheme^ item)
{
	System::Int32 garage_car_count(0);
	try { garage_car_count = System::Int32::Parse(item->car_count); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	System::Boolean delete_check(true);
	if (garage_car_count <= 1)
	{
		delete_check = this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->delete_database_data(gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid));
	}
	else
	{
		item->car_count = System::Int32(garage_car_count - 1).ToString();
		delete_check = this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid));
	}

	return delete_check;
}

System::Boolean DepotManager::delete_car_model_by_guid(System::Guid group_id)
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("group_guid", group_id.ToString()));

	auto request_items = this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);

	if (request_items == nullptr || request_items->Count <= 0) return false;
	Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);

	return this->delete_car_process(item);
}

generic <class TCarClass> where TCarClass : Models::CarBaseModel
	System::Boolean DepotManager::delete_car_model(TCarClass car_model) 
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = create_car_request(car_model, TCarClass::typeid);
	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);

	if (request_items == nullptr || request_items->Count <= 0) return false;
	Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);

	return this->delete_car_process(item);
}

generic <class TCarClass> where TCarClass : Models::CarBaseModel
	System::Boolean DepotManager::rent_car_model(TCarClass car_model, System::Guid driver_guid)
{
	if (this->drive_complex != nullptr) return false;
	List<IDatabaseManager::KeyValuePair^>^ key_pair = create_car_request(car_model, TCarClass::typeid);

	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items == nullptr || request_items->Count <= 0) return false;
	Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);
	
	System::Int32 db_model_count(0);
	try { db_model_count = System::Int32::Parse(item->car_count) - 1; }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }
	
	if (db_model_count > 0) 
	{
		item->car_count = db_model_count.ToString();
		if (!this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid))) 
			return false;
	}
	else 
	{
		if (!service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()->delete_database_data(
			gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid))) return false;
	}
	Services::DriveComplexDbScheme^ scheme = gcnew Services::DriveComplexDbScheme();
	scheme->driver_state = DriveComplexToken::DriverStateType::Idle.ToString();
	scheme->car_class = TCarClass::typeid->Name;
	scheme->car_type = car_model->CarType.ToString();
	scheme->driver_guid = driver_guid.ToString();

	if (this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->send_database_data(scheme) != true)
		throw gcnew Services::DriveComplexTokenException(DepotManager::typeid, "rent_car_model");

	this->drive_complex = gcnew DriveComplexToken(car_model, driver_guid, TCarClass::typeid);
	return true;
}

System::Boolean DepotManager::return_car_model(System::Void)
{
	if (this->drive_complex == nullptr) return false;
	List<IDatabaseManager::KeyValuePair^>^ key_pair 
		= create_car_request(this->drive_complex->CarModel, this->drive_complex->CarModelType);

	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items != nullptr && request_items->Count > 0)
	{
		Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);
		System::Int32 new_model_count(1);
		try { new_model_count = System::Int32::Parse(item->car_count) + 1; }
		catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

		item->car_count = new_model_count.ToString();
		if (!service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid))) 
			return false;
	}
	else 
	{
		Services::CarModelDbScheme^ model = gcnew Services::CarModelDbScheme();
		model->car_class = this->drive_complex->CarModelType->Name;
		model->car_type = this->drive_complex->CarModel->CarType.ToString();
		model->car_speed = this->drive_complex->CarModel->CarSpeed.ToString();
		model->car_color = this->drive_complex->CarModel->CarColor.ToString();
		model->car_count = System::UInt32(1).ToString();
		model->group_guid = System::Guid::NewGuid().ToString();

		if(!service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()->send_database_data(model)) 
			return false;
	}

	if (!service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->delete_database_data(gcnew IDatabaseManager::KeyValuePair("driver_guid", this->DriverGuid.ToString()))) 
		return false;

	this->drive_complex = nullptr;
	return true;
}

System::Boolean DepotManager::update_drive_state(DriveComplexToken::DriverStateType state)
{
	if (this->drive_complex == nullptr) return false;

	List<IDatabaseManager::KeyValuePair^>^ key_pair = gcnew List<IDatabaseManager::KeyValuePair^>();
	key_pair->Add(gcnew IDatabaseManager::KeyValuePair("driver_guid", this->DriverGuid.ToString()));

	auto request_items = service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(key_pair, false);
	if (request_items == nullptr || request_items->Count <= 0) return false;

	Services::DriveComplexDbScheme^ response_item = nullptr;
	try { response_item = safe_cast<Services::DriveComplexDbScheme^>(request_items[0]); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	response_item->driver_state = state.ToString();
	if (!service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->update_database_date(response_item, gcnew IDatabaseManager::KeyValuePair("driver_guid", response_item->driver_guid)))
		return false;

	this->drive_complex->DriverState = state;
	return true;
}

generic <class TCarClass> where TCarClass : Models::CarBaseModel
	System::Boolean DepotManager::add_car_model(TCarClass car_model, System::UInt16 count)
{
	List<IDatabaseManager::KeyValuePair^>^ key_pair = create_car_request(car_model, TCarClass::typeid);
	auto request_items = service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(key_pair, false);

	if (request_items == nullptr || request_items->Count <= 0) 
	{
		Services::CarModelDbScheme^ model = gcnew Services::CarModelDbScheme();
		model->car_class = TCarClass::typeid->Name;
		model->car_type = car_model->CarType.ToString();
		model->car_speed = car_model->CarSpeed.ToString();
		model->car_color = car_model->CarColor.ToString();
		model->car_count = count.ToString();
		model->group_guid = System::Guid::NewGuid().ToString();

		if (service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->send_database_data(model) != true) return false;
	}
	else 
	{
		Services::CarModelDbScheme^ item = safe_cast<Services::CarModelDbScheme^>(request_items[0]);
		System::Int32 new_model_count(0);

		try { new_model_count = System::Int32::Parse(item->car_count) + count; }
		catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

		item->car_count = new_model_count.ToString();
		if (!service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
			->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("group_guid", item->group_guid)))
			return false;
	}
	return true;
}

Models::CarBaseModel^ DepotManager::CarModel::get(System::Void) 
{
	if (this->drive_complex == nullptr) return nullptr;
	return (Models::CarBaseModel^)this->drive_complex->CarModel->Clone();
}

System::Type^ DepotManager::CarModelType::get(System::Void)
{
	if (this->drive_complex == nullptr) return nullptr;
	return this->drive_complex->CarModelType;
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

Generic::List<System::Guid>^ DepotManager::get_all_drivers(System::Void)
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

Generic::List<DepotManager::CarGarageItems>^ DepotManager::get_all_cars(System::Void)
{
	List<DepotManager::CarGarageItems>^ car_list = gcnew List<DepotManager::CarGarageItems>();
	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();

	request_key->Add(gcnew IDatabaseManager::KeyValuePair("car_class", "CarLightModel"));
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("car_class", "CarHeavyModel"));

	auto response_param = this->service_sql_manager->set_scheme_struct<Services::CarModelDbScheme^>()
		->get_database_data(request_key, true);
	if (response_param == nullptr || response_param->Count <= 0) return nullptr;

	for each (auto item in response_param) 
	{
		Services::CarModelDbScheme^ car_model = nullptr;
		Services::DepotManager::CarGarageItems garage_item;

		Models::CarModelTypes garage_item_type;
		Models::CarModelColor garage_item_color;
		System::UInt32 garage_item_speed(0);

		try {
			car_model = safe_cast<Services::CarModelDbScheme^>(item);
			garage_item.Guid = System::Guid::Parse(car_model->group_guid);
			garage_item_type = convert_to_enum<Models::CarModelTypes>(car_model->car_type);
			garage_item_color = convert_to_enum<Models::CarModelColor>(car_model->car_color);
			garage_item_speed = System::UInt32::Parse(car_model->car_speed);
			garage_item.CarCount = System::UInt32::Parse(car_model->car_count);
		}
		catch (System::Exception^ error) { Console::WriteLine(error->Message); continue; }
		
		if (car_model->car_class == "CarHeavyModel")
		{
			garage_item.CarModel = gcnew Models::CarHeavyModel(garage_item_type, garage_item_color, garage_item_speed);
			garage_item.CarClass = Models::CarHeavyModel::typeid;
			
		}
		else if (car_model->car_class == "CarLightModel")
		{
			garage_item.CarModel = gcnew Models::CarLightModel(garage_item_type, garage_item_color, garage_item_speed);
			garage_item.CarClass = Models::CarLightModel::typeid;
		}
		else continue;
		car_list->Add(garage_item);
	}

	return car_list;
}

Services::DriveComplexDbScheme^ DepotManager::get_driver_complexs(System::Guid driver_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ request_param = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_param->Add(gcnew IDatabaseManager::KeyValuePair("driver_guid", driver_guid.ToString()));

	auto response_param = this->service_sql_manager->set_scheme_struct<Services::DriveComplexDbScheme^>()
		->get_database_data(request_param, false);

	if (request_param == nullptr || request_param->Count > 1)
		throw gcnew Services::DriveComplexTokenException(DepotManager::typeid, "get_driver_complexs");
	return safe_cast<Services::DriveComplexDbScheme^>(response_param[0]);
}