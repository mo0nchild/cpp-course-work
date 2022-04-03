#pragma once
#include "../service_items/service_items.h"
#include "../service_collection/service_collection.h"

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	public ref class ServiceManager sealed
	{
		ServiceCollection^ collection;
		Dictionary<String^, Object^>^ parameters;

	public:
		ServiceManager(ServiceCollection^ collection, Dictionary<String^, Object^>^ parameters)
		{
			this->collection = collection;
			this->parameters = parameters;
		}

		generic <class TService> where TService : IServiceBase ServiceProvider^ get_service(void);
	};
}