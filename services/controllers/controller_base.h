#pragma once
#include "../../manager/manager.h"
#include "../managers/manager_base.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ControllerBase : Manager::ServiceBase
	{
	public:
		ControllerBase(System::Void): Manager::ServiceBase() { }
		virtual ~ControllerBase(System::Void) { }

		virtual System::Void update_data(System::Void) { }
	};

	public ref class ControllerBaseProvider : Manager::ServiceProvider
	{
	public:
		ControllerBaseProvider(ControllerBase^ serv, List<Type^>^ dep, System::Guid id)
			: Manager::ServiceProvider(serv, dep, id)
		{

		}
		virtual ~ControllerBaseProvider(System::Void) { }
	};

	private ref struct OrderToken sealed
	{
		
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(GarageManager::typeid)]
	public ref class OrderController sealed : ControllerBase
	{
		System::UInt32 orders_count;

		List<OrderToken^>^ order_collection;
		GarageManager^ service_garage_manager;

	public:
		OrderController(GarageManager^ garage_manager) : ControllerBase(), orders_count(0)
		{
			this->service_garage_manager = garage_manager;
		}
		virtual ~OrderController(System::Void) { }


	};

	public ref class ErrorController : ControllerBase 
	{
	public:
		ErrorController(System::Void) { }
		~ErrorController(System::Void) { }


	};
}
