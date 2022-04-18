#pragma once
#include "../service_items/service_items.h"

namespace Manager 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Collections;

	private ref struct ServiceRecord sealed
	{
	public:		property System::Type^ ServiceProvider;
	public:		property Generic::List<System::Type^> ^ ServiceDependencies;
				property ServiceBase^ ServiceInstance;
	public:
		ServiceRecord(System::Type^ provider, ServiceBase^ service, List<System::Type^>^ dependencies)
		{
			this->ServiceDependencies = dependencies;	this->ServiceProvider = provider;
			this->ServiceInstance = service;
		}
		~ServiceRecord(System::Void) { delete ServiceProvider, ServiceInstance, ServiceDependencies; }
	};

	public interface class IServiceCollection
	{
	public: property Collections::Generic::List<Manager::ServiceRecord^>^ ServiceList
		{ Collections::Generic::List<ServiceRecord^>^ get(System::Void) abstract; }

	public: property System::Type^ ServiceType[System::String^]
		{ System::Type^ get(System::String^ index) abstract; }
	};

	private ref class ServiceCollection: Manager::IServiceCollection
	{
	public: using ServiceListType = Collections::Generic::List<Manager::ServiceRecord^>;
	private: ServiceListType^ services_collection = nullptr;

	public:	virtual property Manager::ServiceCollection::ServiceListType^ ServiceList
		{ public: ServiceListType^ get(System::Void) override { return services_collection; } }

	public:	virtual property System::Type^ ServiceType[System::String^]
		{ public: System::Type ^ get(System::String ^ index) override; }

	public:
		ServiceCollection(System::Void) { services_collection = gcnew ServiceListType(); }
		virtual ~ServiceCollection(System::Void) { delete services_collection; }

		generic <class TService> where TService : Manager::IServiceBase
			System::Boolean add_service(Manager::ServiceRecord^ service_record);
	};
}