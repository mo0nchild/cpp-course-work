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

	public interface class IOrderController 
	{
	public: generic<class TCarModelClass> where TCarModelClass : Models::CarBaseModel
		Task<Boolean>^ registration_order(String^ request_address, Models::CarModelTypes car_type);

	public:		System::Boolean accept_request(System::Guid order_id, System::Guid driver_id);
	public:		System::Boolean cancellation_order(System::Void);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::DepotManager::typeid)]
	public ref class OrderController sealed : Manager::ServiceBase, Services::IOrderController
	{
	public:		using OrderPairConnection = System::Tuple<System::Guid, System::Guid>;
	private:
		Services::OrderControllerToken order_token;
		Services::SqlDatabaseManager^ service_sql_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		OrderPairConnection^ connected_pair = nullptr;
		
		System::Threading::CancellationTokenSource^ cancel_source = nullptr;
		System::Threading::CancellationToken request_cancel_token;

	public:		delegate System::Void RequestCallback(System::Boolean);
	public:		event RequestCallback^ RequestCallbackEvent;
		  
	private:	System::Boolean order_process(System::Void);
	private:	System::Void order_callback(Task<bool>^ task) { RequestCallbackEvent(task->Result); }
	private:	System::Boolean add_request(System::Void);

	public:
		OrderController(SqlDatabaseManager^ sql_manager, DepotManager^ depot_manager)
			: Manager::ServiceBase()
		{ 
			this->service_sql_manager = sql_manager;
			this->service_depot_manager = depot_manager;
		}
		virtual ~OrderController(System::Void) { delete cancel_source; }
		
		property Services::OrderControllerToken OrderToken 
		{ public: OrderControllerToken get(System::Void) { return this->order_token; } }

		property List<Services::OrderControllerDbScheme^>^ OrderList 
		{ public: List<Services::OrderControllerDbScheme^>^ get(System::Void); }

		generic<class TCarModelClass> where TCarModelClass: Models::CarBaseModel
		virtual Task<System::Boolean>^ registration_order(System::String^ request_address, 
			Models::CarModelTypes car_type) override;

		virtual System::Boolean accept_request(Guid order_id, Guid driver_id) override;
		virtual System::Boolean cancellation_order(System::Void) override;
	};

}
