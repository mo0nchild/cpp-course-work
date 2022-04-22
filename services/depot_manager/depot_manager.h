#pragma once
#include "../../manager/manager.h"
#include "../../models/cars_model/cars_model.h"
#include "../database_provider/database_provider.h"
#include "depot_manager_token.h"
#include "depot_manager_scheme.h"

#define GARAGE_COLLECTION_SIZE 100

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Collections;

	public interface class IDepotManager 
	{
	public:		System::Boolean return_car_model(System::Void);
	public:	
		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			System::Boolean rent_car_model(TCarClass car_model, System::Guid driver_guid);

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			System::Boolean add_car_model(TCarClass car_model, System::UInt16 count);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class DepotManager sealed : Manager::ServiceBase, Services::IDepotManager
	{
	public:	value struct CarGarageItems 
		{ property System::UInt32 CarCount; Models::CarBaseModel^ CarModel; System::Type^ CarClass; };

	private:	Services::DriveComplexToken^ drive_complex = nullptr;
	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;
	private:	System::Boolean service_disposed;
	public:
		property System::Guid DriverGuid { public: System::Guid get(System::Void); }
		property System::Boolean IsBuilded 
		{ public: System::Boolean get(System::Void) { return (this->drive_complex != nullptr); } }

		property DriveComplexToken::DriverStateType DriverState
			{ public: DriveComplexToken::DriverStateType get(System::Void); }
	public:
		DepotManager(Services::SqlDatabaseManager^ db_manager) : Manager::ServiceBase(), service_disposed(false)
		{ this->service_sql_manager = db_manager; }

		virtual ~DepotManager(System::Void) { delete this->drive_complex; ServiceBase::~ServiceBase(); }
		!DepotManager(System::Void)
		{ if(!service_disposed && drive_complex != nullptr) { return_car_model(); service_disposed = true; } }

		Services::DriveComplexDbScheme^ get_driver_complexs(System::Guid driver_guid);
		System::Boolean update_drive_state(DriveComplexToken::DriverStateType state);

		Generic::List<System::Guid>^ get_all_drivers(System::Void);
		Generic::List<DepotManager::CarGarageItems>^ get_all_cars(System::Void);

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			virtual System::Boolean add_car_model(TCarClass car_model, UInt16 count) override;

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			virtual System::Boolean rent_car_model(TCarClass car_model, System::Guid driver_guid);

		virtual System::Boolean return_car_model(System::Void) override;
	};
}