#pragma once
#include "service_collection.h"

using namespace Manager;

generic<class TService> bool ServiceCollection::add_service(ServiceRecord^ service_record)
{
	// проверка на наличие добавляемого сервиса в коллекции
	for each (ServiceRecord^ item in this->services_collection)
	{
		try { TService check = safe_cast<TService>(item->ServiceInstance); return false; }
		catch (System::InvalidCastException^ error) { }
	}
	this->services_collection->Add(service_record);
	return true;
}

System::Type^ ServiceCollection::ServiceType::get(System::String^ index)
{
	System::Type^ service_result = nullptr;
	for each (ServiceRecord ^ item in this->services_collection) 
	{
		if (index == item->ServiceInstance->GetType()->Name || 
			index == item->ServiceInstance->ToString())
		{
			service_result = item->ServiceInstance->GetType();	
		}
	}
	return service_result;
}