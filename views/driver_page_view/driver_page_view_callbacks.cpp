#include "driver_page_view.h"

using namespace Views;

generic <class TEnum> TEnum DriverPageView::convert_to_enum(System::String ^ value)
{
	return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
}

System::Void DriverPageView::driver_complex_close(System::Void)
{
	this->driver_textbox_status->Text = "";
	this->driver_button_status->Enabled = false;
	this->driver_button_rent->Enabled = true;
	this->driver_button_return->Enabled = false;
}

System::Void DriverPageView::driver_complex_open(System::Void)
{
	this->driver_textbox_status->Text = "? ????????";
	this->driver_button_status->Enabled = true;
	this->driver_button_rent->Enabled = false;
	this->driver_button_return->Enabled = true;
}

System::Void DriverPageView::driver_button_status_Click(System::Object^ sender, System::EventArgs^ e)
{
	Services::DriveComplexToken::DriverStateType new_driver_status;
	System::String^ new_driver_status_text = nullptr;

	switch (this->driver_combobox_status->SelectedIndex) 
	{
	case 0: 
		new_driver_status = Services::DriveComplexToken::DriverStateType::Ready; 
		new_driver_status_text = "?????"; break;
	case 1: new_driver_status = Services::DriveComplexToken::DriverStateType::Busy; 
		new_driver_status_text = "?????"; break;
	case 2: new_driver_status = Services::DriveComplexToken::DriverStateType::Idle; 
		new_driver_status_text = "? ????????"; break;
	}

	if (!this->service_depot_manager->update_drive_state(new_driver_status)) 
	{ MessageBox::Show("?? ??????? ???????? ??????", "??????"); return; }

	this->driver_textbox_status->Text = new_driver_status_text;
}

System::Void DriverPageView::driver_button_bankmoney_Click(System::Object^ sender, System::EventArgs^ e) 
{
	try {
		Models::AccountDriverModel^ account_model = safe_cast<Models::AccountDriverModel^>(
			this->service_account_manager->AccountToken.AccountModel);

		if (!this->service_bank_controller->load_bank_account(account_model->BankCard))
			throw gcnew Services::AccountManagerTokenException(ClientPageView::typeid, "cant load bank account");
	}
	catch (System::Exception^) { MessageBox::Show("?????????? ???????????? ? ??????????? ????????", "??????"); return; }

	MessageBox::Show(System::String::Concat("??????? ??????: ", this->service_bank_controller->AccountMoney), "??????");
}

System::Void DriverPageView::driver_button_accept_order_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->service_depot_manager->IsBuilded != true)
	{ MessageBox::Show("??? ?????? ????? ?????????? ??????", "??????"); return; }

	if (this->driver_listview_orders->SelectedItems->Count <= 0)
	{ MessageBox::Show("???????? ?????? ? ???????", "??????"); return; }

	System::String^ selected_order = this->driver_listview_orders->SelectedItems[0]->Text;
	System::Guid client_guid;

	try { client_guid = System::Guid::Parse(selected_order); }
	catch (System::Exception^) { MessageBox::Show("?????????? ????????? Guid ??????", "??????"); return; }

	System::Boolean accept_check(false);
	try {
		accept_check = this->service_order_controller->accept_request(client_guid,
			this->service_depot_manager->DriverGuid);
	}
	catch (Services::OrderControllerTokenException^) {}

	if (accept_check != true) MessageBox::Show("?????????? ??????? ?????", "??????");
	else {
		Windows::Forms::Form^ form = gcnew Views::DriverDialogView(this->service_depot_manager->CarModel);
		form->ShowDialog();
	}
}

System::Void DriverPageView::driver_button_update_orders_Click(System::Object^ sender, System::EventArgs^ e)
{
	List<Services::OrderControllerDbScheme^>^ order_list = this->service_order_controller->OrderList;
	if (order_list == nullptr) { MessageBox::Show("?????????? ???????? ?????? ???????", "??????"); return; }

	this->driver_listview_orders->FullRowSelect = true;
	this->driver_listview_orders->Items->Clear();
	for each (auto item in order_list)
	{
		ListViewItem^ list_item = gcnew ListViewItem(item->client_guid);
		list_item->SubItems->Add(item->car_class);
		list_item->SubItems->Add(item->car_type);

		list_item->SubItems->Add(item->address);
		list_item->SubItems->Add(item->date_time);

		this->driver_listview_orders->Items->Add(list_item);
	}
}

