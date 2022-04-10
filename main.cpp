#include "manager/manager.h"
#include "services/services.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Xml;

using namespace Services;
using namespace Manager;
using namespace Models;

void test_request(bool result) 
{
	Console::WriteLine("order: " + result.ToString());
}

int main(array<String^>^ args) 
{
	Manager::ServiceManagerBuilder^ builder = Manager::ManagerBooking::create_builder();

	builder->service_registration<MyServicesProvider^, SqlDatabaseManager^>();
	builder->service_registration<MyServicesProvider^, DepotManager^>();
	builder->service_registration<MyServicesProvider^, OrderController^>();

	ServiceManager^ manager = builder->create_manager(
		gcnew System::Collections::Generic::Dictionary<String^, Object^>()
	);
	Manager::IServiceProvider^ myservice1 = manager->get_service<DepotManager^>();
	Manager::IServiceProvider^ myservice2 = manager->get_service<OrderController^>();
	Manager::IServiceProvider^ myservice3 = manager->get_service<SqlDatabaseManager^>();

	SqlDatabaseManager^ db = (SqlDatabaseManager^)myservice3->Service;
	db->get_data();

	/*DepotManager^ garage_manager = (DepotManager^) myservice1->Service;
	OrderController^ order_controller = (OrderController^) myservice2->Service;

	order_controller->RequestCallbackEvent += gcnew OrderController::RequestCallback(test_request);
	order_controller->registration_order<Models::CarLightModel^>("адрес", Models::CarModelTypes::CarTypeEconom);

	Guid accept;
	for each ( auto i in garage_manager->DriverRequest) 
	{
		Console::WriteLine(i->Item1 + "\t" + i->Item2);
		accept = i->Item1;
	}
	garage_manager->accept_request(accept, Guid::NewGuid());*/
	
	/*Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	Views::Generator form;
	Application::Run(%form);*/

	Console::ReadKey();
	return 0;
}