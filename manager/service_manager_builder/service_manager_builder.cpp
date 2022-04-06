#pragma once
#include "service_manager_builder.h"

using namespace Manager;

generic <class TService> where TService: IServiceBase 
Tuple<TService, List<System::Type^>^>^ ServiceManagerBuilder::dependency_injection(System::Void)
{
	array<ServiceRequire^>^ service_requirement = safe_cast<array<ServiceRequire^>^>(
		Attribute::GetCustomAttributes(TService::typeid, ServiceRequire::typeid));

	System::UInt16 dependencies_collected(0);
	List<System::Type^>^ service_dependencies = gcnew List<System::Type^>();
	array<Object^>^ service_includes = nullptr;
	
	if (service_requirement) 
	{
		service_includes = gcnew array<Object^>(service_requirement->Length);
		for (int i = 0; i < service_includes->Length; i++)
		{
			for each (auto service_in_collection in this->collection->ServiceList)
			{
				if (service_requirement[i]->Requirement == service_in_collection->ServiceInstance->GetType()) 
					service_includes[dependencies_collected++] = service_in_collection->ServiceInstance;
			}
			service_dependencies->Add(service_requirement[i]->Requirement);
		}
	}

	Tuple<TService, List<System::Type^>^>^ service_instance = nullptr;
	// если не удалось найти некоторые зависимости в контейнере
	if (dependencies_collected != service_requirement->Length) 
	{
		Console::WriteLine("dependencies_collected != service_requirement->Length");
		return service_instance;
	}
	try 
	{
		TService service = safe_cast<TService>(Activator::CreateInstance(TService::typeid, service_includes));
		service_instance = Tuple::Create(service, service_dependencies);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message + "\nFrom \"ServiceManagerBuilder\""); }

	return service_instance;
}

generic<class TProvider, class TService> where TService: IServiceBase
bool ServiceManagerBuilder::service_registration(void)
{
	Type^ provider_interface = TProvider::typeid->GetInterface("IServiceProvider");
	Type^ service_interface = TService::typeid->GetInterface("IServiceBase");

	if (provider_interface != nullptr && service_interface != nullptr)
	{
		Tuple<TService, List<System::Type^>^>^ service = dependency_injection<TService>();
		if (service != nullptr)
		{
			return this->collection->add_service<TService>(
				gcnew ServiceRecord(TProvider::typeid, (ServiceBase^)(service->Item1), service->Item2)
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