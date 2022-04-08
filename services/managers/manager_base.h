#pragma once
#include "../../manager/manager.h"
#include "../controllers/controller_base.h"
#include "../../models/cars_model/cars_model.h"

#define GARAGE_COLLECTION_SIZE 100

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ManagerBase : Manager::ServiceBase
	{
	public:
		ManagerBase(System::Void) : Manager::ServiceBase() { }
		virtual ~ManagerBase(System::Void) { }
	};

	public ref class ManagerBaseProvider : Manager::ServiceProvider
	{
	public:
		ManagerBaseProvider(ManagerBase^ service, List<Type^>^ dependencies)
			: Manager::ServiceProvider(service, dependencies)
		{

		}
		virtual ~ManagerBaseProvider(System::Void) { }
	};

	public enum class DriverStateType { Busy, Ready, Idle };

	public value struct DriveComplex 
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

	public ref class GarageManager sealed: ManagerBase
	{
		GarageCollection^ car_garage_collection;

	public:
		GarageManager(System::Void) 
		{
			this->car_garage_collection = gcnew GarageCollection(GARAGE_COLLECTION_SIZE); 
		}
		virtual ~GarageManager(System::Void) { delete car_garage_collection; }

		// свойство: выводить свободные машины (без водителя)

		
		System::Boolean car_request(Models::CarModelTypes car_type) 
		{
			return false;
		}

		

	};



	public ref class AccountManager : ManagerBase 
	{
	public:
		AccountManager(System::Void) { }
		virtual ~AccountManager(System::Void) { }
	};
}