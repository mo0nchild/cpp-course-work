#include "MyForm.h"

using namespace Views;

generic <class TEnum> TEnum ClientPageView::convert_to_enum(System::String^ value)
{ return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true)); }

System::Void ClientPageView::order_request_callback(OrderController::RequestAcceptToken token)
{
	if (!this->service_order_controller->cancellation_order())
		MessageBox::Show("Произошла ошибка при отмене заказа", "Ошибка");

	System::Boolean transfer_checker(true);

	if (token.Status == true)
	{
		Services::DriveComplexDbScheme^ complex_scheme = this->service_depot_manager->get_driver_complexs(token.ConnectionGuid);
		Services::AccountDriversDbScheme^ driver_scheme = this->service_account_manager
			->get_account_scheme<Services::AccountDriversDbScheme^>(token.ConnectionGuid);

		System::Guid transfer_guid = System::Guid::Empty;
		System::Int32 transfer_price(0);
		
		try {
			Models::CarModelTypes car_model_type = convert_to_enum<Models::CarModelTypes>(complex_scheme->car_type);
			switch (car_model_type) 
			{
			case Models::CarModelTypes::CarTypeEconom: transfer_price = CAR_ECONOM_PRICE; break;
			case Models::CarModelTypes::CarTypePremium: transfer_price = CAR_PREMIUM_PRICE; break;
			case Models::CarModelTypes::CarTypeChild: transfer_price = CAR_CHILD_PRICE; break;
			}
			transfer_guid = System::Guid::Parse(driver_scheme->bank_card);
		}
		catch (System::Exception^) { MessageBox::Show("Произошла ошибка при обработки подготовке к транзакции", "Ошибка"); }
		transfer_checker = this->service_bank_controller->transfer_money(transfer_guid, transfer_price);
	}

	this->order_proccess = false;
	this->client_label_waiting->Text = "Состояние заказа";

	if(transfer_checker)MessageBox::Show("Состояние заказа: " + token.Status.ToString(), "Готово");
	else MessageBox::Show("Произошла ошибка при оплате поездки", "Ошибка");

	this->client_button_cancel->Enabled = false;
	this->client_button_order->Enabled = true;
}

System::Void ClientPageView::client_button_bankmoney_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		Models::AccountClientModel^ account_model = safe_cast<Models::AccountClientModel^>(
			this->service_account_manager->AccountToken.AccountModel);

		if (!this->service_bank_controller->load_bank_account(account_model->BankCard))
			throw gcnew Services::AccountManagerTokenException(ClientPageView::typeid, "cant load bank account");
	}
	catch (System::Exception^) { MessageBox::Show("Невозможно подключиться к банковскому аккаунту", "Ошибка"); return; }

	MessageBox::Show(System::String::Concat("Текущий баланс: ", this->service_bank_controller->AccountMoney), "Готово");
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
	{ MessageBox::Show("Заполните текстовое поле для адреса", "Требование"); return; }

	try {
		Models::AccountClientModel^ account_model = safe_cast<Models::AccountClientModel^>(
			this->service_account_manager->AccountToken.AccountModel);

		if (!this->service_bank_controller->load_bank_account(account_model->BankCard))
			throw gcnew Services::AccountManagerTokenException(ClientPageView::typeid, "cant load bank account");
	}
	catch (System::Exception^) { MessageBox::Show("Невозможно подключиться к банковскому аккаунту", "Ошибка"); return; }

	System::String^ address_field = this->client_textbox_address->Text;
	Models::CarModelTypes cartype_field;
	System::Int32 request_price(0);

	switch (this->client_combobox_cartype->SelectedIndex)
	{
	case 0: cartype_field = Models::CarModelTypes::CarTypeEconom; request_price = CAR_ECONOM_PRICE; break;
	case 1: cartype_field = Models::CarModelTypes::CarTypeChild; request_price = CAR_CHILD_PRICE; break;
	case 2: cartype_field = Models::CarModelTypes::CarTypePremium; request_price = CAR_PREMIUM_PRICE; break;
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
	if (update_check != true) { MessageBox::Show("Не удалось обновить данные аккаунта", "Ошибка"); return; }
	
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