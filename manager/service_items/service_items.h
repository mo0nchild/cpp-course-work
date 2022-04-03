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
		property ServiceBase^ Service { ServiceBase^ get() abstract; }

	};

	public ref class ServiceProvider abstract : IServiceProvider
	{
		ServiceBase^ service;
	public:
		virtual property ServiceBase^ Service { ServiceBase^ get() { return this->service; } }

		ServiceProvider(ServiceBase^ service) { this->service = service; }
	};
}