#include "manager/manager.h"
#include "services/services.h"
//#include "views/authorization/authorization_page.h"

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Xml;

using namespace Services;
using namespace Manager;
using namespace Models;

public ref class Program sealed
{
public:
	static System::Int32 Run(array<System::String^>^ params)
	{
		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
		Manager::ServiceManagerBuilder^ service_builder = Manager::ManagerBooking::create_builder();

		service_builder->service_registration<MyServicesProvider^, SqlDatabaseManager^>();
		service_builder->service_registration<MyServicesProvider^, BankController^>();
		service_builder->service_registration<MyServicesProvider^, DepotManager^>();

		service_builder->service_registration<MyServicesProvider^, OrderController^>();
		service_builder->service_registration<MyServicesProvider^, AccountManager^>();

		Manager::ServiceManager^ services_manager = service_builder->create_manager(
			gcnew Generic::Dictionary<System::String^, System::Object^>());

		//Views::authorization_page form;
		//System::Windows::Forms::Application::Run(%form);
		Console::ReadKey();
		return System::Int32(0);
	}
};

[STAThreadAttribute]
System::Int32 main(array<System::String^>^ args) { return Program::Run(args); }