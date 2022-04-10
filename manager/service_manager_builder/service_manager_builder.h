#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"
#include "../service_manager/service_manager.h"
#include "../service_attribute/service_attribute.h"

namespace Manager 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ServiceManagerBuilderException : System::Exception 
	{
	public: ServiceManagerBuilderException(String^ message): System::Exception(message) { }
	};

	public interface class IServiceManagerBuilder
	{
		generic<class TProvider, class TService> where TService: IServiceBase
			bool service_registration(void);

		ServiceManager^ create_manager(Dictionary<String^, Object^>^ manager_parameter);
	};

	ref class ServiceManagerBuilder sealed : IServiceManagerBuilder
	{
		System::Boolean manager_is_created;
		System::UInt16 registration_count;
		ServiceCollection^ collection;

	public:	using ServiceRequire = ServiceAttribute::ServiceRequireAttribute;
	private: generic <class TService> where TService: IServiceBase 
			Tuple<TService, List<System::Type^>^>^ dependency_injection(System::Void);

	public:
		ServiceManagerBuilder(System::Void): manager_is_created(false), registration_count(0)
		{ 
			this->collection = gcnew ServiceCollection(); 
		}
		~ServiceManagerBuilder(System::Void) { }

		virtual property System::UInt16 ServiceCount
		{
		public: System::UInt16 get(void) override { return registration_count; }
		private: void set(System::UInt16 value) override { registration_count = value; }
		}

		virtual ServiceManager^ create_manager(Dictionary<String^, Object^>^ manager_parameter);

		generic<class TProvider, class TService> where TService: IServiceBase
			virtual bool service_registration(void) override;
	};
}