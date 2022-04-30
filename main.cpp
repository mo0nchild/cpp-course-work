#include "manager/manager.h"
#include "services/services.h"
#include "views/authorization_view/authorization_view.h"

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Xml;

using namespace Services;
using namespace Manager;
using namespace Models;

public ref class ServiceManagerCli sealed
{
public:
	static System::Void manager_process(System::Void) 
	{
		// сделать отдельный поток для менеждера
	}
};

public ref class Program sealed
{
public:
	static System::Int32 Run(array<System::String^>^ params)
	{
		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
		Manager::ServiceManagerBuilder^ service_builder = Manager::ManagerBooking::create_builder();

		service_builder->service_configuration_load("./services/services_settings.xml");

		service_builder->service_registration<MyServicesProvider^, SqlDatabaseManager^>();
		service_builder->service_registration<MyServicesProvider^, BankController^>();
		service_builder->service_registration<MyServicesProvider^, DepotManager^>();

		service_builder->service_registration<MyServicesProvider^, OrderController^>();
		service_builder->service_registration<MyServicesProvider^, AccountManager^>();

		Manager::ServiceManager^ services_manager = service_builder->create_manager();

		/*services_manager->start_service_handler(System::TimeSpan(0, 0, 3));*/

		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
		Views::AuthorizationView^ form = gcnew Views::AuthorizationView(services_manager);
		System::Windows::Forms::Application::Run(form);
		
		Console::ReadKey();

		return System::Int32(0);
	}
};

[STAThreadAttribute]
System::Int32 main(array<System::String^>^ args) { return Program::Run(args); }