#pragma once

namespace Models 
{
	public ref class AccountBaseModel abstract
	{
	private:	System::String^ account_username;
	private:	System::UInt32 account_age;
	private:	System::Guid account_guid;

	public: 
		AccountBaseModel(System::String^ name, System::UInt32 age)
			: account_age(age), account_guid(System::Guid::NewGuid())
		{ this->account_username = name; }

		virtual ~AccountBaseModel(System::Void) { delete account_username; }

		property System::String^ Username 
		{
		public: System::String^ get(System::Void) { return this->account_username; }
		private: System::Void set(System::String^ value) { this->account_username = value; }
		}

		property System::UInt32 Age 
		{
		public: System::UInt32 get(System::Void) { return this->account_age; }
		}

		property System::Guid Id 
		{
		public: System::Guid get(System::Void) { return this->account_guid; }
		}
	};

	public ref class AccountDriverModel sealed : AccountBaseModel 
	{
		// лецензия, права (машины), 
	public: 
		AccountDriverModel(System::String^ name, System::UInt32 age) : AccountBaseModel(name, age) 
		{ }
		virtual ~AccountDriverModel(System::Void) { AccountBaseModel::~AccountBaseModel(); }
	};

	public ref class AccountPassengerModel sealed : AccountBaseModel
	{
		// номер карты, адрес
	public:
		AccountPassengerModel(System::String^ name, System::UInt32 age) : AccountBaseModel(name, age) 
		{ }
		virtual ~AccountPassengerModel(System::Void) { AccountBaseModel::~AccountBaseModel(); }
	};
}