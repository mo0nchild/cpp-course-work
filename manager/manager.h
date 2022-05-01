#pragma once

#ifndef MANAGER_INCLUDE_STUFF
#define MANAGER_INCLUDE_STUFF

#include "service_collection/service_collection.h"
#include "service_manager/service_manager.h"
#include "service_manager_builder/service_manager_builder.h"
#include "service_attribute/service_attribute.h"
#include "service_items/service_items.h"

namespace Manager
{
	public ref class ManagerBooking sealed
	{
	public: 
		inline static ServiceManagerBuilder^ create_builder(System::Void) 
		{ return gcnew Manager::ServiceManagerBuilder(); }

	public:		explicit ManagerBooking(System::Void) { }
	public:		virtual ~ManagerBooking(System::Void) { }
	};

	public ref class ServiceManagerCli sealed
	{
	private:	Manager::ServiceManager^ service_manager = nullptr;
	private:	System::TimeSpan handling_timer;
	private:
		System::Void service_manager_help(System::Void)
		{
			Console::WriteLine("[$] - | manager_help | - [Помощник по командам менеджера]");
			Console::WriteLine("[$] - | run_handling | - [Запуск обработки сервисов]");
			Console::WriteLine("[$] - | service_list | - [Список зарегистрированных сервисов]");
			Console::WriteLine("[$] - | manager_exit | - [Список зарегистрированных сервисов]");
		}
		System::Void service_manager_process(System::Void)
		{
			Console::BackgroundColor = ConsoleColor::DarkYellow;
			Console::WriteLine("|=================| SERVICE MANAGER CLIENT |=================|");
			Console::BackgroundColor = ConsoleColor::Black;	this->service_manager_help();
			while (true)
			{
				Console::Write("[$] > ");	System::String^ manager_command = Console::ReadLine();
				if (manager_command == System::String::Empty) continue;
				array<System::String^>^ command_arg_list = manager_command->Split(' ');

				if (command_arg_list[0] == "run_handling")
				{
					Console::WriteLine("[$] - [Для остановки нажмите любую клавишу]");
					this->service_manager->start_service_handler(this->handling_timer);
					Console::ReadKey(); this->service_manager->stop_service_handler();
				}
				else if (command_arg_list[0] == "manager_help") { this->service_manager_help(); }
				else if (command_arg_list[0] == "service_list")
				{
					for each (auto item in this->service_manager->get_all_services())
					{ Console::WriteLine("[$] - [" + item->FullName + "]"); }
				}
				else if (command_arg_list[0] == "manager_exit") { Console::Clear(); break; }
				else Console::WriteLine("[$] - [Комманда была не распознана]");
			}
		}
	public:
		explicit ServiceManagerCli(Manager::ServiceManager^ service_manager, System::TimeSpan handling_timer)
		{ this->service_manager = service_manager; this->handling_timer = handling_timer; }
		virtual ~ServiceManagerCli(System::Void) { }

		System::Void service_manager_run(System::Void)
		{
			Threading::Thread^ manager_thread = gcnew Threading::Thread(
				gcnew Threading::ThreadStart(this, &ServiceManagerCli::service_manager_process));
			manager_thread->Start();
		}
	};
}

#endif // !MANAGER_INCLUDE_STUFF

