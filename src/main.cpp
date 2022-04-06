#include "../manager/manager.h"
#include "../services/controllers/controller_base.h"
#include "../services/managers/manager_base.h"

using namespace System;
using namespace Services;
using namespace Manager;

int main(array<String^>^ args) 
{
	Manager::ServiceManagerBuilder^ builder = Manager::TaxiBooking::create_builder();

	builder->service_registration<ControllerBaseProvider^, OrderController^>();
	builder->service_registration<ManagerBaseProvider^, GarageManager^>();

	ServiceManager^ manager = builder->create_manager(
		gcnew System::Collections::Generic::Dictionary<String^, Object^>()
	);
	Manager::IServiceProvider^ myservice1 = manager->get_service<GarageManager^>();
	Manager::IServiceProvider^ myservice2 = manager->get_service<OrderController^>();

	GarageManager^ garage_manager = (GarageManager^) myservice1->Service;
	OrderController^ order_controller = (OrderController^) myservice2->Service;

	Console::ReadKey();
	return 0;
}