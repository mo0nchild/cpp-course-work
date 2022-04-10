#pragma once
#include "../../manager/manager.h"
#include "../../models/cars_model/cars_model.h"
#include "../database_provider/database_provider.h"

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

	public value struct OrderControllerToken sealed
	{
	public:		property System::String^ OrderAddress;
	public:		property Models::CarModelTypes CarType;
	public:		property System::Guid OrderTokenGuid;

		  OrderControllerToken(System::String^ address, Models::CarModelTypes type)
		  {
			  this->OrderTokenGuid = System::Guid::NewGuid();
			  this->OrderAddress = address;
			  this->CarType = type;
		  }
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class DepotManager sealed : Manager::ServiceBase
	{
		// (id клиента, id водителя)
	public:		using OrderPairConnection = System::Tuple<System::Guid, System::Guid>;
	public:		enum class RequestType : System::UInt16 { Process, Delete };

	private:
		SqlDatabaseManager^ database_manager = nullptr;
		OrderPairConnection^ connected_pair = nullptr;

	public:
		DepotManager(SqlDatabaseManager^ db_manager) : Manager::ServiceBase()
		{ this->database_manager = db_manager; }
		virtual ~DepotManager(System::Void) { delete connected_pair; }

		property List<System::Tuple<System::Guid, System::String^>^>^ DriverRequest
		{
		public: List<Tuple<Guid, String^>^>^ get(System::Void) { return nullptr/*this->request_driver*/; }
		}
		// добавить свойство: выводить свободные машины (без водителя)

		System::Boolean add_request(Services::OrderControllerToken order_token);
		System::Boolean check_request(System::Guid order_id, RequestType request_type);

		System::Boolean accept_request(System::Guid order_id, System::Guid driver_id);

	};
}