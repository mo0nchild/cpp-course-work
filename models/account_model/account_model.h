#pragma once

namespace Models 
{
	public ref class AccountBaseModel abstract
	{
	private:
		System::String^ account_username;
		System::UInt32 account_age;
		System::Guid account_guid;

	public: 
		AccountBaseModel(System::Void) { }
		virtual ~AccountBaseModel(System::Void) { }

		property System::String^ Username 
		{
		public: System::String^ get(System::Void) { return this->account_username; }
		private: System::Void set(System::String^ value) { this->account_username = value; }
		}

		property System::UInt32 Age 
		{
		public: System::UInt32 get(System::Void) { return this->account_age; }
		}
	};

	public ref class AccountDriverModel sealed : AccountBaseModel 
	{
		// лецензия, права (машины), 
	public: 
		AccountDriverModel(System::Void) : AccountBaseModel() { }
		virtual ~AccountDriverModel(System::Void) { }
	};

	public ref class AccountPassengerModel sealed : AccountBaseModel
	{
		// номер карты, адрес
	public:
		AccountPassengerModel(System::Void) : AccountBaseModel() { }
		virtual ~AccountPassengerModel(System::Void) { }
	};
}