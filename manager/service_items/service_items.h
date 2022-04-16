#pragma once

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	public interface class IServiceBase
	{
		property System::Boolean ServiceState { System::Boolean get(System::Void) abstract; }
		property System::Guid ServiceGuid { System::Guid get(System::Void) abstract; }
	};

	public ref class ServiceBase abstract : IServiceBase
	{
		System::Boolean service_state;
		System::Guid service_guid;
		static System::UInt32 service_number = 0;

	public:
		ServiceBase(System::Void) : service_guid(Guid::NewGuid()), service_state(true) 
		{ service_number++; }
		virtual ~ServiceBase(System::Void) { }

		virtual property System::Boolean ServiceState 
		{
		public: System::Boolean get(System::Void) override { return this->service_state; }
		protected: System::Void set(System::Boolean value) override { this->service_state = value; }
		};

		virtual property System::Guid ServiceGuid 
		{
		public: System::Guid get(System::Void) override { return this->service_guid; }
		}
	};

	public interface class IServiceProvider
	{
		// переделать get_dependencies под IEnumerable (IEnumerator)
		System::Collections::Generic::List<System::Type^>^ get_dependencies(System::Void);

		property System::DateTime ServiceGuid { System::DateTime get(System::Void) abstract; }
		property ServiceBase^ Service { ServiceBase^ get(System::Void) abstract; }
	};

	public ref class ServiceProvider abstract : IServiceProvider
	{
		ServiceBase^ service_instance = nullptr;
		DateTime registration_time;

		System::Collections::Generic::List<System::Type^>^ service_dependencies;
		
	public:
		ServiceProvider(ServiceBase^ service, List<System::Type^>^ dependencies)
			: registration_time(DateTime::Now)
		{
			this->service_dependencies = dependencies;
			this->service_instance = service;
		}
		virtual ~ServiceProvider(System::Void) { delete service_dependencies; }

		virtual property ServiceBase^ Service 
		{ 
		public: ServiceBase^ get(System::Void) override { return this->service_instance; }
		private: System::Void set(ServiceBase^ value) override { this->service_instance = value; }
		}
	
		virtual property System::DateTime ServiceGuid
		{
		public: System::DateTime get(System::Void) override { return this->registration_time; }
		}

		virtual List<System::Type^>^ get_dependencies(System::Void) override;
	};
}