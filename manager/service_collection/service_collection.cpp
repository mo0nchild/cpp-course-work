#pragma once
#include "service_collection.h"

using namespace Manager;

generic<class TService> bool ServiceCollection::add_service(ServiceRecord^ record)
{
	// �������� �� ������� ������������ ������� � ���������
	for each (ServiceRecord ^ item in list)
	{
		try
		{
			TService check = safe_cast<TService>(item->service);
			return false;
		}
		catch (InvalidCastException^ error) {}
	}
	list->Add(record);
	return true;
}