System::Void DriverPageView::driver_button_update_garage_Click(System::Object^ sender, System::EventArgs^ e)
{
	List<DepotManager::CarGarageItems>^ car_list = this->service_depot_manager->get_all_cars();
	if (car_list == nullptr) { MessageBox::Show("?????????? ???????? ?????? ?????", "??????"); return; }

	this->driver_listview_garage->FullRowSelect = true;
	this->driver_listview_garage->Items->Clear();

	for each (auto item in car_list)
	{
		ListViewItem^ list_item = gcnew ListViewItem(item.CarClass->Name);
		list_item->SubItems->Add(item.CarModel->CarType.ToString());
		list_item->SubItems->Add(item.CarModel->CarColor.ToString());

		list_item->SubItems->Add(item.CarModel->CarSpeed.ToString());
		list_item->SubItems->Add(item.CarCount.ToString());
		this->driver_listview_garage->Items->Add(list_item);
	}
}

System::Void DriverPageView::driver_button_rent_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->driver_listview_garage->SelectedItems->Count <= 0)
	{ MessageBox::Show("???????? ?????? ? ???????", "??????"); return; }

	if (this->service_depot_manager->IsBuilded)
	{ MessageBox::Show("?????? ??? ???????", "??????"); return; }

	auto selected_list = this->driver_listview_garage->SelectedItems[0]->SubItems;
	System::String^ car_class_string = selected_list[0]->Text;
	System::String^ car_type_string = selected_list[1]->Text;
	System::String^ car_color_string = selected_list[2]->Text;
	System::String^ car_speed_string = selected_list[3]->Text;

	System::UInt32 car_speed;
	Models::CarModelColor car_color;
	Models::CarModelTypes car_type;

	try {
		car_speed = System::UInt32::Parse(car_speed_string);
		car_color = this->convert_to_enum<Models::CarModelColor>(car_color_string);
		car_type = this->convert_to_enum<Models::CarModelTypes>(car_type_string);
	}
	catch (System::Exception^) { MessageBox::Show("?????????? ????????? ??????", "??????"); return; }

	System::Boolean rent_request(true);
	if (car_class_string == Models::CarLightModel::typeid->Name)
	{
		Models::CarLightModel^ model = gcnew Models::CarLightModel(car_type, car_color, car_speed);
		rent_request = this->service_depot_manager->rent_car_model<Models::CarLightModel^>(
			model, this->service_account_manager->AccountToken.AccountGuid);
	}
	else if (car_class_string == Models::CarHeavyModel::typeid->Name)
	{
		Models::CarHeavyModel^ model = gcnew Models::CarHeavyModel(car_type, car_color, car_speed);
		rent_request = this->service_depot_manager->rent_car_model<Models::CarHeavyModel^>(
			model, this->service_account_manager->AccountToken.AccountGuid);
	}
	else { MessageBox::Show("?????????? ?????????? ????? ??????", "??????"); return; }

	if (rent_request != true) { MessageBox::Show("?????? ?? ?????? ?????? ????????", "??????"); }
	else
	{
		MessageBox::Show("?????? ??????? ??????????", "??????");
		this->driver_complex_open();
	}
}

System::Void DriverPageView::driver_button_return_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!this->service_depot_manager->IsBuilded)
	{ MessageBox::Show("?????? ??? ?? ???????", "??????"); return; }

	if (!this->service_depot_manager->return_car_model()) MessageBox::Show("?????? ?? ??????? ????????", "??????");
	else
	{
		MessageBox::Show("?????? ?????????? ? ?????", "??????");
		this->driver_complex_close();
	}
}

