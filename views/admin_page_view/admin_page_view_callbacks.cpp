#include "admin_page_view.h"

using namespace Views;

generic <class TEnum> TEnum AdminPageView::convert_to_enum(System::String^ value)
{
	return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
}

System::Void AdminPageView::set_tabs_limition(System::Void)
{
	Models::AccountAdminModel^ admin_model = nullptr;
	try { admin_model = safe_cast<Models::AccountAdminModel^>(this->service_account_manager->AccountToken.AccountModel); }
	catch (System::Exception^) { MessageBox::Show("Невозможно установить ограничения", "Ошибка"); }

	this->admin_page_garage->Enabled = false;
	this->admin_page_clients->Enabled = false;

	if (admin_model->Permissions == Models::AccountModelPermissions::AccountList
		|| admin_model->Permissions == Models::AccountModelPermissions::FullPermission) 
		this->admin_page_clients->Enabled = true;
	
	
	if (admin_model->Permissions == Models::AccountModelPermissions::FullPermission
		|| admin_model->Permissions == Models::AccountModelPermissions::CarGarage) 
		this->admin_page_garage->Enabled = true;
}

System::Void AdminPageView::admin_button_upd_Click(System::Object^ sender, System::EventArgs^ e)
{
	List<DepotManager::CarGarageItems>^ car_list = this->service_depot_manager->get_all_cars();
	this->admin_listview_carlist->FullRowSelect = true;
	this->admin_listview_carlist->Items->Clear();

	if (car_list == nullptr || car_list->Count <= 0)
	{ MessageBox::Show("Невозможно получить список машин", "Ошибка"); return; }

	for each (auto item in car_list)
	{
		ListViewItem^ list_item = gcnew ListViewItem(item.Guid.ToString());
		list_item->SubItems->Add(item.CarClass->Name);
		list_item->SubItems->Add(item.CarModel->CarType.ToString());
		list_item->SubItems->Add(item.CarModel->CarColor.ToString());

		list_item->SubItems->Add(item.CarModel->CarSpeed.ToString());
		list_item->SubItems->Add(item.CarCount.ToString());
		this->admin_listview_carlist->Items->Add(list_item);
	}
}

System::Void AdminPageView::admin_button_caradd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::Int32 car_count = System::Decimal::ToInt32(this->admin_numeric_carcount->Value);
	System::Int32 car_speed = System::Decimal::ToInt32(this->admin_numeric_carspeed->Value);

	Models::CarModelTypes car_type;
	switch(this->admin_combobox_cartype->SelectedIndex)
	{
	case 0: car_type = Models::CarModelTypes::CarTypeEconom; break;
	case 1: car_type = Models::CarModelTypes::CarTypeChild; break;
	case 2: car_type = Models::CarModelTypes::CarTypePremium; break;
	}

	Models::CarModelColor car_color;
	switch (this->admin_combobox_carcolor->SelectedIndex) 
	{
	case 0: car_color = Models::CarModelColor::CarColorBlack; break;
	case 1: car_color = Models::CarModelColor::CarColorWhite; break;
	case 2: car_color = Models::CarModelColor::CarColorRed; break;
	case 3: car_color = Models::CarModelColor::CarColorYellow; break;
	}

	System::Boolean car_add_check(true);
	switch (this->admin_combobox_carclass->SelectedIndex) 
	{
	case 0:;
		Models::CarLightModel^ light_model;
		light_model = gcnew Models::CarLightModel(car_type, car_color, car_speed);
		car_add_check = this->service_depot_manager->add_car_model<Models::CarLightModel^>(light_model, car_count);
		break;
	case 1:;
		Models::CarHeavyModel^ heavy_model;
		heavy_model = gcnew Models::CarHeavyModel(car_type, car_color, car_speed);
		car_add_check = this->service_depot_manager->add_car_model<Models::CarHeavyModel^>(heavy_model, car_count);
		break;
	}
	if (car_add_check != true) { MessageBox::Show("Невозможно добавить машину(ы)", "Ошибка"); return; }
	this->admin_button_upd_Click(sender, e);
	MessageBox::Show("Машина(ы) успешно добавлены", "Готово"); return;
}

