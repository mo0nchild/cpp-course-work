#include "depot_manager.h"

using namespace Services;

System::Boolean DepotManager::add_request(Services::OrderControllerToken order_token)
{
	/*Tuple<System::Guid, System::String^>^ request = gcnew Tuple<System::Guid, System::String^>(id, address);

	if (request_driver->Contains(request) != true)
		this->request_driver->Add(gcnew Tuple<System::Guid, System::String^>(id, address));
	else return false;*/

	return true;
}

System::Boolean DepotManager::check_request(System::Guid order_id, RequestType request_type)
{
	/*for (int i = 0; i < this->test_find_pair->Count; i++)
	{
		OrderPairConnection^ pair_check = this->test_find_pair[i];
		if (pair_check->Item1 == order_id) { connected_pair = pair_check; return true; }
	}*/
	return false;
}

System::Boolean DepotManager::accept_request(Guid order_id, Guid driver_id)
{
	/*for each (auto i in request_driver)
	{
		if (i->Item1 == order_id)
		{
			test_find_pair->Add(gcnew OrderPairConnection(order_id, driver_id));
		}
	}*/
	return true;
}