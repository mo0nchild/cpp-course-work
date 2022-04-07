#pragma once
#include "service_manager.h"

using namespace Manager;

generic <class TService> where TService : IServiceBase ServiceProvider^ ServiceManager::get_service(System::Void)
{
	Type^ service_require = TService::typeid;
	ServiceProvider^ provider = nullptr;

	for each (ServiceRecord^ srv in this->service_collection->ServiceList)
	{
		if (srv->ServiceInstance->GetType() == service_require)
		{
			array<Object^>^ param = gcnew array<Object^> { srv->ServiceInstance, srv->ServiceDependencies };

			try { provider = safe_cast<ServiceProvider^>(Activator::CreateInstance(srv->ServiceProvider, param)); }
			catch (System::MissingMethodException^ error) { break; }
		}
	}
	return provider;
}

System::Collections::Generic::List<System::Type^>^ ServiceManager::get_all_services(System::Void)
{
	auto result_collection = gcnew System::Collections::Generic::List<System::Type^>();
	for each (ServiceRecord ^ item in this->service_collection->ServiceList)
	{
		result_collection->Add(item->GetType());
	}
	return result_collection;
}