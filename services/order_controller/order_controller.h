#pragma once
#include "../../manager/manager.h"
#include "../depot_manager/depot_manager.h"
#include "../../models/cars_model/cars_model.h"
#include "order_controller_token.h"

#define ORDER_REQUEST_SECOND 15

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class OrderController sealed : Manager::ServiceBase
	{
	public:		using OrderPairConnection = System::Tuple<System::Guid, System::Guid>;
	private:
		Services::OrderControllerToken order_token;
		Services::SqlDatabaseManager^ service_sql_manager = nullptr;
		OrderPairConnection^ connected_pair = nullptr;
		
		System::Threading::CancellationTokenSource^ cancel_source = nullptr;
		System::Threading::CancellationToken request_cancel_token;

	public:		delegate System::Void RequestCallback(System::Boolean);
	public:		event RequestCallback^ RequestCallbackEvent;
		  
	private:	System::Boolean order_process(System::Void);
	private:	System::Void order_callback(Task<bool>^ task) { RequestCallbackEvent(task->Result); }
	private:	System::Boolean add_request(System::Void);

	public:
		OrderController(Services::SqlDatabaseManager^ sql_manager) : Manager::ServiceBase()
		{ this->service_sql_manager = sql_manager; }
		virtual ~OrderController(System::Void) { delete cancel_source; }
		
		// переделать эту ъуйню.
		property Services::OrderControllerToken OrderToken 
		{
		public: OrderControllerToken get(System::Void) { return this->order_token; }
		}

		generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
		Task<Boolean>^ registration_order(String^ request_address, Models::CarModelTypes car_type);
		System::Boolean accept_request(System::Guid order_id, System::Guid driver_id);
		System::Boolean cancellation_order(System::Void);
	};

}
