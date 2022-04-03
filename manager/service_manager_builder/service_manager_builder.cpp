#pragma once
#include "service_manager_builder.h"
using namespace Manager;

generic <class TService> where TService: IServiceBase TService ServiceManagerBuilder::dependency_injection(void)
{
	TService service_instance;
	array<Object^>^ service_includes = nullptr;
	array<ServiceRequire^>^ service_requirement = safe_cast<array<ServiceRequire^>^>(
		Attribute::GetCustomAttributes(TService::typeid, ServiceRequire::typeid)
		);

	if (!service_requirement) return service_instance;
	service_includes = gcnew array<Object^>(service_requirement->Length);

	for (int i = 0; i < service_includes->Length; i++)
	{
		for each (auto service_in_collection in this->collection->ServiceList)
		{
			if (service_requirement[i]->Requirement == service_in_collection->service->GetType())
				service_includes[i] = service_in_collection->service;
		}
	}

	try { service_instance = safe_cast<TService>(Activator::CreateInstance(TService::typeid, service_includes)); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); }

	return service_instance;
}

generic<class TProvider, class TService> where TService: IServiceBase
bool ServiceManagerBuilder::service_registration(void)
{
	Type^ provider_interface = TProvider::typeid->GetInterface("IServiceProvider");
	Type^ service_interface = TService::typeid->GetInterface("IServiceBase");

	if (provider_interface != nullptr && service_interface != nullptr)
	{
		TService service = dependency_injection<TService>();
		if (service != nullptr)
		{
			return collection->add_service<TService>(
				gcnew ServiceCollection::ServiceRecord(TProvider::typeid, (ServiceBase^)service)
			);
		}
	}
	return false;
}

ServiceManager^ ServiceManagerBuilder::create_manager(Dictionary<String^, Object^>^ manager_parameter)
{
	if (manager_is_created) throw gcnew ServiceManagerBuilderException("Менеджер уже создан");

	manager_is_created = true;
	return gcnew ServiceManager(collection, manager_parameter);
}