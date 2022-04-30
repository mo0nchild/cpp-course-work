#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"
#include "../service_manager/service_manager.h"
#include "../service_attribute/service_attribute.h"

namespace Manager 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Collections;

	public ref class ServiceManagerBuilderException sealed : System::Exception
	{
	private:	System::Type^ exception_attach_from = nullptr;
	public:
		property System::Type^ AttachFrom
		{ public: System::Type^ get(System::Void) { return this->exception_attach_from; } }

		virtual property System::String^ Message
		{
		public: System::String^ get(System::Void) override
			{ return "From " + exception_attach_from->ToString() + ": " + Exception::Message; }
		}
	public:
		ServiceManagerBuilderException(System::Type^ from, System::String^ message) : System::Exception(message)
		{ this->exception_attach_from = from; }

		virtual ~ServiceManagerBuilderException(System::Void) { delete exception_attach_from; }
	};

	public interface class IServiceManagerBuilder
	{
	public: value struct ServiceCtorConfigurationItem { System::String^ Key;
		IServiceBase::ServiceCtorConfiguration^ Configuration; };
	
	public:	Manager::ServiceManager^ create_manager(System::Void);
	public:	generic<class TProvider, class TService> where TService: Manager::IServiceBase
		System::Boolean service_registration(System::Void);

		System::Boolean service_configuration_load(ServiceCtorConfigurationItem^ configuration_item);
		System::Boolean service_configuration_load(System::String^ configuration_filename);
	};

	public ref class ServiceManagerBuilder sealed : Manager::IServiceManagerBuilder
	{
	public:	using ServiceRequire = ServiceAttribute::ServiceRequireAttribute;
		value struct ServiceConstructor { ConstructorInfo^ Ctor; String^ Configuration; };

		Dictionary<String^, IServiceBase::ServiceCtorConfiguration^>^ configurations = nullptr;
	private:	System::Boolean manager_is_created;
	private:	System::UInt16 registration_count;
	private:	Manager::ServiceCollection^ collection = nullptr;
	public:
		virtual property System::UInt16 ServiceCount
		{
		public: System::UInt16 get(System::Void) override { return registration_count; }
		private: System::Void set(System::UInt16 value) override { registration_count = value; }
		}
	private: generic <class TService> where TService: Manager::IServiceBase
		System::Tuple<TService, List<System::Type^>^>^ dependency_injection(System::Void);

		ServiceManagerBuilder::ServiceConstructor^ get_service_configuration(System::Type^ obj);
		System::Void service_configuration_setup(System::Void);
	public:
		explicit ServiceManagerBuilder(System::Void) : manager_is_created(false), registration_count(0)
		{ this->collection = gcnew ServiceCollection(); this->service_configuration_setup(); }
		virtual ~ServiceManagerBuilder(System::Void) { }

		virtual Manager::ServiceManager^ create_manager(System::Void) override;

		generic<class TProvider, class TService> where TService: Manager::IServiceBase
			virtual System::Boolean service_registration(System::Void) override;

		virtual System::Boolean service_configuration_load(System::String^ configuration_filename);
		virtual System::Boolean service_configuration_load(
			IServiceManagerBuilder::ServiceCtorConfigurationItem^ configuration_item) override;
	};
}