#include "authorization_view.h"

using namespace Views;

System::Void AuthorizationView::clear_all_textboxes(System::Void) 
{
	for (int i = 0; i < this->page_list->Controls->Count; i++) 
	{
		Control^ check_list = this->page_list->Controls[i];
		for each (Control ^ item in check_list->Controls)
		{
			try { TextBox^ textbox = safe_cast<TextBox^>(item); textbox->Clear(); }
			catch (System::Exception^ error) { continue; }
		}
	}
}

System::Void AuthorizationView::page2_button_registration_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ login_field = this->page2_textbox_login->Text;
	System::String^ password_field = this->page2_textbox_password->Text;
	System::String^ username_field = this->page2_textbox_username->Text;

	System::UInt32 age_field = System::Decimal::ToUInt32(this->page2_numeric_age->Value);
	Models::AccountModelGender gender_field;

	if (this->page2_combobox_gender->SelectedIndex == 0) gender_field = Models::AccountModelGender::MaleGender;
	else gender_field = Models::AccountModelGender::FemaleGender;

	System::Boolean registration_check(true);
	Windows::Forms::Form^ view_preparation = nullptr;

	switch (this->page2_tabcontrol_info->SelectedIndex)
	{
	case 0: {
		System::Guid bank_card_number = System::Guid::Empty;
		try { bank_card_number = System::Guid::Parse(this->pageclient_textbox_bankcard->Text); }
		catch (System::Exception^ error) { MessageBox::Show("Номер банковской карты невалиден", "Ошибка заполнения"); return; }

		Models::AccountClientModel^ model = gcnew Models::AccountClientModel(
			username_field, age_field, gender_field, bank_card_number);

		registration_check = this->account_manager->registration_account<Models::AccountClientModel^>(
			login_field, password_field, model);
		view_preparation = gcnew Views::ClientPageView();
	}	break;
	case 1: {
		System::Guid bank_card_number = System::Guid::Empty;
		System::Guid licence_number = System::Guid::Empty;
		try { 
			bank_card_number = System::Guid::Parse(this->pagedriver_textbox_bankcard->Text);
			licence_number = System::Guid::Parse(this->pagedriver_textbox_licence->Text);
		}
		catch (System::Exception^ error) { 
			MessageBox::Show("Номер банковской карты или лицензии невалиден", "Ошибка заполнения"); return; }

		Models::AccountDriverModel^ model = gcnew Models::AccountDriverModel(
			username_field, age_field, gender_field, licence_number, bank_card_number);

		registration_check = this->account_manager->registration_account<Models::AccountDriverModel^>(
			login_field, password_field, model);
		view_preparation = gcnew Views::DriverPageView();
	}	break;
	case 2: {
		Models::AccountModelPermissions model_permission;
		switch (pageadmin_combobox_permissions->SelectedIndex)
		{
		case 0: model_permission = Models::AccountModelPermissions::FullPermission; break;
		case 1: model_permission = Models::AccountModelPermissions::CarGarage; break;
		case 2: model_permission = Models::AccountModelPermissions::OrderList; break;
		case 3: model_permission = Models::AccountModelPermissions::AccountList; break;
		}
		Models::AccountAdminModel^ model = gcnew Models::AccountAdminModel(
			username_field, age_field, gender_field, model_permission);

		registration_check = this->account_manager->registration_account<Models::AccountAdminModel^>(
			login_field, password_field, model);
		view_preparation = gcnew Views::AdminPageView();
	}	break;
	}

	if(registration_check != true) { MessageBox::Show("Невозможно зарегистрироваться", "Ошибка"); return; }
	this->clear_all_textboxes();
	/*this->Hide();	*/view_preparation->Show();
	account_manager->sign_out_account();
}