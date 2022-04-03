#pragma once
#include "service_manager.h"

using namespace Manager;

generic <class TService> where TService : IServiceBase ServiceProvider^ ServiceManager::get_service(void)
{
	Type^ service_require = TService::typeid;
	ServiceProvider^ provider = nullptr;

	for each (ServiceCollection::ServiceRecord ^ srv in collection->ServiceList)
	{
		if (srv->service->GetType() == service_require)
		{
			array<Object^>^ param = gcnew array<Object^>{ srv->service };
			try { provider = safe_cast<ServiceProvider^>(Activator::CreateInstance(srv->provider, param)); }
			catch (System::MissingMethodException^ error) { return nullptr; }
		}
	}
	return provider;
}