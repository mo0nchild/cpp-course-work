#include "driver_page_view.h"

using namespace Views;

generic <class TEnum> TEnum DriverPageView::convert_to_enum(System::String ^ value)
{
	return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
}

System::Void DriverPageView::driver_button_accept_order_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->service_depot_manager->IsBuilded != true)
	{ MessageBox::Show("Для начала нужно арендовать машину", "Ошибка"); return; }

	if (this->driver_listview_orders->SelectedItems->Count <= 0)
	{ MessageBox::Show("Выберите строку с заказом", "Ошибка"); return; }

	System::String^ selected_order = this->driver_listview_orders->SelectedItems[0]->Text;
	System::Guid client_guid;

	try { client_guid = System::Guid::Parse(selected_order); }
	catch (System::Exception^) { MessageBox::Show("Невозможно прочитать Guid заказа", "Ошибка"); return; }

	System::Boolean accept_check(false);
	try {
		accept_check = this->service_order_controller->accept_request(client_guid,
			this->service_depot_manager->DriverGuid);
	}
	catch (Services::OrderControllerTokenException^) {}

	if (accept_check != true) MessageBox::Show("Невозможно принять заказ", "Ошибка");
	else {
		Windows::Forms::Form^ form = gcnew Views::DriverDialogView(this->service_depot_manager->CarModel);
		form->ShowDialog();
	}
}

System::Void DriverPageView::driver_button_update_orders_Click(System::Object^ sender, System::EventArgs^ e)
{
	List<Services::OrderControllerDbScheme^>^ order_list = this->service_order_controller->OrderList;
	if (order_list == nullptr) { MessageBox::Show("Невозможно получить список заказов", "Ошибка"); return; }

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
		MessageBox::Show("Список заказов обновлен", "Готово");
	}
}

System::Void DriverPageView::driver_button_update_garage_Click(System::Object^ sender, System::EventArgs^ e)
{
	List<DepotManager::CarGarageItems>^ car_list = this->service_depot_manager->get_all_cars();
	if (car_list == nullptr) MessageBox::Show("Невозможно получить список машин", "Ошибка");

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
	{ MessageBox::Show("Выберите строку с машиной", "Ошибка"); return; }

	if (this->service_depot_manager->IsBuilded)
	{ MessageBox::Show("Машина уже выбрана", "Ошибка"); return; }

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
	catch (System::Exception^) { MessageBox::Show("Невозможно составить запрос", "Ошибка"); return; }

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
	else { MessageBox::Show("Невозможно определить класс машины", "Ошибка"); return; }

	if (rent_request != true) { MessageBox::Show("Запрос на аренду машины отклонен", "Ошибка"); }
	else
	{
		MessageBox::Show("Машина успешно арендована", "Готово");
		this->driver_button_rent->Enabled = false;
		this->driver_button_return->Enabled = true;
	}
}

System::Void DriverPageView::driver_button_return_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!this->service_depot_manager->IsBuilded)
	{ MessageBox::Show("Машина еще не выбрана", "Ошибка"); return; }

	if (!this->service_depot_manager->return_car_model()) MessageBox::Show("Запрос на возврат отклонен", "Ошибка");
	else
	{
		MessageBox::Show("Машина возвращена в гараж", "Готово");
		this->driver_button_rent->Enabled = true;
		this->driver_button_return->Enabled = false;
	}
}

System::Void DriverPageView::account_list_initialize(System::Void)
{
	this->driver_listview_account->FullRowSelect = true;
	this->driver_listview_account->Items->Clear();

	ListViewItem^ list_item = gcnew ListViewItem("Тип аккаунта");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountType.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Аккаунт Guid");
	list_item->SubItems->Add(this->service_account_manager->AccountToken.AccountGuid.ToString());
	this->driver_listview_account->Items->Add(list_item);

	Models::AccountDriverModel^ account_model = nullptr;
	try {
		account_model = safe_cast<Models::AccountDriverModel^>(this->service_account_manager
			->AccountToken.AccountModel);
	}
	catch (System::Exception^) { MessageBox::Show("Невозможно определить модель аккаунта", "Ошибка"); return; }

	list_item = gcnew ListViewItem("Номер банковской карты");
	list_item->SubItems->Add(account_model->BankCard.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Возраст");
	list_item->SubItems->Add(account_model->Age.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Пол");
	list_item->SubItems->Add(account_model->Gender.ToString());
	this->driver_listview_account->Items->Add(list_item);

	list_item = gcnew ListViewItem("Имя");
	list_item->SubItems->Add(account_model->Username);
	this->driver_listview_account->Items->Add(list_item);
}

System::Void DriverPageView::driver_button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ username_field = this->driver_textbox_username->Text;
	System::Int32 age_field = System::Decimal::ToInt32(this->driver_numeric_age->Value);
	Models::AccountModelGender gender_field;
	System::Guid bankcard_field, licence_field;

	switch (this->driver_combobox_gender->SelectedIndex)
	{
	case 0: gender_field = Models::AccountModelGender::MaleGender; break;
	case 1: gender_field = Models::AccountModelGender::FemaleGender; break;
	}
	try {
		bankcard_field = System::Guid::Parse(this->driver_textbox_bankcard->Text);
		licence_field = System::Guid::Parse(this->driver_textbox_licence->Text);
	}
	catch (System::Exception^) { MessageBox::Show("Неверный формат банковской карты", "Ошибка"); return; }
	if (username_field == System::String::Empty) { MessageBox::Show("Неверный формат имени", "Ошибка"); return; }

	Models::AccountDriverModel^ model = gcnew Models::AccountDriverModel(
		username_field, age_field, gender_field, bankcard_field, licence_field);
	System::Boolean update_check = this->service_account_manager->update_account(model);
	if (update_check != true) MessageBox::Show("Не удалось обновить данные аккаунта", "Ошибка");

	MessageBox::Show("Данные успешно обновлены", "Готово");
	this->account_list_initialize();
}

System::Void DriverPageView::driver_button_bank_Click(System::Object^ sender, System::EventArgs^ e)
{
	Windows::Forms::Form^ bank_page = gcnew Views::BankSettingsView(this->service_bank_controller);
	bank_page->ShowDialog();
}

System::Void DriverPageView::driver_button_logout_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Boolean logout_check = this->service_account_manager->sign_out_account();
	if (this->service_depot_manager->IsBuilded) this->service_depot_manager->return_car_model();
	this->Close();
}

System::Void DriverPageView::driver_button_complexinfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	Windows::Forms::Form^ form = gcnew Views::DriverComplexView(this->service_depot_manager->CarModel,
		this->service_depot_manager->CarModelType);
	form->ShowDialog();
}