#include "manager/manager.h"

using namespace System;
// https://metanit.com/sharp/aspnet6/4.3.php


public ref class MyController: Manager::ServiceBase
{
public:
	String^ test = "TestWord";

	[Manager::ServiceAttribute::ServiceRequireTargetAttribute]
	MyController() { }
};


public ref class MyControllerProvider : Manager::ServiceProvider
{
public:
	MyControllerProvider(String^ serv) : Manager::ServiceProvider(gcnew MyController())
	{

	}
};

[Manager::ServiceAttribute::ServiceRequireAttribute(MyController::typeid)]
public ref class MyManager : Manager::ServiceBase
{
	MyController^ controller;
public:

	MyManager(MyController^ controller)
	{  
		this->controller = controller;
	}

	void Action() { Console::WriteLine(controller->test); }

	MyManager(String^ test) { }
};

public ref class MyManagerProvider : Manager::ServiceProvider
{
public:
	MyManagerProvider(Manager::ServiceBase^ serv) : Manager::ServiceProvider(serv)
	{

	}
};

int main(array<String^>^ args) 
{
	Manager::ServiceManagerBuilder^ builder = Manager::TaxiBooking::create_builder();
	array<Object^>^ param = gcnew array<Object^>(1);

	builder->service_registration<MyControllerProvider^, MyController^>();
	builder->service_registration<MyManagerProvider^, MyManager^>();

	Manager::ServiceManager^ manager = builder->create_manager(gcnew System::Collections::Generic::Dictionary<String^, Object^>());
	MyManagerProvider^ myservice1 = (MyManagerProvider^) manager->get_service<MyManager^>();
	MyControllerProvider^ myservice2 = (MyControllerProvider^)manager->get_service<MyController^>();



	Console::ReadKey();
	return 0;
}