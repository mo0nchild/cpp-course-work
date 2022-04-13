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

	//SqlDatabaseManager^ db = (SqlDatabaseManager^)myservice3->Service;
	//db->TableName = "order_collection";

	//List<IDatabaseManager::KeyValuePair^>^ arr = gcnew List<IDatabaseManager::KeyValuePair^>();
	//arr->Add(gcnew IDatabaseManager::KeyValuePair("date_time", "12.04.2022/21:32"));
	//auto rows = db->set_scheme_struct<Services::OrderControllerDbScheme^>()->get_database_data(arr);

	//if (rows == nullptr) { Console::WriteLine("rows are null"); }

	//for each (auto items in rows) 
	//{
	//	Console::Write("->\t");
	//	Services::OrderControllerDbScheme^ scheme = safe_cast<Services::OrderControllerDbScheme^>(items);
	//	Console::WriteLine(scheme->date_time);
	//	//Console::WriteLine(scheme->address);
	//	//Console::WriteLine(scheme->car_type);
	//	//Console::WriteLine(scheme->car_class);
	//	//Console::WriteLine(scheme->drive_guid);
	//	//Console::WriteLine(scheme->order_guid);
	//	//Console::WriteLine(scheme->order_status);
	//}
	//Services::OrderControllerDbScheme^ scheme = gcnew Services::OrderControllerDbScheme("","","", "123123", "", "","");
	//bool check1 = db->send_database_data(scheme);
	//bool check2 = db->delete_database_data(gcnew Services::IDatabaseManager::KeyValuePair("car_class", "123123"));

	DepotManager^ garage_manager = (DepotManager^) myservice1->Service;
	OrderController^ order_controller = (OrderController^) myservice2->Service;

	order_controller->RequestCallbackEvent += gcnew OrderController::RequestCallback(test_request);
	order_controller->registration_order<Models::CarLightModel^>("адрес", Models::CarModelTypes::CarTypeEconom);

	Thread::Sleep(2000);

	order_controller->accept_request(order_controller->OrderToken.OrderTokenGuid, System::Guid::NewGuid());
	order_controller->cancellation_order();

	//Guid accept;
	//for each ( auto i in garage_manager->DriverRequest) 
	//{
	//	Console::WriteLine(i->Item1 + "\t" + i->Item2);
	//	accept = i->Item1;
	//}
	//garage_manager->accept_request(accept, Guid::NewGuid());

	/*Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	Views::Generator form;
	Application::Run(%form);*/

	Console::ReadKey();
	return 0;
}