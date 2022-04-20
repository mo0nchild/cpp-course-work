#pragma once
#include "../database_provider/database_provider.h"
#include "../database_provider/database_provider_attribute.h"

namespace Services
{
	[Services::SqlDatabaseTableAttribute("bank_accounts")]
	public ref struct BankAccountDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public: [Services::SqlDatabaseFieldAttribute("account_guid")] property System::String^ account_guid;
	public: [Services::SqlDatabaseFieldAttribute("account_money")] property System::String^ account_money;
	public: [Services::SqlDatabaseFieldAttribute("account_marker")] property System::String^ account_marker;

		BankAccountDbScheme(System::String^ p1, System::String^ p2, System::String^ p3)
		{ this->account_guid = p1; this->account_money = p2; this->account_marker = p3; }

		BankAccountDbScheme(System::Void) { this->account_guid = ""; this->account_money = ""; this->account_marker = ""; }
		virtual ~BankAccountDbScheme(System::Void) { delete account_guid, account_money, account_marker; }
	};
}