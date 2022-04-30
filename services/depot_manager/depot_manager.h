#pragma once
#include "../../manager/manager.h"
#include "../../models/cars_model/cars_model.h"
#include "../database_provider/database_provider.h"
#include "depot_manager_token.h"
#include "depot_manager_scheme.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Collections;
	using namespace Manager;

	public interface class IDepotManager 
	{
	public:		System::Boolean return_car_model(System::Void);
	public:	
		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			System::Boolean rent_car_model(TCarClass car_model, System::Guid driver_guid);

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			System::Boolean add_car_model(TCarClass car_model, System::UInt16 count);

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			System::Boolean delete_car_model(TCarClass car_model);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class DepotManager sealed : Manager::ServiceBase, Services::IDepotManager
	{
	public:	value struct CarGarageItems 
	{ System::Guid Guid; Models::CarBaseModel^ CarModel; System::Type^ CarClass; System::UInt32 CarCount; };

	private:	Services::DriveComplexToken^ drive_complex = nullptr;
	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;
	
	private:	System::Boolean service_disposed;
				System::UInt32 garage_collection_size;
	public:
		property System::Guid DriverGuid { public: System::Guid get(System::Void); }
		property Models::CarBaseModel^ CarModel { public: Models::CarBaseModel^ get(System::Void); }
		
		property System::Type^ CarModelType { public: System::Type^ get(System::Void); }
		property System::UInt32 CarTypePrice[Models::CarModelTypes]
		{ public: System::UInt32 get(Models::CarModelTypes value); }

		property System::Boolean IsBuilded 
		{ public: System::Boolean get(System::Void) { return (this->drive_complex != nullptr); } }

		property DriveComplexToken::DriverStateType DriverState
		{ public: DriveComplexToken::DriverStateType get(System::Void); }
	
	private: System::Boolean delete_car_process(Services::CarModelDbScheme^ item);
	public:
		[Manager::ServiceConfigurationAttribute("depot_manager")]
		DepotManager(IServiceBase::ServiceCtorConfiguration^ configuration, Services::SqlDatabaseManager^ db_manager) 
			: Manager::ServiceBase(configuration), service_disposed(false)
		{ 
			if (!configuration->ContainsKey("car_child_type_price") || !configuration->ContainsKey("car_econom_type_price")
				|| !configuration->ContainsKey("car_premium_type_price")) throw gcnew System::Exception("Parameter Error");

			this->garage_collection_size = System::UInt32::Parse((String^)configuration["garage_collection_size"]);
			this->service_sql_manager = db_manager; 
		}
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

		generic <class TCarClass> where TCarClass : Models::CarBaseModel
			virtual System::Boolean delete_car_model(TCarClass car_model) override;
		virtual System::Boolean return_car_model(System::Void) override;

		virtual IServiceBase::ServiceQuery^ service_query_handler(System::TimeSpan work_time) override;
		System::Boolean delete_car_model_by_guid(System::Guid group_id);

	};
}