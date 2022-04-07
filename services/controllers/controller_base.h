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
		ControllerBaseProvider(ControllerBase^ service, List<Type^>^ dependencies)
			: Manager::ServiceProvider(service, dependencies)
		{

		}
		virtual ~ControllerBaseProvider(System::Void) { }
	};

	public value struct OrderToken sealed
	{
		System::String^ order_comment;
		Models::AccountBaseModel^ order_client;

	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(GarageManager::typeid)]
	public ref class OrderController sealed : ControllerBase
	{
		System::UInt32 orders_count;
		System::Threading::Thread^ order_processing = nullptr;

		List<OrderToken>^ order_collection;
		GarageManager^ service_garage_manager;

	public:
		OrderController(GarageManager^ garage_manager) : ControllerBase(), orders_count(0)
		{
			this->order_collection = gcnew List<OrderToken>();
			this->service_garage_manager = garage_manager;
		}
		virtual ~OrderController(System::Void) { }

		void create_order(OrderToken order_information)
		{
			
		}

		Models::CarBaseModel^ order_process(String^ address, Models::CarModelTypes type)
		{
			
		}
	};

	public ref class ErrorController : ControllerBase 
	{
	public:
		ErrorController(System::Void) { }
		~ErrorController(System::Void) { }


	};
}
