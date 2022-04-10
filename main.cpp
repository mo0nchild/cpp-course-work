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

	List<IDatabaseManager::KeyValuePair^>^ req_row = gcnew List<IDatabaseManager::KeyValuePair^>();
	req_row->Add(gcnew IDatabaseManager::KeyValuePair("car_type", "suprume"));
	req_row->Add(gcnew IDatabaseManager::KeyValuePair("address", "Yrupinsk"));
	db->send_database_data(req_row);

	List<IDatabaseManager::KeyValuePair^>^ arr = gcnew List<IDatabaseManager::KeyValuePair^>();
	arr->Add(gcnew IDatabaseManager::KeyValuePair("car_type", "econom"));
	auto rows = db->get_database_data(arr);

	for each (auto items in rows) 
	{
		for each (auto i in items) { Console::Write(i->ToString() + " "); }
		Console::WriteLine();
	}

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