#pragma once
#include "../service_items/service_items.h"

namespace Manager 
{
	private ref struct ServiceRecord sealed
	{
		property System::Type^ ServiceProvider;
		property ServiceBase^ ServiceInstance;
		property List<System::Type^>^ ServiceDependencies;
		System::Guid ServiceGuid;

		ServiceRecord(System::Type^ provider, ServiceBase^ service, List<System::Type^>^ dependencies)
			: ServiceGuid(System::Guid::NewGuid())
		{
			this->ServiceDependencies = dependencies;
			this->ServiceProvider = provider;
			this->ServiceInstance = service;
		}
		~ServiceRecord(System::Void) { delete ServiceProvider, ServiceInstance, ServiceDependencies; }
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
		virtual ~ServiceCollection(System::Void) { delete services_collection; }

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