#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"

namespace Manager 
{
	using namespace System::Reflection;
	using namespace System;

	// делегат нужно доделать
	delegate System::Void ServiceDelegateHandler(IServiceBase^ service_info);

	public interface class IServiceManager 
	{
		generic <class TService> where TService : IServiceBase 
			ServiceProvider^ get_service(System::Void);

		property System::UInt16 ServiceCount { System::UInt16 get(System::Void) abstract; }
		System::Collections::Generic::List<System::Type^>^ get_all_services(System::Void);

		event ServiceDelegateHandler^ ServiceEventHandler;
	};

	public ref class ServiceManager sealed : IServiceManager
	{
	private:
		ServiceCollection^ service_collection;
		System::Collections::Generic::Dictionary<String^, Object^>^ parameters;
	
	public:
		virtual event ServiceDelegateHandler^ ServiceEventHandler;

		ServiceManager(ServiceCollection^ collection, Dictionary<String^, Object^>^ parameters)
		{
			this->service_collection = collection;
			this->parameters = parameters;
		}
		~ServiceManager(System::Void) { delete parameters; }

		virtual property System::UInt16 ServiceCount 
		{
		public: System::UInt16 get(System::Void) { return service_collection->ServiceList->Count; }
		}

		virtual System::Collections::Generic::List<System::Type^>^ 
			get_all_services(System::Void) override;

		generic <class TService> where TService : IServiceBase virtual
			ServiceProvider^ get_service(System::Void) override;
	};
}