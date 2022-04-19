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

		Manager::IServiceProvider^ depot_manager_provider = services_manager->get_service<DepotManager^>();
		DepotManager^ depot_manager = (DepotManager^)depot_manager_provider->Service;

		depot_manager->rent_car_model<Models::CarHeavyModel^>(
			gcnew Models::CarHeavyModel(CarModelTypes::CarTypeEconom, CarModelColor::CarColorRed, 20), System::Guid::NewGuid());

		auto drivers = depot_manager->get_all_drivers();

		for each (auto i in drivers)
		{
			Console::WriteLine(i.ToString());
		}

		depot_manager->update_drive_state(DriveComplexToken::DriverStateType::Ready);

		Console::WriteLine(depot_manager->DriverState);
		Console::ReadKey();

		depot_manager->return_car_model();
		//Views::authorization_page form;
		//System::Windows::Forms::Application::Run(%form);
		Console::ReadKey();
		return System::Int32(0);
	}
};

[STAThreadAttribute]
System::Int32 main(array<System::String^>^ args) { return Program::Run(args); }