System::Void AdminPageView::admin_button_cardelete_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->admin_listview_carlist->SelectedItems->Count > 0)
	{
		System::Guid carmodel_guid;
		try { carmodel_guid = System::Guid::Parse(this->admin_listview_carlist->SelectedItems[0]->Text); }
		catch (System::Exception^ error) { MessageBox::Show("Данные повреждены", "Ошибка"); return; }

		if (!this->service_depot_manager->delete_car_model_by_guid(carmodel_guid))
		{ MessageBox::Show("Невозможно удалить машину", "Ошибка"); return; }

		this->admin_button_upd_Click(sender, e);
		MessageBox::Show("Машина успешно удалена", "Готово");
	}
	else MessageBox::Show("Выберите строку с машиной", "Ошибка");
}

System::Void AdminPageView::admin_button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->admin_listview_accounts->SelectedItems->Count > 0)
	{
		System::Guid account_guid;
		Services::AccountManagerToken::AccountManagerType account_type_new;
		try {
			account_guid = System::Guid::Parse(this->admin_listview_accounts->SelectedItems[0]->Text);
			account_type_new = this->convert_to_enum<Services::AccountManagerToken::AccountManagerType>(
				this->admin_listview_accounts->SelectedItems[0]->SubItems[1]->Text);
		}
		catch (System::Exception^) { MessageBox::Show("Данные повреждены", "Ошибка"); return; }
		
		System::Nullable<System::Boolean> check = this->service_account_manager->get_account_status(account_guid);
		if (check.HasValue != true) { MessageBox::Show("Данные повреждены", "Ошибка"); return; }
		if (check.Value == true) { MessageBox::Show("Аккаунт активен - недоступно", "Ошибка"); return; }

		if (!this->service_account_manager->delete_account(account_guid))
		{ MessageBox::Show("Невозможно удалить аккаунт", "Ошибка"); return; }

		MessageBox::Show("Аккаунт успешно удален", "Готово");
	}
	else MessageBox::Show("Выберите строку с аккаунтом", "Ошибка");
}

System::Void AdminPageView::admin_button_refresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	Generic::List<AccountManager::AccountInfo>^ account_list = this->service_account_manager->AccountList;
	if (account_list == nullptr || account_list->Count <= 0)
	{ MessageBox::Show("Возникла ошибка при обновлении", "Уведомление"); return; }

	this->admin_listview_accounts->Items->Clear();
	this->admin_listview_accounts->FullRowSelect = true;

	for each (auto item in account_list) 
	{
		if (item.Type == Services::AccountManagerToken::AccountManagerType::Admin) continue;

		ListViewItem^ list_item = gcnew ListViewItem(item.Guid.ToString());
		list_item->SubItems->Add(item.Type.ToString());
		list_item->SubItems->Add(item.State.ToString());
		admin_listview_accounts->Items->Add(list_item);
	}

	MessageBox::Show("Данные обновлены", "Уведомление");
}

