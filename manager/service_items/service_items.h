#pragma once

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	public interface class IServiceBase
	{
		property System::Boolean ServiceState { System::Boolean get(System::Void) abstract; }
	};

	public ref class ServiceBase abstract : IServiceBase
	{
		System::Boolean service_state;
	public:
		ServiceBase(System::Void) : service_state(true) { }
		~ServiceBase(System::Void) { }

		virtual property System::Boolean ServiceState 
		{
		public: System::Boolean get(System::Void) override { return service_state; }
		};
	};

	public interface class IServiceProvider
	{
		// переделать get_dependencies под IEnumerable (IEnumerator)
		System::Collections::Generic::List<System::Type^>^ get_dependencies(System::Void);

		property ServiceBase^ Service { ServiceBase^ get(System::Void) abstract; }
		property System::Guid^ ServiceGuid { System::Guid^ get(System::Void) abstract; }
	};

	public ref class ServiceProvider abstract : IServiceProvider
	{
		ServiceBase^ service_instance = nullptr;
		System::Guid service_guid;

		System::Collections::Generic::List<System::Type^>^ service_dependencies;
		
	public:
		ServiceProvider(ServiceBase^ service, List<System::Type^>^ dependencies, System::Guid id)
			: service_guid(id)
		{
			this->service_dependencies = dependencies;
			this->service_instance = service;
		}
		~ServiceProvider(System::Void) { delete service_dependencies; }

		virtual property ServiceBase^ Service 
		{ 
		public: ServiceBase^ get(System::Void) override { return this->service_instance; }
		private: System::Void set(ServiceBase^ value) override { this->service_instance = value; }
		}
	
		virtual property System::Guid^ ServiceGuid 
		{
		public: System::Guid^ get(System::Void) override { return this->service_guid; }
		}

		virtual List<System::Type^>^ get_dependencies(System::Void) override;
	};
}