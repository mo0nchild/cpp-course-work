#include "account_manager_scheme.h"

using namespace Services;

generic <class TEnum> TEnum fixedconvert_to_enum(System::String^ value)
{
	return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
}

Models::AccountClientModel^ AccountClientsDbScheme::AccountClientsDbScheme::cast_to_model(AccountClientsDbScheme^ scheme)
{
	Models::AccountClientModel^ account_model = nullptr;
	try{
		account_model = gcnew Models::AccountClientModel(scheme->username, System::UInt32::Parse(scheme->age),
			fixedconvert_to_enum<Models::AccountModelGender>(scheme->gender), scheme->bank_card);
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return nullptr; }
	return account_model;
}

Models::AccountAdminModel^ AccountAdminsDbScheme::cast_to_model(AccountAdminsDbScheme^ scheme)
{
	Models::AccountAdminModel^ account_model = nullptr;
	try {
		account_model = gcnew Models::AccountAdminModel(scheme->username, System::UInt32::Parse(scheme->age),
			fixedconvert_to_enum<Models::AccountModelGender>(scheme->gender),
			fixedconvert_to_enum<Models::AccountModelPermissions>(scheme->permissions));
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return nullptr; }
	return account_model;
}

Models::AccountDriverModel^ AccountDriversDbScheme::cast_to_model(AccountDriversDbScheme^ scheme)
{
	Models::AccountDriverModel^ account_model = nullptr;
	try {
		account_model = gcnew Models::AccountDriverModel(scheme->username, System::UInt32::Parse(scheme->age),
			fixedconvert_to_enum<Models::AccountModelGender>(scheme->gender),
			System::Guid::Parse(scheme->licence), System::UInt16::Parse(scheme->experience));
	}
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return nullptr; }
	return account_model;
}

AccountDriversDbScheme^ AccountDriversDbScheme::cast_to_scheme(Models::AccountDriverModel^ model, System::Guid guid)
{
	AccountDriversDbScheme^ account_scheme = gcnew AccountDriversDbScheme();

	account_scheme->account_guid = guid.ToString();
	account_scheme->age = model->Age.ToString();
	account_scheme->username = model->Username;
	account_scheme->gender = model->Gender.ToString();
	account_scheme->experience = model->Experience.ToString();
	account_scheme->licence = model->Licence.ToString();

	return account_scheme;
}

AccountAdminsDbScheme^ AccountAdminsDbScheme::cast_to_scheme(Models::AccountAdminModel^ model, System::Guid guid)
{
	AccountAdminsDbScheme^ account_scheme = gcnew AccountAdminsDbScheme();
	account_scheme->account_guid = guid.ToString();
	account_scheme->username = model->Username;
	account_scheme->age = model->Age.ToString();
	account_scheme->gender = model->Gender.ToString();
	account_scheme->permissions = model->Permissions.ToString();

	return account_scheme;
}

AccountClientsDbScheme^ AccountClientsDbScheme::cast_to_scheme(Models::AccountClientModel^ model, System::Guid guid)
{
	AccountClientsDbScheme^ account_scheme = gcnew AccountClientsDbScheme();

	account_scheme->account_guid = guid.ToString();
	account_scheme->age = model->Age.ToString();
	account_scheme->username = model->Username;
	account_scheme->gender = model->Gender.ToString();
	account_scheme->bank_card = model->BankCard;

	return account_scheme;
}