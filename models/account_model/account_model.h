#pragma once

namespace Models 
{
	using namespace System;
	using namespace System::Collections::Generic;

	public enum class AccountModelGender : System::UInt16 { MaleGender, FemaleGender };

	public enum class AccountModelPermissions : System::UInt16 
	{ FullPermission = 0b00000111, CarGarage = 0b00000001, AccountList = 0b00000010, OrderList = 0b00000100 };

	public ref class AccountBaseModel abstract : System::ICloneable
	{
	private:	Models::AccountModelGender account_gender;
	private:	System::UInt32 account_age;
	
	private:	System::String^ account_username = nullptr;
	public:
		property System::String^ Username
		{
		public: System::String^ get(System::Void) { return this->account_username; }
		private: System::Void set(System::String^ value) { this->account_username = value; }
		}

		property AccountModelGender Gender { AccountModelGender get(System::Void) { return account_gender; } }
		property System::UInt32 Age { System::UInt32 get(System::Void) { return this->account_age; } }

	public: 
		AccountBaseModel(System::String^ name, System::UInt32 age, Models::AccountModelGender gender) 
			: account_age(age), account_gender(gender) { this->account_username = name; }
		virtual ~AccountBaseModel(System::Void) { delete account_username; }

		virtual System::Object^ Clone(System::Void) abstract;
	};

	public ref class AccountAdminModel sealed : Models::AccountBaseModel 
	{
		Models::AccountModelPermissions permissions;
	public:
		property Models::AccountModelPermissions Permissions
		{ public: AccountModelPermissions get(System::Void) { return this->permissions; } }
	public:
		AccountAdminModel(String^ name, UInt32 age, AccountModelGender gender, AccountModelPermissions permissions)
			: Models::AccountBaseModel(name, age, gender), permissions(permissions) { }
		virtual ~AccountAdminModel(System::Void) { AccountBaseModel::~AccountBaseModel(); }

		virtual System::Object^ Clone(System::Void) override 
		{ return gcnew AccountAdminModel((System::String^)Username->Clone(), Age, Gender, permissions); }
	};

	public ref class AccountDriverModel sealed : Models::AccountBaseModel
	{
		// лецензия, права (машины), 
		System::Guid driver_licence = System::Guid::Empty;
		System::UInt16 driver_experience = 0;
	public:
		property System::Guid Licence { System::Guid get(System::Void) { return this->driver_licence; } }
		property System::UInt16 Experience { System::UInt16 get(System::Void) { return this->driver_experience; } }
	public: 
		AccountDriverModel(String^ name, UInt32 age, AccountModelGender gender, Guid licence, UInt16 experience)
			: Models::AccountBaseModel(name, age, gender)
		{
			this->driver_experience = experience; 
			this->driver_licence = licence;
		}
		virtual ~AccountDriverModel(System::Void) { AccountBaseModel::~AccountBaseModel(); }

		virtual System::Object^ Clone(System::Void) override
		{ return gcnew AccountDriverModel((String^)Username->Clone(), Age, Gender, driver_licence, driver_experience); }
	};

	public ref class AccountClientModel sealed : Models::AccountBaseModel
	{
		System::String^ bank_card = nullptr;
	public: property System::String^ BankCard { System::String^ get(System::Void) { return (String^)bank_card->Clone(); } }
	public:
		AccountClientModel(System::String^ name, System::UInt32 age, AccountModelGender gender, System::String^ bank_card)
			: AccountBaseModel(name, age, gender) { this->bank_card = bank_card; }

		virtual ~AccountClientModel(System::Void) { delete this->bank_card; AccountBaseModel::~AccountBaseModel(); }

		virtual System::Object^ Clone(System::Void) override
		{ return gcnew AccountClientModel((String^)Username->Clone(), Age, Gender, (String^)bank_card->Clone()); }
	};
}