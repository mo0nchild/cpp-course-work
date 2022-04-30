#pragma once
#include "../database_provider/database_provider.h"
#include "../../manager/manager.h"
#include "account_manager_scheme.h"
#include "account_manager_token.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace Manager;

	public interface class IAccountManager 
	{
	public:
		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
		System::Boolean registration_account(System::String^ login, System::String^ password, 
			TAccountModel account_model);
		System::Boolean authorization_account(System::String^ login, System::String^ password);

		System::Boolean delete_account(System::Guid guid);
		System::Boolean sign_out_account(System::Void);
	};

	[Manager::ServiceAttribute::ServiceRequireAttribute(Services::SqlDatabaseManager::typeid)]
	public ref class AccountManager sealed : Manager::ServiceBase, Services::IAccountManager
	{
	public:	value struct AccountInfo { System::Boolean State;
		System::Guid Guid; System::String^ Name; AccountManagerToken::AccountManagerType Type; };

	private:	Services::SqlDatabaseManager^ service_sql_manager = nullptr;
				System::Boolean service_disposed = false;

	private:	System::Boolean account_initialized;
	private:	Services::AccountManagerToken account_token;
	public:
		property System::Boolean IsInitialized { System::Boolean get(System::Void) { return this->account_initialized; } }
		property List<AccountManager::AccountInfo>^ AccountList { List<AccountManager::AccountInfo>^ get(System::Void); }

		property Services::AccountManagerToken AccountToken
		{ 
		public:	Services::AccountManagerToken get(System::Void)
			{ 
				if (this->account_initialized) return this->account_token;
				throw gcnew AccountManagerTokenException(AccountManagerToken::typeid, "token not init");
			}
		protected: System::Void set(Services::AccountManagerToken value) { this->account_token = value; }
		}
	public:
		[Manager::ServiceConfigurationAttribute("none")]
		AccountManager(IServiceBase::ServiceCtorConfiguration^ configuration, SqlDatabaseManager^ sql_manager) 
			: Manager::ServiceBase(configuration), account_initialized(false)
		{ this->service_sql_manager = sql_manager; }

		virtual ~AccountManager(System::Void) { AccountManager::!AccountManager(); }
		!AccountManager(System::Void) { if (!service_disposed) { this->sign_out_account(); service_disposed = true; } }

		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
		virtual System::Boolean registration_account(System::String^ login, System::String^ password,
			TAccountModel account_model) override;

		virtual System::Boolean authorization_account(System::String^ login, System::String^ password) override;

		generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
			System::Boolean update_account(TAccountModel account_model);

		generic <class TAccountScheme> where TAccountScheme : Services:: AccountClassesDbScheme
			TAccountScheme get_account_scheme(System::Guid account_guid);

		virtual IServiceBase::ServiceQuery^ service_query_handler(System::TimeSpan work_time) override;

		System::Nullable<System::Boolean> get_account_status(System::Guid account_guid);

		virtual System::Boolean delete_account(System::Guid guid) override;
		virtual System::Boolean sign_out_account(System::Void) override;
	};
}