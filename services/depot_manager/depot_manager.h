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
	
	public ref class GarageCollection 
	{
		// (модель машины, )
		array<DriveComplex>^ car_collection = nullptr;
		System::UInt16 collection_space_used;

	public:
		GarageCollection(System::UInt32 garage_size) : collection_space_used(0)
		{
			this->car_collection = gcnew array<DriveComplex>(garage_size);
		}
		~GarageCollection(System::Void) { delete car_collection; }

		property DriveComplex CarsArray[int]
		{
		public: DriveComplex get(int index) 
			{ 
				if (index < collection_space_used) return this->car_collection[index];
				throw gcnew System::Exception("From GarageCollection: Index out of range");
			}
		}

		property System::UInt16 CarsArraySize 
		{
		public: System::UInt16 get(System::Void) { return this->collection_space_used; }
		}

		GarageCollection^ add_car_model(DriveComplex new_car) 
		{
			if (this->collection_space_used < this->car_collection->Length) 
			{
				car_collection[this->collection_space_used++] = new_car;
			}
			return this;
		}
	};

	public value struct OrderControllerToken sealed
	{
	public:	property System::String^ OrderAddress;
	public:	property Models::CarModelTypes CarType;
	public: property System::Guid OrderTokenGuid;

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
	public:	using OrderPairConnection = System::Tuple<System::Guid, System::Guid>;

		GarageCollection^ car_garage_collection = nullptr;
		SqlDatabaseManager^ database_manager = nullptr;
		OrderPairConnection^ connected_pair = nullptr;

	public:
		DepotManager(SqlDatabaseManager^ db_manager) : Manager::ServiceBase()
		{
			this->car_garage_collection = gcnew GarageCollection(GARAGE_COLLECTION_SIZE);
			this->database_manager = db_manager;
		}
		virtual ~DepotManager(System::Void) { delete car_garage_collection; }

		property List<System::Tuple<System::Guid, System::String^>^>^ DriverRequest
		{
		public: List<Tuple<Guid, String^>^>^ get(System::Void) { return nullptr/*this->request_driver*/; }
		}
		// добавить свойство: выводить свободные машины (без водителя)

		// для клиента
		System::Boolean add_request(Services::OrderControllerToken order_token);
		System::Boolean check_request(System::Guid order_id);
		// для водителя
		System::Void accept_request(System::Guid order_id, System::Guid driver_id);

	};
}