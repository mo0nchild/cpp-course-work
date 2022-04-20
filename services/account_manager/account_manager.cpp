#include "account_manager.h"

using namespace Services;

generic <class TEnum> TEnum convert_to_enum_cool(System::String^ value)
{
	return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
}

List<AccountManager::AccountInfo>^ AccountManager::AccountList::get(System::Void) 
{  	List<IDatabaseManager::KeyValuePair^>^ request_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_state", "True"));
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_state", "False"));

	List<IDatabaseManager::RequestRow^>^ response_list = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->get_database_data(request_list, true);
	if (response_list == nullptr)
		throw gcnew AccountManagerTokenException(AccountManager::typeid, "AccountList::get DB error");

	List<AccountManager::AccountInfo>^ result = gcnew List<AccountManager::AccountInfo>();
	for each (IDatabaseManager::RequestRow ^ item in response_list)
	{
		AccountAuthenticationDbScheme^ account_scheme = (AccountAuthenticationDbScheme^)item;
		try {
			result->Add(AccountManager::AccountInfo{ System::Guid::Parse(account_scheme->account_guid),
				account_scheme->login, convert_to_enum_cool<AccountManagerToken::AccountManagerType>(account_scheme->type),
				System::Boolean::Parse(account_scheme->state)});
		}
		catch (System::Exception^ error) { Console::WriteLine(error->Message); }
	}

	return result;
}

generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
	System::Boolean AccountManager::registration_account(System::String^ login, System::String^ password,
	TAccountModel account_model)
{
	List<IDatabaseManager::KeyValuePair^>^ request_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_login", login));

	List<IDatabaseManager::RequestRow^>^ response_list = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->get_database_data(request_list, false);
	if (response_list == nullptr || response_list->Count > 0) return false;

	AccountManagerToken::AccountManagerType account_type;
	if (TAccountModel::typeid->Name == "AccountAdminModel") account_type = AccountManagerToken::AccountManagerType::Admin;
	else if (TAccountModel::typeid->Name == "AccountDriverModel") account_type = AccountManagerToken::AccountManagerType::Driver;
	else if (TAccountModel::typeid->Name == "AccountClientModel") account_type = AccountManagerToken::AccountManagerType::Client;
	else return false;

	System::Guid account_guid = System::Guid::NewGuid();
	AccountAuthenticationDbScheme^ registration_list = gcnew AccountAuthenticationDbScheme(
		account_guid.ToString(), login, password, account_type.ToString(), true.ToString());

	System::Boolean registration_request = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->send_database_data(registration_list);
	if (registration_request != true) return false;

	System::Boolean add_account_request;
	switch (account_type) 
	{
	case AccountManagerToken::AccountManagerType::Admin:
	{
		Models::AccountAdminModel^ cast_model = (Models::AccountAdminModel^)account_model;
		AccountAdminsDbScheme^ account_scheme = AccountAdminsDbScheme::cast_to_scheme(cast_model, account_guid);

		add_account_request = this->service_sql_manager->set_scheme_struct<AccountAdminsDbScheme^>()
			->send_database_data(account_scheme);
	}
		break;
	case AccountManagerToken::AccountManagerType::Driver:
	{
		Models::AccountDriverModel^ cast_model = (Models::AccountDriverModel^)account_model;
		AccountDriversDbScheme^ account_scheme = AccountDriversDbScheme::cast_to_scheme(cast_model, account_guid);
		
		add_account_request = this->service_sql_manager->set_scheme_struct<AccountDriversDbScheme^>()
			->send_database_data(account_scheme);
	}
		break;
	case AccountManagerToken::AccountManagerType::Client:
	{
		Models::AccountClientModel^ cast_model = (Models::AccountClientModel^)account_model;
		AccountClientsDbScheme^ account_scheme = AccountClientsDbScheme::cast_to_scheme(cast_model, account_guid);

		add_account_request = this->service_sql_manager->set_scheme_struct<AccountClientsDbScheme^>()
			->send_database_data(account_scheme);
	}
		break;
	}
	
	if (add_account_request != true) return false;
	this->AccountToken = AccountManagerToken(account_type, account_model, account_guid);
	this->account_initialized = true;

	return true;
}

