#pragma once
#include "../manager.h"

namespace Manager 
{
	using namespace System;
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