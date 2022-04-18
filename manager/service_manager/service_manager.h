#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"

namespace Manager 
{
	using namespace System::Collections;
	using namespace System::Reflection;
	using namespace System;

	public interface class IServiceManager 
	{
	public: generic <class TService> where TService : Manager::IServiceBase
		Manager::ServiceProvider^ get_service(System::Void);

		property System::UInt16 ServiceCount { System::UInt16 get(System::Void) abstract; }
		Collections::Generic::List<System::Type^>^ get_all_services(System::Void);
	};

	public ref class ServiceManager sealed : Manager::IServiceManager
	{
	public:		delegate System::Void ServiceDelegateHandler(Manager::IServiceBase^ service_info);

	private:	Manager::ServiceCollection^ service_collection = nullptr;
	private:	Generic::Dictionary<System::String^, System::Object^>^ parameters = nullptr;

		ServiceManager::ServiceDelegateHandler^ services_event_handler = nullptr;
	public:
		virtual property System::UInt16 ServiceCount
		{ public: System::UInt16 get(System::Void) { return service_collection->ServiceList->Count; } }

		event ServiceManager::ServiceDelegateHandler^ ServiceEventHandler 
		{
		protected: System::Void add(ServiceDelegateHandler^ value) { services_event_handler += value; }
		protected: System::Void remove(ServiceDelegateHandler^ value) { services_event_handler -= value; }
		};
	public:
		ServiceManager(Manager::ServiceCollection^ collection, Generic::Dictionary<System::String^, 
			System::Object^>^ parameters) 
		{ this->service_collection = collection; this->parameters = parameters;}
		virtual ~ServiceManager(System::Void) 
		{ delete this->service_collection, this->services_event_handler, parameters; }

		virtual Generic::List<System::Type^>^ get_all_services(System::Void) override;

		generic <class TService> where TService : Manager::IServiceBase
			virtual Manager::ServiceProvider^ get_service(System::Void) override;
	};
}