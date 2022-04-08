#pragma once
#include "../../manager/manager.h"
#include "../managers/manager_base.h"

#define ORDER_REQUEST_SECOND 15

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

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

	private value struct OrderControllerToken sealed
	{
	public:	property System::String^ OrderAddress;
	public:	property Models::CarModelTypes CarType;

		  OrderControllerToken(System::String^ address, Models::CarModelTypes type)
		  {
			  this->CarType = type;
			  this->OrderAddress = address;
		  }
	};
	 
	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::GarageManager::typeid)]
	public ref class OrderController sealed : ControllerBase
	{
		System::UInt32 orders_count;
		OrderControllerToken order_toker;
		GarageManager^ service_garage_manager = nullptr;
		
		CancellationTokenSource^ cancel_source = nullptr;
		CancellationToken request_cancel_token;

	public:		delegate System::Void RequestCallback(System::Boolean);
	public:		event RequestCallback^ RequestCallbackEvent;

	private:	System::Boolean order_process(System::Void);
	private:	System::Void order_callback(Task<bool>^ task) { RequestCallbackEvent(task->Result); }

	public:
		OrderController(GarageManager^ garage_manager) : ControllerBase(), orders_count(0)
		{ this->service_garage_manager = garage_manager; }
		virtual ~OrderController(System::Void) { delete cancel_source; }
		
		generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
		System::Void registration_order(String^ request_address, Models::CarModelTypes car_type);
		System::Void cancellation_order(System::Void);
	};

	public ref class ErrorController : ControllerBase 
	{
	public:
		ErrorController(System::Void) { }
		~ErrorController(System::Void) { }
	};
}
