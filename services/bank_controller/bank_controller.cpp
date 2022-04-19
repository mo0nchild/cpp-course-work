#include "bank_controller.h"

using namespace Services;

System::Guid BankController::AccountGuid::get(System::Void)
{
	return System::Guid::Empty;
}

System::UInt32 BankController::AccountMoney::get(System::Void) 
{
	return 0;
}

System::Boolean BankController::transfer_money(System::Guid payee_guid, System::UInt32 money)
{
	return true;
}

System::Boolean BankController::take_money(System::UInt32 money)
{
	return true;
}

System::Boolean BankController::put_money(System::UInt32 money)
{
	return true;
}

System::Boolean BankController::load_bank_account(System::Guid account_guid)
{
	return true;
}

Generic::List<System::Guid>^ BankController::get_bank_accounts(System::Void)
{
	return nullptr;
}