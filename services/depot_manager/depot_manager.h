#pragma once
#include "../../manager/manager.h"
#include "../../models/cars_model/cars_model.h"
#include "../database_provider/database_provider.h"
#include "../order_controller/order_controller_token.h"

#define GARAGE_COLLECTION_SIZE 100

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public enum class DriverStateType : System::UInt16 { Busy, Ready, Idle };

	public value struct DriveComplex sealed
	{
		property Models::CarBaseModel^ CarModel;
		property Models::AccountDriverModel^ DriverModel;

		property System::Guid ComplexGuid;
		property DriverStateType DriverState;
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class DepotManager sealed : Manager::ServiceBase
	{
		// (id клиента, id водителя)
	/*public:		using OrderPairConnection = System::Tuple<System::Guid, System::Guid>;
	public:		enum class RequestType : System::UInt16 { Process, Delete };*/

	private:
		SqlDatabaseManager^ database_manager = nullptr;
		/**/

	public:
		DepotManager(SqlDatabaseManager^ db_manager) : Manager::ServiceBase()
		{ this->database_manager = db_manager; }
		virtual ~DepotManager(System::Void) {  }

		/*property List<System::Tuple<System::Guid, System::String^>^>^ DriverRequest
		{
		public: List<System::Tuple<System::Guid, System::String^>^>^ get(System::Void);
		}*/
		// добавить свойство: выводить свободные машины (без водителя)


		// убрать эти методы в oder_controller
		/*System::Boolean add_request(Services::OrderControllerToken order_token);
		System::Boolean check_request(System::Guid order_id, RequestType request_type);

		System::Boolean accept_request(System::Guid order_id, System::Guid driver_id);*/

	};
}