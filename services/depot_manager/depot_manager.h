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

	public interface class IDepotManager 
	{
	public:		System::Boolean return_car_model(System::Void);
	public:		generic <class TCarClass> where TCarClass : Models::CarBaseModel
					System::Boolean rent_car_model(Models::CarBaseModel^ car_model);

	public:		Services::DriveComplexDbScheme^ get_driver_complexs(System::Guid driver_guid);
	public:		List<System::Guid>^ get_drivers_guid(System::Void);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class DepotManager sealed : Manager::ServiceBase, Services::IDepotManager
	{
	private:	Services::DriveComplexToken^ drive_complex = nullptr;
	private:	SqlDatabaseManager^ service_sql_manager = nullptr;

	public:
		DepotManager(SqlDatabaseManager^ db_manager) : Manager::ServiceBase()
		{ this->service_sql_manager = db_manager; }
		virtual ~DepotManager(System::Void) { delete this->drive_complex; }

		property DriveComplexToken::DriverStateType DriverState
		{ public: DriveComplexToken::DriverStateType get(System::Void) { return drive_complex->DriverState; } }

		property System::Guid DriverGuid 
		{ public: System::Guid get(System::Void) { return this->drive_complex->ComplexGuid; } }

		virtual Services::DriveComplexDbScheme^ get_driver_complexs(Guid driver_guid) override;
		virtual List<System::Guid>^ get_drivers_guid(System::Void) override;

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			virtual System::Boolean rent_car_model(Models::CarBaseModel^ car_model) override;

		virtual System::Boolean return_car_model(System::Void) override;
	};
}