#include "client_page_view.h"

using namespace Views;

System::Void ClientPageView::order_request_callback(System::Boolean value)
{
	if (!this->service_order_controller->cancellation_order())
		MessageBox::Show("Произошла ошибка при отмене заказа", "Ошибка");

	this->order_proccess = false;
	MessageBox::Show("Состояние заказа: " + value.ToString(), "Готово");

	this->client_label_waiting->Text = "Состояние заказа";
	this->client_button_cancel->Enabled = false;
	this->client_button_order->Enabled = true;
}

System::Void ClientPageView::progressbar_proceed(System::Void)
{
	this->client_progressbar_waiting->Value = 100;
	for (System::Int32 time_index = 0; time_index < 100; time_index++)
	{
		if (!this->order_proccess) break;
		this->client_progressbar_waiting->Value -= 1;
		Thread::Sleep(150);
	}
	this->client_progressbar_waiting->Value = 0;
}

System::Void ClientPageView::client_button_order_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->client_textbox_address->Text == System::String::Empty)
	{
		MessageBox::Show("Заполните текстовое поле для адреса", "Требование"); return;
	}

	System::String^ address_field = this->client_textbox_address->Text;
	Models::CarModelTypes cartype_field;

	switch (this->client_combobox_cartype->SelectedIndex)
	{
	case 0: cartype_field = Models::CarModelTypes::CarTypeEconom; break;
	case 1: cartype_field = Models::CarModelTypes::CarTypeChild; break;
	case 2: cartype_field = Models::CarModelTypes::CarTypePremium; break;
	}

	this->service_order_controller->OrderRequestCallback += gcnew OrderController::RequestCallback(
		this, &ClientPageView::order_request_callback);

	System::Guid client_guid = this->service_account_manager->AccountToken.AccountGuid;
	System::Boolean registered_order;

	if (this->client_combobox_carclass->SelectedIndex == 0)
	{
		registered_order = this->service_order_controller->registration_order<Models::CarLightModel^>(
			address_field, cartype_field, client_guid);
	}
	else
	{
		registered_order = this->service_order_controller->registration_order<Models::CarHeavyModel^>(
			address_field, cartype_field, client_guid);
	}

	if (registered_order != true) { MessageBox::Show("Невозможно создать заказ", "Ошибка"); return; }
	this->client_button_cancel->Enabled = true;
	this->client_button_order->Enabled = false;

	this->client_label_waiting->Text = "Ожидание принятия заказа...";
	this->order_proccess = true;

	Task::Run(gcnew Action(this, &ClientPageView::progressbar_proceed));
}

System::Void ClientPageView::client_button_cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->service_order_controller->cancellation_token_push();
	return System::Void();
}

System::Void ClientPageView::client_button_bank_Click(System::Object^ sender, System::EventArgs^ e)
{
	Windows::Forms::Form^ bank_page = gcnew Views::BankSettingsView(this->service_bank_controller);
	bank_page->ShowDialog();
}

System::Void ClientPageView::client_button_logout_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Boolean logout_check = this->service_account_manager->sign_out_account();
	this->Close();
}

System::Void ClientPageView::account_list_initialize(System::Void)
{
	this->client_listview_account->FullRowSelect = true;
	this->client_listview_account->Items->Clear();

	ListViewItem^ list_item = gcnew ListViewItem("Тип аккаунта");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountType.ToString());
	this->client_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Аккаунт Guid");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountGuid.ToString());
	this->client_listview_account->Items->Add(list_item);

	Models::AccountClientModel^ account_model = nullptr;
	try {
		account_model = safe_cast<Models::AccountClientModel^>(this->service_account_manager
			->AccountToken.AccountModel);
	}
	catch (System::Exception^) { MessageBox::Show("Невозможно определить модель аккаунта", "Ошибка"); return; }

	list_item = gcnew ListViewItem("Номер банковской карты");
	list_item->SubItems->Add(account_model->BankCard.ToString());
	this->client_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Возраст");
	list_item->SubItems->Add(account_model->Age.ToString());
	this->client_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Пол");
	list_item->SubItems->Add(account_model->Gender.ToString());
	this->client_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Имя");
	list_item->SubItems->Add(account_model->Username);
	this->client_listview_account->Items->Add(list_item);
}

System::Void ClientPageView::client_button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ username_field = this->client_textbox_username->Text;
	System::Int32 age_field = System::Decimal::ToInt32(this->client_numeric_age->Value);
	Models::AccountModelGender gender_field;
	System::Guid bankcard_field = System::Guid::Empty;

	switch (this->client_combobox_gender->SelectedIndex)
	{
	case 0: gender_field = Models::AccountModelGender::MaleGender; break;
	case 1: gender_field = Models::AccountModelGender::FemaleGender; break;
	}
	
	try { bankcard_field = System::Guid::Parse(this->client_textbox_bankcard->Text); }
	catch (System::Exception^) { MessageBox::Show("Неверный формат банковской карты", "Ошибка"); return; }
	if (username_field == System::String::Empty) { MessageBox::Show("Неверный формат имени", "Ошибка"); return; }
	
	Models::AccountClientModel^ model = gcnew Models::AccountClientModel(
		username_field, age_field, gender_field, bankcard_field);
	System::Boolean update_check = this->service_account_manager->update_account(model);
	if (update_check != true) MessageBox::Show("Не удалось обновить данные аккаунта", "Ошибка");
	
	MessageBox::Show("Данные успешно обновлены", "Готово");
	this->account_list_initialize();
}

System::Void ClientPageView::client_button_refresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	Generic::List<System::Guid>^ drivers_list = this->service_depot_manager->get_all_drivers();
	if (drivers_list == nullptr) { MessageBox::Show("Не удалось получить информацию о водителях", "Ошибка"); return; }

	this->client_listview_car->FullRowSelect = true;
	this->client_listview_car->Items->Clear();

	for each (auto item in drivers_list)
	{
		Services::DriveComplexDbScheme^ complex = this->service_depot_manager->get_driver_complexs(item);
		if (complex == nullptr) continue;

		ListViewItem^ list_item = gcnew ListViewItem(complex->driver_guid);
		list_item->SubItems->Add(complex->car_class);
		list_item->SubItems->Add(complex->car_type);
		list_item->SubItems->Add(complex->driver_state);
		
		this->client_listview_car->Items->Add(list_item);
	}
	MessageBox::Show("Список доступных машин обновлен", "Готово");
}