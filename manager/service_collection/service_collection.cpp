#pragma once
#include "service_collection.h"

using namespace Manager;

generic<class TService> bool ServiceCollection::add_service(ServiceRecord^ service_record)
{
	// �������� �� ������� ������������ ������� � ���������
	for each (ServiceRecord^ item in this->services_collection)
	{
		try { TService check = safe_cast<TService>(item->Service); return false; }
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
		if (item->Service->GetType()->Name == index) service_result = item->Service->GetType();
	}
	return service_result;
}