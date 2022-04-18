#pragma once
#include "../../models/account_model/account_model.h"
#include "../../models/cars_model/cars_model.h"

namespace Services 
{
	using namespace System;
	using namespace Models;
	using namespace System::Collections::Generic;

	public ref class AccountManagerTokenException sealed : System::Exception
	{
	private:	System::Type^ exception_attach_from = nullptr;
	public:
		property System::Type^ AttachFrom
		{ public: System::Type^ get(System::Void) { return this->exception_attach_from; } }

		virtual property System::String^ Message
		{
		public: System::String^ get(System::Void) override
			{ return "From " + exception_attach_from->ToString() + ": " + Exception::Message; }
		}
	public: AccountManagerTokenException(System::Type^ from, System::String^ message) : System::Exception(message) 
		{ this->exception_attach_from = from; }
		virtual ~AccountManagerTokenException(System::Void) { delete exception_attach_from; }
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
