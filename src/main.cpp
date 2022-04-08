#include "../manager/manager.h"
#include "../services/controllers/controller_base.h"
#include "../services/managers/manager_base.h"

using namespace System;
using namespace Services;
using namespace Manager;
using namespace Models;

void order_callback_test(bool result) 
{
	Console::WriteLine(result.ToString());
}

int main(array<String^>^ args) 
{
	Manager::ServiceManagerBuilder^ builder = Manager::TaxiBooking::create_builder();

	builder->service_registration<ManagerBaseProvider^, GarageManager^>();
	builder->service_registration<ControllerBaseProvider^, OrderController^>();

	ServiceManager^ manager = builder->create_manager(
		gcnew System::Collections::Generic::Dictionary<String^, Object^>()
	);
	Manager::IServiceProvider^ myservice1 = manager->get_service<GarageManager^>();
	Manager::IServiceProvider^ myservice2 = manager->get_service<OrderController^>();

	GarageManager^ garage_manager = (GarageManager^) myservice1->Service;
	OrderController^ order_controller = (OrderController^) myservice2->Service;

	order_controller->RequestCallbackEvent += gcnew OrderController::RequestCallback(order_callback_test);
	order_controller->registration_order<Models::CarLightModel^>("адрес", Models::CarModelTypes::CarTypeEconom);
	

	Console::ReadKey();
	return 0;
}