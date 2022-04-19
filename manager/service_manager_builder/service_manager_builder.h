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
		generic<class TProvider, class TService> where TService: Manager::IServiceBase
			System::Boolean service_registration(System::Void);

		Manager::ServiceManager^ create_manager(Generic::Dictionary<System::String^, 
			System::Object^>^ manager_parameter);
	};

	public ref class ServiceManagerBuilder sealed : Manager::IServiceManagerBuilder
	{
	public:	using ServiceRequire = ServiceAttribute::ServiceRequireAttribute;

	private:	System::Boolean manager_is_created;
	private:	System::UInt16 registration_count;
	private:	Manager::ServiceCollection^ collection = nullptr;
	public:
		virtual property System::UInt16 ServiceCount
		{
		public: System::UInt16 get(void) override { return registration_count; }
		private: void set(System::UInt16 value) override { registration_count = value; }
		}

	private: generic <class TService> where TService: Manager::IServiceBase
		System::Tuple<TService, List<System::Type^>^>^ dependency_injection(System::Void);

	public:
		ServiceManagerBuilder(System::Void): manager_is_created(false), registration_count(0)
		{ this->collection = gcnew ServiceCollection(); }

		virtual ~ServiceManagerBuilder(System::Void) { }

		virtual Manager::ServiceManager^ create_manager(Generic::Dictionary<System::String^,
			System::Object^>^ manager_parameter) override;

		generic<class TProvider, class TService> where TService: Manager::IServiceBase
			virtual System::Boolean service_registration(System::Void) override;
	};
}