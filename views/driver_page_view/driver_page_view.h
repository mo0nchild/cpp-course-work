#pragma once

#include "../../manager/manager.h"
#include "../../services/services.h"

#include "../bank_settings_view/bank_settings_view.h"
#include "../admin_page_view/admin_page_view.h"
#include "../driver_page_view/driver_page_view.h"
#include "../client_page_view/client_page_view.h"
#include "driver_dialog_view.h"
#include "driver_complex_view.h"

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
	/// —водка дл€ DriverPageView
	/// </summary>
	public ref class DriverPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		Services::OrderController^ service_order_controller = nullptr;
	private: System::Windows::Forms::CheckBox^ driver_checkbox_licence;
	private: System::Windows::Forms::CheckBox^ driver_checkbox_bankcard;
	private: System::Windows::Forms::CheckBox^ driver_checkbox_age;
	private: System::Windows::Forms::CheckBox^ driver_checkbox_gender;
	private: System::Windows::Forms::CheckBox^ driver_checkbox_username;
		   Services::BankController^ service_bank_controller = nullptr;

	public:
		DriverPageView(System::Void) { InitializeComponent(); }

		DriverPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon(L"./assets/my_app_icon.ico");

			this->driver_page_account->BackgroundImage = System::Drawing::Image::FromFile("./assets/background.png");
			this->driver_page_account->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			this->driver_page_order->BackgroundImage = System::Drawing::Image::FromFile("./assets/background.png");
			this->driver_page_order->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

			this->driver_page_garage->BackgroundImage = System::Drawing::Image::FromFile("./assets/background.png");
			this->driver_page_garage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;

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
			this->driver_complex_close();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DriverPageView(System::Void) 
		{
			if (this->service_account_manager->IsInitialized) this->service_account_manager->sign_out_account();
			if (this->service_depot_manager->IsBuilded) this->service_depot_manager->return_car_model();
			if (components) delete components;
		}

	private: System::Windows::Forms::Label^ driver_label_currentstatus;
	private: System::Windows::Forms::Label^ driver_statuslist;
	private: System::Windows::Forms::TextBox^ driver_textbox_status;
	private: System::Windows::Forms::Button^ driver_button_status;
	private: System::Windows::Forms::ComboBox^ driver_combobox_status;
	private: System::Windows::Forms::Button^ driver_button_bankmoney;
	private: System::Windows::Forms::Label^ driver_orders_list;
	private: System::Windows::Forms::Button^ driver_button_update_orders;
	private: System::Windows::Forms::Button^ driver_button_accept_order;
	private: System::Windows::Forms::ColumnHeader^ order_client_guid;
	private: System::Windows::Forms::ColumnHeader^ order_car_class;
	private: System::Windows::Forms::ColumnHeader^ order_car_type;
	private: System::Windows::Forms::ColumnHeader^ order_address;
	private: System::Windows::Forms::Button^ driver_button_complexinfo;


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

	private: System::Windows::Forms::TextBox^ driver_textbox_licence;
	private: System::Windows::Forms::Button^ driver_button_bank;




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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void);

#pragma endregion

		private: generic <class TEnum> TEnum convert_to_enum(System::String^ value);

		private: System::Void driver_complex_open(System::Void);

		private: System::Void driver_complex_close(System::Void);

		private: System::Void driver_button_accept_order_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_update_orders_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_update_garage_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_rent_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_return_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void account_list_initialize(System::Void);

		private: System::Void driver_button_update_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_bank_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_logout_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_complexinfo_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_bankmoney_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void driver_button_status_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