System::Void AdminPageView::admin_button_accountinfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->admin_listview_accounts->SelectedItems->Count > 0)
	{
		System::Guid account_guid;
		Services::AccountManagerToken::AccountManagerType account_type_new;
		try {
			account_guid = System::Guid::Parse(this->admin_listview_accounts->SelectedItems[0]->Text);
			account_type_new = this->convert_to_enum<Services::AccountManagerToken::AccountManagerType>(
				this->admin_listview_accounts->SelectedItems[0]->SubItems[1]->Text);
		}
		catch (System::Exception^ error) { MessageBox::Show("Данные повреждены", "Ошибка"); return; }

		Models::AccountBaseModel^ model = nullptr;
		switch (account_type_new)
		{
		case Services::AccountManagerToken::AccountManagerType::Client:;

			Services::AccountClientsDbScheme^ client_scheme;
			client_scheme = this->service_account_manager->get_account_scheme<Services::AccountClientsDbScheme^>(account_guid); 
			if (client_scheme == nullptr) { MessageBox::Show("Не удалось сформировать модель", "Ошибка"); return; }

			model = Services::AccountClientsDbScheme::cast_to_model(client_scheme);	break;

		case Services::AccountManagerToken::AccountManagerType::Driver:;

			Services::AccountDriversDbScheme^ driver_scheme;
			driver_scheme = this->service_account_manager->get_account_scheme<Services::AccountDriversDbScheme^>(account_guid);
			if (driver_scheme == nullptr) { MessageBox::Show("Не удалось сформировать модель", "Ошибка"); return; }
			
			model = Services::AccountDriversDbScheme::cast_to_model(driver_scheme);	break;	
		}
		
		Windows::Forms::Form^ form = gcnew Views::AdminDetailsView(model, account_guid, account_type_new);
		form->ShowDialog();
	}
	else MessageBox::Show("Выберите строку с аккаунтом", "Ошибка");
}

System::Void AdminPageView::account_list_initialize(System::Void)
{
	this->admin_listview_account->FullRowSelect = true;
	this->admin_listview_account->Items->Clear();

	ListViewItem^ list_item = gcnew ListViewItem("Тип аккаунта");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountType.ToString());
	this->admin_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Аккаунт Guid");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountGuid.ToString());
	this->admin_listview_account->Items->Add(list_item);

	Models::AccountAdminModel^ account_model = nullptr;
	try {
		account_model = safe_cast<Models::AccountAdminModel^>(this->service_account_manager
			->AccountToken.AccountModel);
	}
	catch (System::Exception^) { MessageBox::Show("Невозможно определить модель аккаунта", "Ошибка"); return; }

	list_item = gcnew ListViewItem("Возраст");
	list_item->SubItems->Add(account_model->Age.ToString());
	this->admin_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Пол");
	list_item->SubItems->Add(account_model->Gender.ToString());
	this->admin_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Имя");
	list_item->SubItems->Add(account_model->Username);
	this->admin_listview_account->Items->Add(list_item);
}

System::Void AdminPageView::admin_button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	Models::AccountAdminModel^ current_model = safe_cast<Models::AccountAdminModel^>(
		this->service_account_manager->AccountToken.AccountModel);

	System::Int32 age_field = this->admin_checkbox_age->Checked ? Decimal::ToInt32(this->admin_numeric_age->Value)
		: current_model->Age;

	System::String^ username_field = this->admin_checkbox_username->Checked ?
		this->admin_textbox_username->Text : current_model->Username;
	if (username_field == System::String::Empty) { MessageBox::Show("Неверный формат имени", "Ошибка"); return; }

	Models::AccountModelGender gender_field;
	if (this->admin_checkbox_gender->Checked)
	{
		switch (this->admin_combobox_gender->SelectedIndex)
		{
		case 0: gender_field = Models::AccountModelGender::MaleGender; break;
		case 1: gender_field = Models::AccountModelGender::FemaleGender; break;
		}
	}
	else gender_field = current_model->Gender;

	Models::AccountAdminModel^ model = gcnew Models::AccountAdminModel(
		username_field, age_field, gender_field, current_model->Permissions);

	System::Boolean update_check = this->service_account_manager->update_account(model);
	if (update_check != true) { MessageBox::Show("Не удалось обновить данные аккаунта", "Ошибка"); return; }

	MessageBox::Show("Данные успешно обновлены", "Готово");
	this->account_list_initialize();
}

System::Void AdminPageView::admin_button_logout_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы уверены?", "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question) 
		== ::DialogResult::Yes)
	{
		System::Boolean logout_check = this->service_account_manager->sign_out_account();
		this->Close();
	}
}