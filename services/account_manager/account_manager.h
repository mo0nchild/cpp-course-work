#pragma once
#include "../database_provider/database_provider.h"
#include "../../manager/manager.h"
#include "account_manager_scheme.h"
#include "account_manager_token.h"

namespace Services 
{
	public interface class IAccountManager 
	{
	public:
		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
		System::Boolean registration_account(System::String^ login, System::String^ password, 
			TAccountModel account_model);
		System::Boolean authorization_account(System::String^ login, System::String^ password);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class AccountManager sealed : Manager::ServiceBase, Services::IAccountManager
	{
	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;

	private:	System::Boolean account_initialized;
	private:	Services::AccountManagerToken account_token;
	public:
		property System::Boolean IsInitialized { System::Boolean get(System::Void) { return this->account_initialized; } }
		property Services::AccountManagerToken AccountToken
		{ 
		public:	Services::AccountManagerToken get(System::Void)
			{ 
				if (this->account_initialized) return this->account_token;
				throw gcnew AccountManagerTokenException("From AccountManager: token not init");
			}
		protected: System::Void set(Services::AccountManagerToken value) { this->account_token = value; }
		}
	public:
		AccountManager(SqlDatabaseManager^ sql_manager) : Manager::ServiceBase(), account_initialized(false)
		{ this->service_sql_manager = sql_manager; }
		virtual ~AccountManager(System::Void) { Manager::ServiceBase::~ServiceBase(); }

		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
		virtual System::Boolean registration_account(System::String^ login, System::String^ password,
			TAccountModel account_model) override;

		virtual System::Boolean authorization_account(System::String^ login, System::String^ password) override;

		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
			System::Boolean update_account(TAccountModel account_model);

		System::Boolean delete_account(System::Void);
		System::Boolean sign_out_account(System::Void);
	};
}