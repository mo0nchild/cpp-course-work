#pragma once
#include "../../manager/manager.h"
#include "../../services/services.h"
#include "../../models/cars_model/cars_model.h"
#include "../../models/account_model/account_model.h"
#include "../bank_settings_view/bank_settings_view.h"
#include "client_pricelist_view.h"

namespace Views
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Threading::Tasks;
	using namespace System::Threading;

	using namespace Models;
	using namespace Services;
	/// <summary>
	/// —водка дл€ ClientPageView
	/// </summary>
	public ref class ClientPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;
		System::Boolean order_proccess;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		Services::OrderController^ service_order_controller = nullptr;
		Services::BankController^ service_bank_controller = nullptr;
	public:
		ClientPageView(System::Void) { InitializeComponent(); }

		ClientPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager) : order_proccess(false)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon(L"./assets/my_app_icon.ico");
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
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClientPageView(System::Void)
		{
			if (this->service_account_manager->IsInitialized) this->service_account_manager->sign_out_account();
			if (components) delete components;
		}

	private: System::Windows::Forms::CheckBox^ client_checkbox_bankcard;
	private: System::Windows::Forms::CheckBox^ client_checkbox_age;
	private: System::Windows::Forms::CheckBox^ client_checkbox_gender;
	private: System::Windows::Forms::CheckBox^ client_checkbox_username;

	private: System::Windows::Forms::Button^ client_button_money;
	private: System::Windows::Forms::Button^ client_button_price;
	private: System::Windows::Forms::TabControl^ client_tabcontrol;
	private: System::Windows::Forms::TabPage^ client_page_order;
	private: System::Windows::Forms::Label^ client_label_carlist;
	private: System::Windows::Forms::ComboBox^ client_combobox_cartype;
	private: System::Windows::Forms::ProgressBar^ client_progressbar_waiting;
	private: System::Windows::Forms::ListView^ client_listview_car;
	private: System::Windows::Forms::TabPage^ client_page_account;

	private: System::Windows::Forms::Button^ client_button_refresh;
	private: System::Windows::Forms::ColumnHeader^ driver_state;
	private: System::Windows::Forms::Button^ client_button_cancel;
	private: System::Windows::Forms::Button^ client_button_bank;

	private: System::Windows::Forms::TextBox^ client_textbox_address;
	private: System::Windows::Forms::Button^ client_button_order;
	private: System::Windows::Forms::Label^ client_label_cartype;

	private: System::Windows::Forms::Label^ client_label_address;
	private: System::Windows::Forms::Label^ client_label_carclass;
	private: System::Windows::Forms::ComboBox^ client_combobox_carclass;
	private: System::Windows::Forms::ColumnHeader^ driver_guid;


	private: System::Windows::Forms::ColumnHeader^ car_class;
	private: System::Windows::Forms::ColumnHeader^ car_type;
	private: System::Windows::Forms::Label^ client_label_waiting;
	private: System::Windows::Forms::TextBox^ client_textbox_username;
	private: System::Windows::Forms::Button^ client_button_update;
	private: System::Windows::Forms::Button^ client_button_logout;
	private: System::Windows::Forms::ListView^ client_listview_account;

	private: System::Windows::Forms::Label^ client_label_account;
	private: System::Windows::Forms::NumericUpDown^ client_numeric_age;
	private: System::Windows::Forms::TextBox^ client_textbox_bankcard;
	private: System::Windows::Forms::ComboBox^ client_combobox_gender;
	private: System::Windows::Forms::ColumnHeader^ account_field;
	private: System::Windows::Forms::ColumnHeader^ account_data;

		   /// <summary>
		   /// ќб€зательна€ переменна€ конструктора.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void);
#pragma endregion
		private: generic <class TEnum> TEnum convert_to_enum(System::String^ value);

		private: System::Void order_request_callback(OrderController::RequestAcceptToken token);

		private: System::Void progressbar_proceed(System::Void);

		private: System::Void client_button_order_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_cancel_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_refresh_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_update_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_logout_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void account_list_initialize(System::Void);

		private: System::Void client_button_bank_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_price_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void client_button_money_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