System::Void DriverPageView::account_list_initialize(System::Void)
{
	this->driver_listview_account->FullRowSelect = true;
	this->driver_listview_account->Items->Clear();

	ListViewItem^ list_item = gcnew ListViewItem("??? ????????");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountType.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("??????? Guid");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountGuid.ToString());
	this->driver_listview_account->Items->Add(list_item);

	Models::AccountDriverModel^ account_model = nullptr;
	try {
		account_model = safe_cast<Models::AccountDriverModel^>(this->service_account_manager
			->AccountToken.AccountModel);
	}
	catch (System::Exception^) { MessageBox::Show("?????????? ?????????? ?????? ????????", "??????"); return; }

	list_item = gcnew ListViewItem("????? ?????????? ?????");
	list_item->SubItems->Add(account_model->BankCard.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("????? ????????");
	list_item->SubItems->Add(account_model->Licence.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("???????");
	list_item->SubItems->Add(account_model->Age.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("???");
	list_item->SubItems->Add(account_model->Gender.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("???");
	list_item->SubItems->Add(account_model->Username);
	this->driver_listview_account->Items->Add(list_item);
}

System::Void DriverPageView::driver_button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	Models::AccountDriverModel^ current_model = safe_cast<Models::AccountDriverModel^>(
		this->service_account_manager->AccountToken.AccountModel);

	System::Int32 age_field = this->driver_checkbox_age->Checked ? Decimal::ToInt32(this->driver_numeric_age->Value)
		: current_model->Age;

	System::String^ username_field = this->driver_checkbox_username->Checked ?
		this->driver_textbox_username->Text : current_model->Username;
	if (username_field == System::String::Empty) { MessageBox::Show("???????? ?????? ?????", "??????"); return; }

	Models::AccountModelGender gender_field;
	if (this->driver_checkbox_gender->Checked)
	{
		switch (this->driver_combobox_gender->SelectedIndex)
		{
		case 0: gender_field = Models::AccountModelGender::MaleGender; break;
		case 1: gender_field = Models::AccountModelGender::FemaleGender; break;
		}
	}
	else gender_field = current_model->Gender;

	System::Guid bankcard_field, licence_field;
	if (this->driver_checkbox_bankcard->Checked)
	{
		try { bankcard_field = System::Guid::Parse(this->driver_textbox_bankcard->Text); }
		catch (System::Exception^) { MessageBox::Show("???????? ?????? ?????????? ?????", "??????"); return; }

		if (!this->service_bank_controller->load_bank_account(bankcard_field))
		{ MessageBox::Show("?????????? ??????? ?? ??????", "??????"); return; }
	}
	else bankcard_field = current_model->BankCard;

	if (this->driver_checkbox_licence->Checked)
	{
		try { licence_field = System::Guid::Parse(this->driver_textbox_licence->Text); }
		catch (System::Exception^) { MessageBox::Show("???????? ?????? ????????", "??????"); return; }
	}
	else licence_field = current_model->Licence;

	Models::AccountDriverModel^ model = gcnew Models::AccountDriverModel(
		username_field, age_field, gender_field, licence_field, bankcard_field);

	System::Boolean update_check = this->service_account_manager->update_account(model);
	if (update_check != true) MessageBox::Show("?? ??????? ???????? ?????? ????????", "??????");

	MessageBox::Show("?????? ??????? ?????????", "??????");
	this->account_list_initialize();
}

System::Void DriverPageView::driver_button_bank_Click(System::Object^ sender, System::EventArgs^ e)
{
	Windows::Forms::Form^ bank_page = gcnew Views::BankSettingsView(this->service_bank_controller);
	bank_page->ShowDialog();
}

System::Void DriverPageView::driver_button_logout_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("?? ????????", "?????????????", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
		== ::DialogResult::Yes)
	{
		System::Boolean logout_check = this->service_account_manager->sign_out_account();
		if (this->service_depot_manager->IsBuilded) this->service_depot_manager->return_car_model();
		this->Close();
	}
}

System::Void DriverPageView::driver_button_complexinfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!this->service_depot_manager->IsBuilded) 
	{ MessageBox::Show("??? ?????? ????????? ??????", "??????"); return; }

	Windows::Forms::Form^ form = gcnew Views::DriverComplexView(this->service_depot_manager->CarModel,
		this->service_depot_manager->CarModelType);
	form->ShowDialog();
}