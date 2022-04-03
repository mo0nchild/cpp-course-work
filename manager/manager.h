#pragma once
#include "service_collection/service_collection.h"
#include "service_manager/service_manager.h"
#include "service_manager_builder/service_manager_builder.h"

namespace Manager
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	public interface class IServiceBase
	{

	};

	ref class ServiceManagerBuilder;
	ref class ServiceManager;
	ref class ServiceCollection;
	ref struct ServiceCollection::ServiceRecord;
	ref class ServiceBase;
	ref class ServiceProvider;

	namespace ServiceAttribute 
	{
		[System::AttributeUsage(System::AttributeTargets::Class)]
		ref class ServiceRequireAttribute sealed : System::Attribute
		{
			Type^ requirement;
		public:

			property Type^ Requirement
			{
			public: Type^ get(void) { return requirement; }
			private: void set(Type^ value) { requirement = value; }
			};

			ServiceRequireAttribute(Type^ list) { this->Requirement = list; }
		};

		[System::AttributeUsage(System::AttributeTargets::Constructor)]
		ref class ServiceRequireTargetAttribute sealed : System::Attribute { };
	}

	

	public ref class ServiceBase abstract : IServiceBase
	{
	public:
		ServiceBase(void) 
		{ }
	};


	public interface class IServiceProvider
	{
		property ServiceBase^ Service { ServiceBase^ get() abstract; }

	};

	public ref class ServiceProvider abstract : IServiceProvider
	{
		ServiceBase^ service;
	public:
		virtual property ServiceBase^ Service { ServiceBase^ get() { return this->service; } }

		ServiceProvider(ServiceBase^ service) { this->service = service; }
	};

	ref class TaxiBooking
	{
	public:
		TaxiBooking(void) { }
		static ServiceManagerBuilder^ create_builder(void) { return gcnew ServiceManagerBuilder(); }
	};
}