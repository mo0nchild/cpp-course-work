#pragma once
#include "service_manager_builder.h"

using namespace Manager;
using namespace ServiceAttribute;

ServiceManagerBuilder::ServiceConstructor^ ServiceManagerBuilder::get_service_configuration(System::Type^ obj)
{
	ServiceManagerBuilder::ServiceConstructor^ selected_configuration = nullptr;
	array<ConstructorInfo^>^ ctor_list = obj->GetConstructors();
	
	for(System::UInt32 index = 0; index < ctor_list->Length; index++)
	{
		Reflection::ConstructorInfo^ selected_ctor = ctor_list[index];
		ServiceConfigurationAttribute^ ctor_attribute = nullptr;

		try { ctor_attribute = safe_cast<ServiceConfigurationAttribute^>(
			Attribute::GetCustomAttribute(selected_ctor, ServiceConfigurationAttribute::typeid)); }
		catch (System::Exception^ error) { Console::WriteLine(error->Message); continue; }
		
		if (ctor_attribute != nullptr) 
		{
			selected_configuration = gcnew ServiceManagerBuilder::ServiceConstructor();
			selected_configuration->Configuration = ctor_attribute->Configuration;
			selected_configuration->Ctor = selected_ctor;	break;
		}
	}
	return selected_configuration;
}

generic <class TService> where TService: IServiceBase 
	System::Tuple<TService, List<System::Type^>^>^ ServiceManagerBuilder::dependency_injection(System::Void)
{
	array<ServiceRequire^>^ service_requirement = safe_cast<array<ServiceRequire^>^>(
		Attribute::GetCustomAttributes(TService::typeid, ServiceRequire::typeid));
	
	ServiceConstructor^ service_ctor = this->get_service_configuration(TService::typeid);
	if (service_ctor == nullptr) { return nullptr; }
	array<ParameterInfo^>^ ctor_parameter = service_ctor->Ctor->GetParameters();

	if (ctor_parameter->Length <= 0 || ctor_parameter[0]->ParameterType != IServiceBase::ServiceCtorConfiguration::typeid 
		|| !this->configurations->ContainsKey(service_ctor->Configuration)) 
	{ Console::WriteLine(TService::typeid->FullName + "Parameter Error"); return nullptr; }

	List<System::Type^>^ service_dependencies = gcnew List<System::Type^>(); // для сервис провайдера
	array<Object^>^ service_includes = gcnew array<Object^>(service_requirement->Length + 1); // для создания сервиса (в конструктор)
	
	service_includes[0] = this->configurations[service_ctor->Configuration];
	System::UInt16 dependencies_collected(0);
	
	if (service_requirement != nullptr && service_requirement->Length > 0)
	{
		for (System::UInt16 index = 0; index < service_requirement->Length; index++)
		{
			for each (auto service_in_collection in this->collection->ServiceList)
			{
				if (service_requirement[index]->Requirement == service_in_collection->ServiceInstance->GetType())
				{ service_includes[dependencies_collected++ + 1] = service_in_collection->ServiceInstance; }
			}
			service_dependencies->Add(service_requirement[index]->Requirement);
		}
	}
	Tuple<TService, List<System::Type^>^>^ service_instance = nullptr;
	// если не удалось найти некоторые зависимости в контейнере
	if (dependencies_collected != service_requirement->Length) 
	{
		Console::WriteLine("dependencies_collected != service_requirement->Length");
		return service_instance;
	}
	try {
		TService service = safe_cast<TService>(service_ctor->Ctor->Invoke(service_includes));
		service_instance = Tuple::Create(service, service_dependencies);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message + "\nFrom \"ServiceManagerBuilder\""); }

	return service_instance;
}

generic<class TProvider, class TService> where TService: Manager::IServiceBase
	System::Boolean ServiceManagerBuilder::service_registration(System::Void)
{
	System::Type^ provider_interface = TProvider::typeid->GetInterface("IServiceProvider");
	System::Type^ service_interface = TService::typeid->GetInterface("IServiceBase");

	if (provider_interface != nullptr && service_interface != nullptr)
	{
		System::Tuple<TService, Generic::List<System::Type^>^>^ service_instance = nullptr;
		try { service_instance = dependency_injection<TService>(); }
		catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

		if (service_instance != nullptr)
		{
			return this->collection->add_service<TService>(gcnew Manager::ServiceRecord(TProvider::typeid, 
				(Manager::ServiceBase^)(service_instance->Item1), service_instance->Item2));
		}
	}
	return false;
}

System::Boolean ServiceManagerBuilder::service_configuration_load(
	IServiceManagerBuilder::ServiceCtorConfigurationItem^ configuration_item)
{
	if (configuration_item == nullptr || configuration_item->Configuration == nullptr) return false;
	if (this->configurations->ContainsKey(configuration_item->Key)) 
	{
		for each (Generic::KeyValuePair<String^, Object^> item in configuration_item->Configuration)
		{
			try { this->configurations[configuration_item->Key]->Add(item.Key, item.Value); }
			catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }
		}
	}
	else { this->configurations->Add(configuration_item->Key, configuration_item->Configuration); }
	return true;
}

System::Boolean ServiceManagerBuilder::service_configuration_load(System::String^ configuration_filename)
{
	Xml::XmlDocument^ parameters_document = gcnew Xml::XmlDocument();
	parameters_document->Load(configuration_filename);
	
	Xml::XmlElement^ doc_root = parameters_document->DocumentElement;
	if (doc_root == nullptr) return false;

	for each (Xml::XmlElement^ doc_element in doc_root) 
	{
		Xml::XmlNode^ node_attr = doc_element->Attributes->GetNamedItem("service_name");
		if (node_attr == nullptr) continue;

		auto configuration_item = gcnew IServiceManagerBuilder::ServiceCtorConfigurationItem();
		configuration_item->Key = node_attr->Value;
		configuration_item->Configuration = gcnew IServiceBase::ServiceCtorConfiguration();

		for each (Xml::XmlNode ^ childnode in doc_element->ChildNodes) 
		{ configuration_item->Configuration->Add(childnode->Name, childnode->InnerText); }
		this->service_configuration_load(configuration_item);
	}
	return true;
}

System::Void ServiceManagerBuilder::service_configuration_setup(System::Void)
{
	this->configurations = gcnew Dictionary<String^, IServiceBase::ServiceCtorConfiguration^>();
	this->configurations->Add("none", nullptr);
}

Manager::ServiceManager^ ServiceManagerBuilder::create_manager(System::Void)
{
	if (manager_is_created != false)
	{ throw gcnew ServiceManagerBuilderException(ServiceManagerBuilder::typeid, "Менеджер уже создан"); }
	
	manager_is_created = !manager_is_created;
	return gcnew ServiceManager(this->collection);
}