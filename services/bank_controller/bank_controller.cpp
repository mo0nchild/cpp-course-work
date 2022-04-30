#include "bank_controller.h"

using namespace Services;

System::Guid BankController::AccountGuid::get(System::Void)
{
	if (this->bank_account != nullptr) return this->bank_account->AccountGuid;
	return System::Guid::Empty;
}

System::Int32 BankController::AccountMoney::get(System::Void) 
{
	if (this->bank_account != nullptr) return this->bank_account->Money;
	return System::Int32(0);
}

Manager::IServiceBase::ServiceQuery^ BankController::service_query_handler(System::TimeSpan work_time)
{
	Manager::IServiceBase::ServiceQuery^ service_query = gcnew Manager::IServiceBase::ServiceQuery();

	service_query->Message = "Message from Bank Controller";
	service_query->ServiceType = this->GetType();
	service_query->State = this->ServiceState;

	return service_query;
}

System::Boolean BankController::transfer_money(System::Guid payee_guid, System::Int32 money)
{
	if (this->bank_account == nullptr || money <= 0) return false;
	
	List<IDatabaseManager::KeyValuePair^>^ receiver_key = gcnew List<IDatabaseManager::KeyValuePair^>();
	receiver_key->Add(gcnew IDatabaseManager::KeyValuePair("account_guid", payee_guid.ToString()));

	auto receiver_items = this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()->get_database_data(receiver_key, false);
	if (receiver_items == nullptr || receiver_items->Count <= 0) { return false; }

	if (this->take_money(money) != true) return false;

	BankAccountDbScheme^ receiver_model = safe_cast<BankAccountDbScheme^>(receiver_items[0]);
	System::Int32 receiver_money(0);
	System::Boolean transfer_checker(true);

	try { receiver_money = System::UInt32::Parse(receiver_model->account_money); }
	catch (System::Exception^ error) { this->put_money(money); return false; }

	receiver_model->account_money = System::Int32(receiver_money + money).ToString();

	System::Boolean update_receiver = this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->update_database_date(receiver_model, gcnew IDatabaseManager::KeyValuePair("account_guid", receiver_model->account_guid));
		
	if (update_receiver != true) { this->put_money(money); return false; }
	return true;
}

System::Boolean BankController::create_bank_account(System::Guid account_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("account_guid", account_guid.ToString()));

	auto request_items = this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->get_database_data(request_key, false);
	if (request_items != nullptr && request_items->Count > 0) return false;

	BankAccountDbScheme^ account_model = gcnew BankAccountDbScheme();
	account_model->account_guid = account_guid.ToString();
	account_model->account_money = System::Int32(0).ToString();
	account_model->account_marker = System::Boolean(true).ToString();

	if (!this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()->send_database_data(account_model)) return false;
	return true;
}

BankAccountDbScheme^ BankController::account_check(System::Guid account_guid)
{
	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("account_guid", account_guid.ToString()));

	auto request_items = this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->get_database_data(request_key, false);
	if (request_items == nullptr || request_items->Count <= 0) return nullptr;
	return safe_cast<BankAccountDbScheme^>(request_items[0]);
}

System::Boolean BankController::take_money(System::Int32 money)
{
	if (this->bank_account == nullptr) return false;
	BankAccountDbScheme^ item = this->account_check(this->AccountGuid);
	if (item == nullptr) return false;

	System::Int32 account_money(0);
	try { account_money = System::Int32::Parse(item->account_money); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	if (account_money - money < 0) return false;

	this->bank_account->Money = System::Int32(account_money - money);
	item->account_money = this->bank_account->Money.ToString();

	if(!this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("account_guid", item->account_guid))) return false;

	return true;
}

System::Boolean BankController::put_money(System::Int32 money)
{
	if (this->bank_account == nullptr) return false;
	BankAccountDbScheme^ item = this->account_check(this->AccountGuid);
	if (item == nullptr) return false;

	System::Int32 account_money(0);
	try { account_money = System::Int32::Parse(item->account_money); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return false; }

	this->bank_account->Money = System::Int32(account_money + money);
	item->account_money = this->bank_account->Money.ToString();
	
	if (!this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->update_database_date(item, gcnew IDatabaseManager::KeyValuePair("account_guid", item->account_guid))) return false;

	return true;
}

System::Boolean BankController::load_bank_account(System::Guid account_guid)
{
	BankAccountDbScheme^ item = this->account_check(account_guid);
	if (item != nullptr) {
		this->bank_account = gcnew BankController::BankAccount();
		try {
			this->bank_account->Money = System::UInt32::Parse(item->account_money);
			this->bank_account->AccountGuid = System::Guid::Parse(item->account_guid);
		}
		catch (System::Exception^ error) { this->bank_account = nullptr; return false; }
	}
	else return false;

	return true;
}

Generic::List<System::Guid>^ BankController::get_bank_accounts(System::Void)
{
	List<IDatabaseManager::KeyValuePair^>^ request_key = gcnew List<IDatabaseManager::KeyValuePair^>();
	request_key->Add(gcnew IDatabaseManager::KeyValuePair("account_marker", "True"));

	auto request_items = this->service_sql_manager->set_scheme_struct<BankAccountDbScheme^>()
		->get_database_data(request_key, false);
	if (request_items == nullptr || request_items->Count <= 0) return nullptr;
	
	List<System::Guid>^ result_list = gcnew List<System::Guid>();
	for each (auto item in request_items) 
	{
		System::Guid item_guid;
		try { 
			BankAccountDbScheme^ scheme = safe_cast<BankAccountDbScheme^>(item);
			item_guid = System::Guid::Parse(scheme->account_guid);
		}
		catch (System::Exception^ error) { Console::WriteLine(error->Message); continue; }

		result_list->Add(item_guid);
	}

	return result_list;
}