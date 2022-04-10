#pragma once
#include "../../manager/manager.h"
#include "../depot_manager/depot_manager.h"
#include "../../models/cars_model/cars_model.h"

#define ORDER_REQUEST_SECOND 15

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::DepotManager::typeid)]
	public ref class OrderController sealed : Manager::ServiceBase
	{
		Services::OrderControllerToken order_toker;
		DepotManager^ service_depot_manager = nullptr;
		
		System::Threading::CancellationTokenSource^ cancel_source = nullptr;
		System::Threading::CancellationToken request_cancel_token;

	public:		delegate System::Void RequestCallback(System::Boolean);
	public:		event RequestCallback^ RequestCallbackEvent;
		  
	private:	System::Boolean order_process(System::Void);
	private:	System::Void order_callback(Task<bool>^ task) { RequestCallbackEvent(task->Result); }

	public:
		OrderController(DepotManager^ depot_manager) : Manager::ServiceBase()
		{ this->service_depot_manager = depot_manager; }
		virtual ~OrderController(System::Void) { delete cancel_source; }
		
		generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
		System::Void registration_order(String^ request_address, Models::CarModelTypes car_type);
		System::Void cancellation_order(System::Void);
	};

	public ref class ErrorController : Manager::ServiceBase
	{
	public:
		ErrorController(System::Void) : Manager::ServiceBase() { }
		virtual ~ErrorController(System::Void) { }
	};
}
