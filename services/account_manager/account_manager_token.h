#pragma once
#include "../../models/account_model/account_model.h"
#include "../../models/cars_model/cars_model.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace Models;

	public ref class AccountManagerTokenException sealed : System::Exception
	{
	public: AccountManagerTokenException(System::String^ message) : System::Exception(message) { }
		virtual ~AccountManagerTokenException(System::Void) { }
	};

	public value struct AccountManagerToken sealed
	{
	public:	enum class AccountManagerType : System::UInt16 { Admin, Driver, Client };

	private:	System::Guid account_guid;
	private:	AccountManagerToken::AccountManagerType account_type;
	private:	Models::AccountBaseModel^ account_model;

	public:
		property System::Guid AccountGuid
		{ public:	System::Guid get(System::Void) { return this->account_guid; } };

		property Models::AccountBaseModel^ AccountModel 
		{ AccountBaseModel^ get(System::Void) { return (AccountBaseModel^)account_model->Clone(); } }

		property Services::AccountManagerToken::AccountManagerType AccountType
		{ AccountManagerToken::AccountManagerType get(System::Void) { return account_type; } };

	public: AccountManagerToken(AccountManagerType type, Models::AccountBaseModel^ model, Guid id)
		: account_guid(id), account_type(type) 
	{ 
		if (model != nullptr) this->account_model = (AccountBaseModel^)model->Clone();
		else this->account_model = nullptr;
	}
	};
}
