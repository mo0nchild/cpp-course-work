#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"

namespace Manager 
{
	using namespace System::Reflection;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System;

	public interface class IServiceManager 
	{
	public: generic <class TService> where TService : Manager::IServiceBase
		Manager::ServiceProvider^ get_service(System::Void);

		property System::UInt16 ServiceCount { System::UInt16 get(System::Void) abstract; }
		virtual Generic::List<System::Type^>^ get_all_services(System::Void) abstract;

		virtual Tasks::Task^ start_service_handler(System::TimeSpan tick_timer) abstract;
		virtual System::Boolean stop_service_handler(System::Void) abstract;
	};

	public ref class ServiceManager sealed : Manager::IServiceManager
	{
	public:	delegate IServiceBase::ServiceQuery^ ServiceDelegateHandler(System::TimeSpan);

	private:	Manager::ServiceCollection^ service_collection = nullptr;
		ServiceManager::ServiceDelegateHandler^ services_event_handler = nullptr;

		System::Threading::CancellationTokenSource^ cancel_source = nullptr;
		System::Threading::CancellationToken cancellation_token;
		System::TimeSpan^ service_handling_timer = nullptr;

		System::Void service_handling_process(System::Void);
		System::Boolean service_handling_connection(System::Void);
	public:
		virtual property System::UInt16 ServiceCount
		{ public: System::UInt16 get(System::Void) { return service_collection->ServiceList->Count; } }

		event ServiceManager::ServiceDelegateHandler^ ServiceEventHandler 
		{
		public: System::Void add(ServiceDelegateHandler^ value) { services_event_handler += value; }
		protected: System::Void remove(ServiceDelegateHandler^ value) { services_event_handler -= value; }
		};
	public:
		explicit ServiceManager(Manager::ServiceCollection^ collection)
		{ 
			this->service_collection = collection;
			if (service_handling_connection() != true) throw gcnew System::Exception("Service handling error");
		}
		virtual ~ServiceManager(System::Void) 
		{ delete this->service_collection, this->services_event_handler; }

		virtual Generic::List<System::Type^>^ get_all_services(System::Void) override;

		generic <class TService> where TService : Manager::IServiceBase
			virtual Manager::ServiceProvider^ get_service(System::Void) override;

		virtual Tasks::Task^ start_service_handler(System::TimeSpan tick_timer);
		virtual System::Boolean stop_service_handler(System::Void);
	};
}