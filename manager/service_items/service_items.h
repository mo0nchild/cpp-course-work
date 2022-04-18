#pragma once

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections;

	public interface class IServiceBase
	{
	public:
		property System::Boolean ServiceState { System::Boolean get(System::Void) abstract; }
		property System::Guid ServiceGuid { System::Guid get(System::Void) abstract; }
	};

	public ref class ServiceBase abstract : Manager::IServiceBase
	{
	private:	System::Boolean service_state;
				System::Guid service_guid = System::Guid::Empty;

	private: static System::UInt32 service_number = 0;
	public:
		virtual property System::Boolean ServiceState
		{
		public: System::Boolean get(System::Void) override { return this->service_state; }
		protected: System::Void set(System::Boolean value) override { this->service_state = value; }
		};

		virtual property System::Guid ServiceGuid
		{ public: System::Guid get(System::Void) override { return this->service_guid; } }
	public:
		ServiceBase(System::Void) : service_guid(System::Guid::NewGuid()), service_state(true) 
		{ service_number++; }
		virtual ~ServiceBase(System::Void) { }	
	};

	public interface class IServiceProvider
	{
	public: // переделать get_dependencies под IEnumerable (IEnumerator)
		Collections::Generic::List<System::Type^>^ get_dependencies(System::Void);

		property System::DateTime ServiceDate { System::DateTime get(System::Void) abstract; }
		property ServiceBase^ Service { ServiceBase^ get(System::Void) abstract; }
	};

	public ref class ServiceProvider abstract : Manager::IServiceProvider
	{
	private:	Manager::ServiceBase^ service_instance = nullptr;
				Generic::List<System::Type^>^ service_dependencies = nullptr; 

	private:	System::DateTime registration_time;
	public:
		virtual property Manager::ServiceBase^ Service
		{
		private: System::Void set(Manager::ServiceBase^ value) override { this->service_instance = value; }
		public: Manager::ServiceBase^ get(System::Void) override { return this->service_instance; }
		}

		virtual property System::DateTime ServiceDate
		{ public: System::DateTime get(System::Void) override { return this->registration_time; } }

	public:
		ServiceProvider(Manager::ServiceBase^ service, Generic::List<System::Type^>^ dependencies)
			: registration_time(System::DateTime::Now)
		{ this->service_dependencies = dependencies; this->service_instance = service; }

		virtual ~ServiceProvider(System::Void) { delete this->service_dependencies; }
		virtual Generic::List<System::Type^>^ get_dependencies(System::Void) override;
	};
}