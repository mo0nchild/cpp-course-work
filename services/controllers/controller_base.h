#pragma once
#include "../../manager/manager.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ControllerBase : Manager::ServiceBase
	{
	public:
		ControllerBase(System::Void) { }
		~ControllerBase(System::Void) { }

		virtual System::Void update_data(System::Void) {}
	};

	public ref class ControllerBaseProvider : Manager::ServiceProvider
	{
	public:
		ControllerBaseProvider(ManagerBase^ serv, List<Type^>^ dep, System::Guid id)
			: Manager::ServiceProvider(serv, dep, id)
		{

		}
		~ControllerBaseProvider(System::Void) { }
	};

	private ref struct OrderToken sealed
	{
		
	};

	public ref class OrderController : ControllerBase
	{
		List<OrderToken^>^ order_collection;
	public:
		OrderController(System::Void) { }
		~OrderController(System::Void) { }


	};

	public ref class ErrorController : ControllerBase 
	{
	public:
		ErrorController(System::Void) { }
		~ErrorController(System::Void) { }


	};
}
