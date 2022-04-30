#pragma once
#include "../database_provider/database_provider.h"
#include "../../manager/manager.h"
#include "bank_controller_scheme.h"

namespace Services
{
	using namespace System;
	using namespace System::Collections;
	using namespace Manager;

	public interface class IBankController
	{
	public:	System::Boolean transfer_money(System::Guid payee_guid, System::Int32 money);
	public:		System::Boolean take_money(System::Int32 money);
	public:		System::Boolean put_money(System::Int32 money);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class BankController sealed : Manager::ServiceBase, Services::IBankController
	{
	public: value struct BankAccount { System::Guid AccountGuid; System::Int32 Money; };

	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;
	private:	BankController::BankAccount^ bank_account = nullptr;

		BankAccountDbScheme^ account_check(System::Guid account_guid);
	public:
		property System::Guid AccountGuid { public: System::Guid get(System::Void); }
		property System::Int32 AccountMoney { public: System::Int32 get(System::Void); }
	public:
		[Manager::ServiceConfigurationAttribute("none")]
		BankController(IServiceBase::ServiceCtorConfiguration^ configuration, SqlDatabaseManager^ sql_manager) 
			: Manager::ServiceBase(configuration) { this->service_sql_manager = sql_manager; }

		virtual ~BankController(System::Void) { ServiceBase::~ServiceBase(); }
		virtual System::Boolean transfer_money(System::Guid payee_guid, System::Int32 money) override;

		virtual IServiceBase::ServiceQuery^ service_query_handler(System::TimeSpan work_time) override;

		System::Boolean load_bank_account(System::Guid account_guid);
		System::Boolean create_bank_account(System::Guid account_guid);
		Generic::List<System::Guid>^ get_bank_accounts(System::Void);

		virtual System::Boolean take_money(System::Int32 money) override;
		virtual System::Boolean put_money(System::Int32 money) override;
	};
}