#pragma once
#include "../database_provider/database_provider.h"
#include "../../manager/manager.h"

namespace Services
{
	using namespace System;
	using namespace System::Collections;

	public interface class IBankController
	{
	public:	System::Boolean transfer_money(System::Guid payee_guid, System::UInt32 money);
	public:		System::Boolean take_money(System::UInt32 money);
	public:		System::Boolean put_money(System::UInt32 money);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class BankController sealed : Manager::ServiceBase, Services::IBankController
	{
	public: value struct BankAccount { System::Guid AccountGuid; System::UInt32 Money; };
	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;
	private:	BankController::BankAccount^ bank_account = nullptr;
	public:
		property System::Guid AccountGuid { public: System::Guid get(System::Void); }
		property System::UInt32 AccountMoney { public: System::UInt32 get(System::Void); }
	public:
		BankController(SqlDatabaseManager^ sql_manager) : Manager::ServiceBase()
		{ this->service_sql_manager = sql_manager; }

		virtual ~BankController(System::Void) { ServiceBase::~ServiceBase(); }
		virtual System::Boolean transfer_money(System::Guid payee_guid, System::UInt32 money) override;

		System::Boolean load_bank_account(System::Guid account_guid);
		Generic::List<System::Guid>^ get_bank_accounts(System::Void);

		virtual System::Boolean take_money(System::UInt32 money) override;
		virtual System::Boolean put_money(System::UInt32 money) override;
	};
}