#pragma once
#include "../manager.h"

namespace Manager 
{

	ref class ServiceCollection
	{
	public:
		ref struct ServiceRecord
		{
			Type^ provider;
			ServiceBase^ service;

			ServiceRecord(Type^ provider, ServiceBase^ service)
			{
				this->provider = provider;
				this->service = service;
			}
		};
		using ServiceListType = List<ServiceRecord^>;

		ServiceCollection(void)
		{
			list = gcnew ServiceListType();
		}

		property ServiceListType^ ServiceList
		{
			ServiceListType^ get(void) { return list; }
		}

		generic<class TService> bool add_service(ServiceRecord^ record);
	private:
		ServiceListType^ list;
	};
}