System::Boolean AccountManager::authorization_account(System::String^ login, System::String^ password)
{
	List<IDatabaseManager::KeyValuePair^>^ request_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_login", login));
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_password", password));

	List<IDatabaseManager::RequestRow^>^ response_list = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->get_database_data(request_list, false); // <------ если шо
	if (response_list == nullptr || response_list->Count != 1) return false;

	AccountAuthenticationDbScheme^ account_auth = safe_cast<AccountAuthenticationDbScheme^>(response_list[0]);
	try { if (System::Boolean::Parse(account_auth->state) == true) throw gcnew System::Exception("allready login"); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	System::Guid account_guid = System::Guid::Empty;
	AccountManagerToken::AccountManagerType account_type;

	try { 
		account_guid = System::Guid::Parse(account_auth->account_guid); 
		account_type = convert_to_enum_cool<AccountManagerToken::AccountManagerType>(account_auth->type);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();
	List<IDatabaseManager::RequestRow^>^ response_obj = gcnew List<IDatabaseManager::RequestRow^>();
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("account_guid", account_auth->account_guid));

	Models::AccountBaseModel^ account_model = nullptr;
	switch (account_type)
	{
	case AccountManagerToken::AccountManagerType::Admin:
		
		response_obj = this->service_sql_manager->set_scheme_struct<AccountAdminsDbScheme^>()
			->get_database_data(request_key, true);
		if (response_obj == nullptr || response_obj->Count != 1) return false;
		account_model = AccountAdminsDbScheme::cast_to_model((AccountAdminsDbScheme^)response_obj[0]);
	break;
	case AccountManagerToken::AccountManagerType::Driver:
		response_obj = this->service_sql_manager->set_scheme_struct<AccountDriversDbScheme^>()
			->get_database_data(request_key, true);
		if (response_obj == nullptr || response_obj->Count != 1) return false;
		account_model = AccountDriversDbScheme::cast_to_model((AccountDriversDbScheme^)response_obj[0]);
	break;
	case AccountManagerToken::AccountManagerType::Client: 
		response_obj = this->service_sql_manager->set_scheme_struct<AccountClientsDbScheme^>()
			->get_database_data(request_key, true);
		if (response_obj == nullptr || response_obj->Count != 1) return false;
		account_model = AccountClientsDbScheme::cast_to_model((AccountClientsDbScheme^)response_obj[0]);
	break;
	}

	if (account_model == nullptr) return false;

	account_auth->state = true.ToString();
	System::Boolean account_state_update = this->service_sql_manager->set_scheme_struct<AccountAuthenticationDbScheme^>()
		->update_database_date(account_auth, gcnew IDatabaseManager::KeyValuePair("account_guid", account_auth->account_guid));
	if (account_state_update != true) return false;

	this->AccountToken = AccountManagerToken(account_type, account_model, account_guid);
	this->account_initialized = true;
	return true;
}

System::Boolean AccountManager::sign_out_account(System::Void)
{
	if (this->account_initialized != true) return false;
	List<IDatabaseManager::KeyValuePair^>^ request_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_list->Add(gcnew IDatabaseManager::KeyValuePair("account_guid", this->AccountToken.AccountGuid.ToString()));

	List<IDatabaseManager::RequestRow^>^ response_list = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->get_database_data(request_list, false);
	
	if (response_list == nullptr || response_list->Count != 1) return false;
	AccountAuthenticationDbScheme^ account_auth = safe_cast<AccountAuthenticationDbScheme^>(response_list[0]);

	account_auth->state = false.ToString();
	System::Boolean account_state_update = this->service_sql_manager->set_scheme_struct<AccountAuthenticationDbScheme^>()
		->update_database_date(account_auth, gcnew IDatabaseManager::KeyValuePair("account_guid", account_auth->account_guid));
	if (account_state_update != true) return false;

	AccountManagerToken::AccountManagerType account_enum_type;
	try {
		account_enum_type = convert_to_enum_cool<AccountManagerToken::AccountManagerType>(account_auth->type);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }
	this->account_initialized = false;
	this->AccountToken = AccountManagerToken(account_enum_type, nullptr, System::Guid::Empty);
	return true;
}

generic <class TAccountModel> where TAccountModel : Models::AccountBaseModel
	System::Boolean AccountManager::update_account(TAccountModel account_model)
{
	if (this->IsInitialized != true) return false;
	IDatabaseManager::KeyValuePair^ upload_key = gcnew IDatabaseManager::KeyValuePair(
		"account_guid", this->AccountToken.AccountGuid.ToString());
	switch (this->AccountToken.AccountType)
	{
	case AccountManagerToken::AccountManagerType::Admin:;
	{
		if (TAccountModel::typeid->Name != "AccountAdminModel") return false;
		IDatabaseManager::RequestRow^ upload_model = AccountAdminsDbScheme::cast_to_scheme(
			(Models::AccountAdminModel^)account_model, this->AccountToken.AccountGuid);

		System::Boolean upload_check = this->service_sql_manager->set_scheme_struct<AccountAdminsDbScheme^>()
			->update_database_date(upload_model, upload_key);
		if (upload_check != true) return false;
	}
		break;
	case AccountManagerToken::AccountManagerType::Client:;
	{
		if (TAccountModel::typeid->Name != "AccountClientModel") return false;
		IDatabaseManager::RequestRow^ upload_model = AccountClientsDbScheme::cast_to_scheme(
			(Models::AccountClientModel^)account_model, this->AccountToken.AccountGuid);

		System::Boolean upload_check = this->service_sql_manager->set_scheme_struct<AccountClientsDbScheme^>()
			->update_database_date(upload_model, upload_key);
		if (upload_check != true) return false;

	}
		break;
	case AccountManagerToken::AccountManagerType::Driver:;
	{
		if (TAccountModel::typeid->Name != "AccountDriverModel") return false;
		IDatabaseManager::RequestRow^ upload_model = AccountDriversDbScheme::cast_to_scheme(
			(Models::AccountDriverModel^)account_model, this->AccountToken.AccountGuid);
		
		System::Boolean upload_check = this->service_sql_manager->set_scheme_struct<AccountDriversDbScheme^>()
			->update_database_date(upload_model, upload_key);
		if (upload_check != true) return false;
	}
		break;
	}

	this->AccountToken = AccountManagerToken(AccountToken.AccountType, account_model, AccountToken.AccountGuid);
	return true;
}

System::Boolean AccountManager::delete_account(System::Void) 
{
	if (this->IsInitialized != true) return false;
	IDatabaseManager::KeyValuePair^ request_key = gcnew IDatabaseManager::KeyValuePair("account_guid", 
		this->AccountToken.AccountGuid.ToString());

	List<IDatabaseManager::KeyValuePair^>^ request_list = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_list->Add(request_key);
	List<IDatabaseManager::RequestRow^>^ response_list = this->service_sql_manager
		->set_scheme_struct<AccountAuthenticationDbScheme^>()->get_database_data(request_list, false);

	if (response_list == nullptr || response_list->Count != 1) return false;
	AccountAuthenticationDbScheme^ account_auth = safe_cast<AccountAuthenticationDbScheme^>(response_list[0]);

	AccountManagerToken::AccountManagerType account_enum_type;
	try {
		account_enum_type = convert_to_enum_cool<AccountManagerToken::AccountManagerType>(account_auth->type);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }
	switch (account_enum_type)
	{
	case AccountManagerToken::AccountManagerType::Admin:
		if (this->service_sql_manager->set_scheme_struct<AccountAdminsDbScheme^>()
			->delete_database_data(request_key) != true) return false;
		break;
	case AccountManagerToken::AccountManagerType::Driver:
		if (this->service_sql_manager->set_scheme_struct<AccountDriversDbScheme^>()
			->delete_database_data(request_key) != true) return false;
		break;
	case AccountManagerToken::AccountManagerType::Client:
		if (this->service_sql_manager->set_scheme_struct<AccountClientsDbScheme^>()
			->delete_database_data(request_key) != true) return false;
		break;
	}

	this->service_sql_manager->set_scheme_struct<AccountAuthenticationDbScheme^>()
		->delete_database_data(request_key);
	
	this->account_initialized = false;
	this->AccountToken = AccountManagerToken(account_enum_type, nullptr, System::Guid::Empty);
	
	return true;
}
