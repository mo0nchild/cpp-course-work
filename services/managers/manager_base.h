#pragma once
#include "../../manager/manager.h"
#include "../controllers/controller_base.h"
#include "../../models/cars_model/cars_model.h"

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
		ManagerBaseProvider(ManagerBase^ serv, List<Type^>^ dep, System::Guid id)
			: Manager::ServiceProvider(serv, dep, id)
		{

		}
		virtual ~ManagerBaseProvider(System::Void) { }
	};



	// переписать и добавить в модели
	

	public ref class GarageManager sealed: ManagerBase
	{
	public:
		GarageManager(System::Void) { }
		virtual ~GarageManager(System::Void) { }

		Models::CarBaseModel^ car_request(String^ address, Models:: type)
		{
			return nullptr;
		}

	};

	public ref class AccountManager : ManagerBase 
	{
	public:
		AccountManager(System::Void) { }
		virtual ~AccountManager(System::Void) { }
	};
}