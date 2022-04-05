#pragma once

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	public interface class IServiceBase
	{

	};

	public ref class ServiceBase abstract : IServiceBase
	{
	public:
		ServiceBase(void) { }
	};

	public interface class IServiceProvider
	{
		System::Collections::Generic::List<System::Type^> get_dependencies(System::Void);
		property ServiceBase^ Service { ServiceBase^ get(System::Void) abstract; }
	};

	public ref class ServiceProvider abstract : IServiceProvider
	{
		ServiceBase^ service;
	public:
		ServiceProvider(ServiceBase^ service) { this->service = service; }
		~ServiceProvider(System::Void) { }

		virtual property ServiceBase^ Service 
		{ 
		public: ServiceBase^ get(System::Void) override { return this->service; } 
		}
	
		virtual List<System::Type^> get_dependencies(System::Void) override
		{

		}
	};
}