#pragma once

#include "../../manager/manager.h"
#include "../../services/services.h"

#include "../bank_settings_view/bank_settings_view.h"
#include "../admin_page_view/admin_page_view.h"
#include "../driver_page_view/driver_page_view.h"
#include "../client_page_view/client_page_view.h"

namespace Views 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Models;
	using namespace Services;

	/// <summary>
	/// Сводка для DriverPageView
	/// </summary>
	public ref class DriverPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		Services::OrderController^ service_order_controller = nullptr;
		Services::BankController^ service_bank_controller = nullptr;

	public:
		DriverPageView(System::Void) { InitializeComponent(); }

		DriverPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager)
		{
			InitializeComponent();
			this->service_manager = service_manager;
			this->start_page = start_page;

			Manager::IServiceProvider^ provider_account_manager = this->service_manager->get_service<AccountManager^>();
			Manager::IServiceProvider^ provider_depot_manager = this->service_manager->get_service<DepotManager^>();
			Manager::IServiceProvider^ provider_order_controller = this->service_manager->get_service<OrderController^>();
			Manager::IServiceProvider^ provider_bank_controller = this->service_manager->get_service<BankController^>();

			this->service_account_manager = (Services::AccountManager^)provider_account_manager->Service;
			this->service_depot_manager = (Services::DepotManager^)provider_depot_manager->Service;
			this->service_order_controller = (Services::OrderController^)provider_order_controller->Service;
			this->service_bank_controller = (Services::BankController^)provider_bank_controller->Service;

			this->account_list_initialize();
			this->driver_button_rent->Enabled = true;
			this->driver_button_return->Enabled = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DriverPageView(System::Void) 
		{
			if (this->service_account_manager->IsInitialized) this->service_account_manager->sign_out_account();
			if (this->service_depot_manager->IsBuilded) this->service_depot_manager->return_car_model();
			if (components) delete components;
		}
	private: System::Windows::Forms::Label^ driver_orders_list;
	private: System::Windows::Forms::Button^ driver_button_update_orders;
	private: System::Windows::Forms::Button^ driver_button_accept_order;
	private: System::Windows::Forms::ColumnHeader^ order_client_guid;
	private: System::Windows::Forms::ColumnHeader^ order_car_class;
	private: System::Windows::Forms::ColumnHeader^ order_car_type;
	private: System::Windows::Forms::ColumnHeader^ order_address;

	private: System::Windows::Forms::Button^ driver_button_orderinfo;
	private: System::Windows::Forms::ColumnHeader^ order_date;
	private: System::Windows::Forms::Button^ driver_button_update_garage;
	private: System::Windows::Forms::Label^ driver_label_garage;
	private: System::Windows::Forms::Button^ driver_button_return;
	private: System::Windows::Forms::Button^ driver_button_rent;
	private: System::Windows::Forms::ListView^ driver_listview_garage;
	private: System::Windows::Forms::ColumnHeader^ garage_car_class;
	private: System::Windows::Forms::ColumnHeader^ garage_car_type;
	private: System::Windows::Forms::ColumnHeader^ garage_car_color;
	private: System::Windows::Forms::ColumnHeader^ garage_car_speed;
	private: System::Windows::Forms::ColumnHeader^ garage_car_count;

	private: System::Windows::Forms::TabControl^ driver_tabcontrol;
	private: System::Windows::Forms::TabPage^ driver_page_order;
	private: System::Windows::Forms::TabPage^ driver_page_account;
	private: System::Windows::Forms::Label^ driver_label_licence;
	private: System::Windows::Forms::TextBox^ driver_textbox_licence;
	private: System::Windows::Forms::Button^ driver_button_bank;
	private: System::Windows::Forms::Label^ driver_label_bankcard;
	private: System::Windows::Forms::Label^ driver_label_age;
	private: System::Windows::Forms::Label^ driver_label_gender;
	private: System::Windows::Forms::Label^ driver_label_username;
	private: System::Windows::Forms::Label^ driver_label_account;
	private: System::Windows::Forms::NumericUpDown^ driver_numeric_age;
	private: System::Windows::Forms::TextBox^ driver_textbox_bankcard;

	private: System::Windows::Forms::ComboBox^ driver_combobox_gender;
	private: System::Windows::Forms::TextBox^ driver_textbox_username;
	private: System::Windows::Forms::Button^ driver_button_update;
	private: System::Windows::Forms::Button^ driver_button_logout;
	private: System::Windows::Forms::ListView^ driver_listview_account;
	private: System::Windows::Forms::ColumnHeader^ account_field;
	private: System::Windows::Forms::ColumnHeader^ account_data;
	private: System::Windows::Forms::ListView^ driver_listview_orders;

	private: System::Windows::Forms::TabPage^ driver_page_garage;

	private:

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void);

#pragma endregion

		private: generic <class TEnum> TEnum convert_to_enum(System::String^ value)
		{
			return safe_cast<TEnum>(System::Enum::Parse(TEnum::typeid, value, true));
		}

		private: System::Void driver_button_accept_order_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (this->service_depot_manager->IsBuilded)
				MessageBox::Show("Для начала нужно арендовать машину", "Ошибка");

			if (this->driver_listview_orders->SelectedItems->Count <= 0)
				MessageBox::Show("Выберите строку с заказом", "Ошибка");

			System::String^ selected_order = this->driver_listview_orders->SelectedItems[0]->Text;
			System::Guid client_guid;

			try { client_guid = System::Guid::Parse(selected_order); }
			catch (System::Exception^) { MessageBox::Show("Невозможно прочитать Guid заказа", "Ошибка"); return; }

			Console::WriteLine(client_guid);

			System::Boolean accept_check = this->service_order_controller->accept_request(
				client_guid, this->service_depot_manager->DriverGuid);

			if(accept_check != true) MessageBox::Show("Невозможно принять заказ", "Ошибка");
			else MessageBox::Show("Заказ был принят", "Готово");
		}

		private: System::Void driver_button_update_orders_Click(System::Object^ sender, System::EventArgs^ e)
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

		private: System::Void driver_button_update_garage_Click(System::Object^ sender, System::EventArgs^ e) 
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

		private: System::Void driver_button_rent_Click(System::Object^ sender, System::EventArgs^ e) 
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

		private: System::Void driver_button_return_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!this->service_depot_manager->IsBuilded)
			{ MessageBox::Show("Машина еще не выбрана", "Ошибка"); return; }

			if(!this->service_depot_manager->return_car_model()) MessageBox::Show("Запрос на возврат отклонен", "Ошибка");
			else 
			{
				MessageBox::Show("Машина возвращена в гараж", "Готово");
				this->driver_button_rent->Enabled = true;
				this->driver_button_return->Enabled = false;
			}
		}

		private: System::Void account_list_initialize(System::Void)
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

		private: System::Void driver_button_update_Click(System::Object^ sender, System::EventArgs^ e) 
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

		private: System::Void driver_button_bank_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Windows::Forms::Form^ bank_page = gcnew Views::BankSettingsView(this->service_bank_controller);
			bank_page->ShowDialog();
		}

		private: System::Void driver_button_logout_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			System::Boolean logout_check = this->service_account_manager->sign_out_account();
			if (this->service_depot_manager->IsBuilded) this->service_depot_manager->return_car_model();
			this->Close();
		}

		private: System::Void driver_button_orderinfo_Click(System::Object^ sender, System::EventArgs^ e) 
		{

		}

	};
}
