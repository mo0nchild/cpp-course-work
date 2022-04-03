#pragma once
#include "../manager.h"
#include "../service_manager/service_manager.h"

namespace Manager 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ServiceManagerBuilderException : System::Exception 
	{
	public:
		ServiceManagerBuilderException(String^ message): System::Exception(message) { }
	};

	public interface class IServiceManagerBuilder
	{
		generic<class TProvider, class TService> where TService: IServiceBase
			bool service_registration(void);

		ServiceManager^ create_manager(Dictionary<String^, Object^>^ manager_parameter);
	};

	ref class ServiceManagerBuilder sealed : IServiceManagerBuilder
	{
		bool manager_is_created;
		System::UInt16 registration_count;
		ServiceCollection^ collection;

		using ServiceRequire = ServiceAttribute::ServiceRequireAttribute;
		using ServiceRequireTarget = ServiceAttribute::ServiceRequireTargetAttribute;

		generic <class TService> where TService: IServiceBase TService dependency_injection(void);
	public:
		ServiceManagerBuilder(void): manager_is_created(false) { this->collection = gcnew ServiceCollection(); }

		property System::UInt16 ServiceCount
		{
		public: System::UInt16 get(void) { return registration_count; }
		private: void set(System::UInt16 value) { registration_count = value; }
		}

		generic<class TProvider, class TService> where TService: IServiceBase
		virtual bool service_registration(void) override;

		virtual ServiceManager^ create_manager(Dictionary<String^, Object^>^ manager_parameter) override;
	};
}