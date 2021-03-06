#pragma once

#ifndef SERVICES_INCLUDE_STUFF
#define SERVICES_INCLUDE_STUFF

#include "database_provider/database_provider.h"
#include "depot_manager/depot_manager.h"
#include "order_controller/order_controller.h"
#include "account_manager/account_manager.h"
#include "bank_controller/bank_controller.h"

namespace Services 
{
	public ref class MyServicesProvider sealed : Manager::ServiceProvider
	{
	public:
		explicit MyServicesProvider(Manager::ServiceBase^ service, List<Type^>^ dependencies)
			: Manager::ServiceProvider(service, dependencies) { }
		virtual ~MyServicesProvider(System::Void) { }
	};
}

#endif // !SERVICES_INCLUDE_STUFF