#pragma once
#include "../database_provider/database_provider.h"
#include "../database_provider/database_provider_attribute.h"
#include "../../models/account_model/account_model.h"

namespace Services
{
	using namespace System;
	using namespace System::Collections::Generic;

	public interface class AccountClassesDbScheme {};

	[Services::SqlDatabaseTableAttribute("account_authentication")]
	public ref class AccountAuthenticationDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public: [Services::SqlDatabaseFieldAttribute("account_guid")]		property System::String^ account_guid;
	public: [Services::SqlDatabaseFieldAttribute("account_login")]		property System::String^ login; 
	public: [Services::SqlDatabaseFieldAttribute("account_password")]	property System::String^ password;
	public: [Services::SqlDatabaseFieldAttribute("account_type")]		property System::String^ type;
	public: [Services::SqlDatabaseFieldAttribute("account_state")]		property System::String^ state;

		  AccountAuthenticationDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, 
			  System::String^ p4, System::String^ p5)
		  { this->account_guid = p1;	this->login = p2;	this->password = p3;	this->type = p4;	this->state = p5; }
		  AccountAuthenticationDbScheme(System::Void)
		  { this->account_guid = "";	this->login = "";	this->password = "";	this->type = "";	this->state = ""; }

		  virtual ~AccountAuthenticationDbScheme(System::Void) { delete account_guid, login, password; }
	};

	[Services::SqlDatabaseTableAttribute("account_clients")]
	public ref class AccountClientsDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType, AccountClassesDbScheme
	{
	public: [Services::SqlDatabaseFieldAttribute("account_guid")]	property System::String^ account_guid;
	public: [Services::SqlDatabaseFieldAttribute("username")]		property System::String^ username;
	public: [Services::SqlDatabaseFieldAttribute("age")]			property System::String^ age;
	public: [Services::SqlDatabaseFieldAttribute("gender")]			property System::String^ gender;
	public: [Services::SqlDatabaseFieldAttribute("bank_card")]		property System::String^ bank_card;

		AccountClientsDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, System::String^ p4, System::String^ p5)
		{ 
			this->account_guid = p1;	this->username = p2;	this->age = p3;	this->gender = p4;	this->bank_card = p5; 
		}
		AccountClientsDbScheme(System::Void)
		{ 
			this->account_guid = "";	this->username = "";	this->age = "";	this->gender = "";	this->bank_card = ""; 
		}

		virtual ~AccountClientsDbScheme(System::Void) { delete account_guid, username, age, gender, bank_card; }
		static Models::AccountClientModel^ cast_to_model(AccountClientsDbScheme^ scheme);
		static AccountClientsDbScheme^ cast_to_scheme(Models::AccountClientModel^ model, System::Guid guid);
	};

	[Services::SqlDatabaseTableAttribute("account_drivers")]
	public ref class AccountDriversDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType, AccountClassesDbScheme
	{
	public: [Services::SqlDatabaseFieldAttribute("account_guid")]		property System::String^ account_guid;
	public: [Services::SqlDatabaseFieldAttribute("username")]			property System::String^ username;
	public: [Services::SqlDatabaseFieldAttribute("age")]				property System::String^ age;
	public: [Services::SqlDatabaseFieldAttribute("gender")]				property System::String^ gender;
	public: [Services::SqlDatabaseFieldAttribute("driver_licence")]		property System::String^ licence;
	public: [Services::SqlDatabaseFieldAttribute("bank_card")]			property System::String^ bank_card;

		  AccountDriversDbScheme(System::String^ p1, System::String^ p2, System::String^ p3,
			  System::String^ p4, System::String^ p5, System::String^ p6)
		  {
			  this->account_guid = p1;	this->username = p2;	this->age = p3;	this->gender = p4;	
			  this->licence = p5;		this->bank_card = p6;
		  }
		  AccountDriversDbScheme(System::Void)
		  {
			  this->account_guid = "";	this->username = "";	this->age = "";	this->gender = "";
			  this->licence = "";		this->bank_card = "";
		  }

		  virtual ~AccountDriversDbScheme(System::Void) { delete account_guid, username, age, gender, licence, bank_card; }
		  static Models::AccountDriverModel^ cast_to_model(AccountDriversDbScheme^ scheme);
		  static AccountDriversDbScheme^ cast_to_scheme(Models::AccountDriverModel^ model, System::Guid guid);
	};

	[Services::SqlDatabaseTableAttribute("account_admins")]
	public ref class AccountAdminsDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType, AccountClassesDbScheme
	{
	public: [Services::SqlDatabaseFieldAttribute("account_guid")]		property System::String^ account_guid;
	public: [Services::SqlDatabaseFieldAttribute("username")]			property System::String^ username;
	public: [Services::SqlDatabaseFieldAttribute("age")]				property System::String^ age;
	public: [Services::SqlDatabaseFieldAttribute("gender")]				property System::String^ gender;
	public: [Services::SqlDatabaseFieldAttribute("permissions")]		property System::String^ permissions;

		  AccountAdminsDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, System::String^ p4, System::String^ p5)
		  { this->account_guid = p1;	this->username = p2;	this->age = p3;	this->gender = p4;	this->permissions = p5; }
		  AccountAdminsDbScheme(System::Void)
		  { this->account_guid = "";	this->username = "";	this->age = "";	this->gender = "";	this->permissions = ""; }

		  virtual ~AccountAdminsDbScheme(System::Void) { delete account_guid, username, age, gender, permissions; }
		  static Models::AccountAdminModel^ cast_to_model(AccountAdminsDbScheme^ scheme);
		  static AccountAdminsDbScheme^ cast_to_scheme(Models::AccountAdminModel^ model, System::Guid guid);
	};
}