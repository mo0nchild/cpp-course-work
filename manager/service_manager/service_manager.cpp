#pragma once
#include "service_manager.h"

using namespace Manager;

generic <class TService> where TService : IServiceBase ServiceProvider^ ServiceManager::get_service(System::Void)
{
	System::Type^ service_require = TService::typeid;
	Manager::ServiceProvider^ provider = nullptr;

	for each (Manager::ServiceRecord^ srv in this->service_collection->ServiceList)
	{
		if (srv->ServiceInstance->GetType() == service_require)
		{
			array<System::Object^>^ params = gcnew array<System::Object^> { srv->ServiceInstance, srv->ServiceDependencies };

			try { provider = safe_cast<Manager::ServiceProvider^>(Activator::CreateInstance(srv->ServiceProvider, params)); }
			catch (System::MissingMethodException^ error) { Console::WriteLine(error->Message); break; }
		}
	}
	return provider;
}

Generic::List<System::Type^>^ ServiceManager::get_all_services(System::Void)
{
	Generic::List<System::Type^>^ result_collection = gcnew Generic::List<System::Type^>();

	for each (Manager::ServiceRecord ^ item in this->service_collection->ServiceList)
	{ result_collection->Add(item->GetType()); }

	return result_collection;
}