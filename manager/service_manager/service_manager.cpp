#pragma once
#include "service_manager.h"

using namespace Manager;

generic <class TService> where TService : IServiceBase ServiceProvider^ ServiceManager::get_service(System::Void)
{
	System::Type^ service_require = TService::typeid;
	Manager::ServiceProvider^ provider = nullptr;

	for each (Manager::ServiceRecord^ srv in this->service_collection->ServiceList)
	{
		if (srv->ServiceInstance->GetType() == service_require)
		{
			array<System::Object^>^ params = gcnew array<System::Object^> { srv->ServiceInstance, srv->ServiceDependencies };

			try { provider = safe_cast<Manager::ServiceProvider^>(Activator::CreateInstance(srv->ServiceProvider, params)); }
			catch (System::MissingMethodException^ error) { Console::WriteLine(error->Message); break; }
		}
	}
	return provider;
}

Generic::List<System::Type^>^ ServiceManager::get_all_services(System::Void)
{
	Generic::List<System::Type^>^ result_collection = gcnew Generic::List<System::Type^>();

	for each (Manager::ServiceRecord ^ item in this->service_collection->ServiceList)
	{ result_collection->Add(item->ServiceInstance->GetType()); }

	return result_collection;
}

System::Boolean ServiceManager::service_handling_connection(System::Void) 
{
	for each (Manager::ServiceRecord^ service_item in this->service_collection->ServiceList)
	{
		try { this->ServiceEventHandler += gcnew ServiceManager::ServiceDelegateHandler(
			service_item->ServiceInstance, &IServiceBase::service_query_handler); }
		catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }
	}
	return true;
}

System::Void console_service_state(IServiceBase::ServiceQuery^ query) 
{
	switch (query->State) 
	{
	case ServiceState::Idle:; Console::BackgroundColor = ConsoleColor::Gray; break;
	case ServiceState::Killed:; Console::BackgroundColor = ConsoleColor::Magenta; break;
	case ServiceState::Running:; Console::BackgroundColor = ConsoleColor::DarkGreen; break;
	}

	Console::Write("[ " + query->State.ToString() + " ]");
	Console::BackgroundColor = ConsoleColor::Black;
	
	Console::WriteLine(" [ " + query->ServiceType->ToString() + " ] : " + query->Message);
}

System::Void ServiceManager::service_handling_process(System::Void)
{
	System::UInt32 tick_millisecond = this->service_handling_timer->TotalMilliseconds;
	for(System::UInt64 iteration_tick = 0; true; iteration_tick++)
	{
		Console::WriteLine("========= [ " + System::DateTime::Now + " ] ### Сообщение от Менеджера сервисов =========");
		for each (auto handler in this->services_event_handler->GetInvocationList()) 
		{
			ServiceManager::ServiceDelegateHandler^ handler_delegate = nullptr;
			try { handler_delegate = safe_cast<ServiceManager::ServiceDelegateHandler^>(handler); }
			catch (System::Exception^ error)
			{ Console::WriteLine(error->Message); this->stop_service_handler(); break; }

			IServiceBase::ServiceQuery^ query = handler_delegate->Invoke(System::TimeSpan::FromSeconds(iteration_tick));
			console_service_state(query);
		}
		Console::WriteLine();

		if (this->cancellation_token.IsCancellationRequested) return;
		Thread::Sleep(tick_millisecond);
	}
}

Tasks::Task^ ServiceManager::start_service_handler(System::TimeSpan tick_timer)
{
	this->cancel_source = gcnew CancellationTokenSource();
	this->cancellation_token = this->cancel_source->Token;
	this->service_handling_timer = tick_timer;

	Tasks::Task^ service_handling_task = gcnew Tasks::Task(
		gcnew Action(this, &ServiceManager::service_handling_process), this->cancel_source->Token);
	service_handling_task->Start();

	if (service_handling_task != nullptr) 
	{
		for each (auto service_item in this->service_collection->ServiceList)
			service_item->ServiceInstance->ServiceState = Manager::ServiceState::Running;
	}

	return service_handling_task;
}

System::Boolean ServiceManager::stop_service_handler(System::Void)
{
	try { this->cancel_source->Cancel(); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	for each (auto service_item in this->service_collection->ServiceList)
		service_item->ServiceInstance->ServiceState = Manager::ServiceState::Idle;

	this->cancel_source = nullptr;
	return true;
}