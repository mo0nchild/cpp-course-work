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
		service_builder->service_registration<MyServicesProvider^, DepotManager^>();
		service_builder->service_registration<MyServicesProvider^, OrderController^>();
		service_builder->service_registration<MyServicesProvider^, AccountManager^>();

		Manager::ServiceManager^ services_manager = service_builder->create_manager(
			gcnew Generic::Dictionary<System::String^, System::Object^>());

		/*Manager::IServiceProvider^ depot_manager_provider = services_manager->get_service<DepotManager^>();
		DepotManager^ depot_manager = (DepotManager^)depot_manager_provider->Service;
		depot_manager->rent_car_model<Models::CarLightModel^>(
			gcnew Models::CarLightModel(CarModelTypes::CarTypeEconom, CarModelColor::CarColorBlack, 10), System::Guid::NewGuid());
		
		auto result = depot_manager->rent_car_model<Models::CarLightModel^>(
			gcnew Models::CarLightModel(CarModelTypes::CarTypeEconom, CarModelColor::CarColorBlack, 10), System::Guid::NewGuid());

		auto sended = depot_manager->add_car_model<Models::CarHeavyModel^>(gcnew Models::CarHeavyModel(CarModelTypes::CarTypeEconom, CarModelColor::CarColorRed, 20), 3);

		Console::WriteLine("add: " + sended);

		Console::WriteLine(result);
		Console::WriteLine(depot_manager->DriverState);
		Console::WriteLine(depot_manager->DriverGuid);
		Console::ReadKey("вернуть?");
		depot_manager->return_car_model();*/


		/*Manager::IServiceProvider^ myservice = services_manager->get_service<AccountManager^>();
		AccountManager^ account_manager = (AccountManager^)myservice->Service;

		Console::WriteLine(account_manager->authorization_account("user1", "123456789"));
		delete account_manager;*/

		//Views::authorization_page form;
		//System::Windows::Forms::Application::Run(%form);
		Console::ReadKey();
		return System::Int32(0);
	}
};

[STAThreadAttribute]
System::Int32 main(array<System::String^>^ args) { return Program::Run(args); }