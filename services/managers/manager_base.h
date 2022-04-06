#pragma once
#include "../../manager/manager.h"
#include "../controllers/controller_base.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ManagerBase : Manager::ServiceBase
	{
		
	public:

	};

	public ref class ManagerBaseProvider : Manager::ServiceProvider
	{
	public:
		ManagerBaseProvider(ManagerBase^ serv, List<Type^>^ dep, System::Guid id)
			: Manager::ServiceProvider(serv, dep, id)
		{

		}
		~ManagerBaseProvider(System::Void) { }
	};

	public ref class GarageManager : ManagerBase
	{
	public:
		GarageManager(System::Void) { }
		~GarageManager(System::Void) { }
	};

	public ref class AccountManager : ManagerBase 
	{
	public:
		AccountManager(System::Void) { }
		~AccountManager(System::Void) { }
	};
}