#pragma once
#include "../service_items/service_items.h"

namespace Manager 
{
	private ref struct ServiceRecord sealed
	{
		property System::Type^ Provider;
		property ServiceBase^ Service;

		ServiceRecord(System::Type^ provider, ServiceBase^ service)
		{
			this->Provider = provider;
			this->Service = service;
		}
		~ServiceRecord() { delete Provider, Service; }
	};

	public interface class IServiceCollection
	{
		property System::Collections::Generic::List<ServiceRecord^>^ ServiceList
		{
			System::Collections::Generic::List<ServiceRecord^>^ get(System::Void) abstract;
		}
		property System::Type^ ServiceType[System::String^]
		{
			System::Type ^ get(System::String^ index) abstract;
		}
	};

	private ref class ServiceCollection: IServiceCollection
	{
	public:
		using ServiceListType = System::Collections::Generic::List<ServiceRecord^>;

		ServiceCollection(System::Void) { services_collection = gcnew ServiceListType(); }
		~ServiceCollection(System::Void) { delete services_collection; }

		virtual property ServiceListType^ ServiceList
		{
		public: ServiceListType^ get(System::Void) override { return services_collection; }
		}

		virtual property System::Type^ ServiceType[System::String^]
		{
		public: System::Type ^ get(System::String ^ index) override;
		}

		generic<class TService> System::Boolean add_service(ServiceRecord^ record);

	private: ServiceListType^ services_collection;
	};
}