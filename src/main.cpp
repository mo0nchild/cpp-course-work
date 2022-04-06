#include "../manager/manager.h"
#include "../services/controllers/controller_base.h"
#include "../services/managers/manager_base.h"

using namespace System;
using namespace Services;

int main(array<String^>^ args) 
{
	/*Manager::ServiceManagerBuilder^ builder = Manager::TaxiBooking::create_builder();
	array<Object^>^ param = gcnew array<Object^>(1);

	builder->service_registration<ControllerBaseProvider^, ControllerBase^>();
	builder->service_registration<ControllerBaseProvider^, ManagerBase^>();

	Manager::ServiceManager^ manager = builder->create_manager(
		gcnew System::Collections::Generic::Dictionary<String^, Object^>()
	);
	ControllerBaseProvider^ myservice1 = (ControllerBaseProvider^)manager->get_service<ManagerBase^>();
	ControllerBaseProvider^ myservice2 = (ControllerBaseProvider^)manager->get_service<ControllerBase^>();
	
	if (myservice1 == nullptr) Console::WriteLine("My Manager not found");*/

	Console::ReadKey();
	return 0;
}