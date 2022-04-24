#pragma once
#include "../../manager/manager.h"
#include "../../services/services.h"
#include "admin_details_view.h"

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
	/// —водка дл€ AdminPageView
	/// </summary>
	public ref class AdminPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
	private: System::Windows::Forms::ColumnHeader^ garage_car_groupguid;
	private: System::Windows::Forms::Label^ admin_label_carspeed;
	private: System::Windows::Forms::NumericUpDown^ admin_numeric_carspeed;
		   Services::OrderController^ service_order_controller = nullptr;
	public:
		AdminPageView(System::Void) { InitializeComponent(); }

		AdminPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager)
		{ 
			InitializeComponent(); 
			this->service_manager = service_manager;
			this->start_page = start_page;

			Manager::IServiceProvider^ provider_account_manager = this->service_manager->get_service<AccountManager^>();
			Manager::IServiceProvider^ provider_depot_manager = this->service_manager->get_service<DepotManager^>();
			Manager::IServiceProvider^ provider_order_controller = this->service_manager->get_service<OrderController^>();

			this->service_account_manager = (Services::AccountManager^)provider_account_manager->Service;
			this->service_depot_manager = (Services::DepotManager^)provider_depot_manager->Service;
			this->service_order_controller = (Services::OrderController^)provider_order_controller->Service;
			this->set_tabs_limition();
			this->account_list_initialize();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AdminPageView(System::Void) 
		{ 
			if (components) delete components; 
			if (this->service_account_manager->IsInitialized) this->service_account_manager->sign_out_account();
		}

	private: System::Windows::Forms::TabControl^ admin_tabcontrol;
	private: System::Windows::Forms::TabPage^ admin_page_garage;
	private: System::Windows::Forms::TabPage^ admin_page_account;
	private: System::Windows::Forms::CheckBox^ admin_checkbox_age;
	private: System::Windows::Forms::CheckBox^ admin_checkbox_gender;
	private: System::Windows::Forms::CheckBox^ admin_checkbox_username;

	private: System::Windows::Forms::Label^ admin_label_account;
	private: System::Windows::Forms::NumericUpDown^ admin_numeric_age;
	private: System::Windows::Forms::ComboBox^ admin_combobox_gender;
	private: System::Windows::Forms::TextBox^ admin_textbox_username;
	private: System::Windows::Forms::Button^ admin_button_update;
	private: System::Windows::Forms::Button^ admin_button_logout;
	private: System::Windows::Forms::ListView^ admin_listview_account;

	private: System::Windows::Forms::ColumnHeader^ account_field;
	private: System::Windows::Forms::ColumnHeader^ account_data;
	private: System::Windows::Forms::TabPage^ admin_page_clients;
	private: System::Windows::Forms::ListView^ admin_listview_carlist;
	private: System::Windows::Forms::ColumnHeader^ garage_car_class;
	private: System::Windows::Forms::ColumnHeader^ garage_car_type;
	private: System::Windows::Forms::ColumnHeader^ garage_car_color;
	private: System::Windows::Forms::ColumnHeader^ garage_car_speed;
	private: System::Windows::Forms::ColumnHeader^ garage_car_count;
	private: System::Windows::Forms::Button^ admin_button_cardelete;
	private: System::Windows::Forms::Button^ admin_button_caradd;
	private: System::Windows::Forms::Button^ admin_button_upd;

	private: System::Windows::Forms::ComboBox^ admin_combobox_carclass;
	private: System::Windows::Forms::ComboBox^ admin_combobox_carcolor;
	private: System::Windows::Forms::ComboBox^ admin_combobox_cartype;
	private: System::Windows::Forms::Label^ admin_label_carcount;
	private: System::Windows::Forms::Label^ admin_label_carclass;
	private: System::Windows::Forms::Label^ admin_label_carcolor;
	private: System::Windows::Forms::Label^ admin_label_cartype;

	private: System::Windows::Forms::Label^ admin_label_carlist;
	private: System::Windows::Forms::NumericUpDown^ admin_numeric_carcount;
	private: System::Windows::Forms::Label^ admin_label_accounts;
	private: System::Windows::Forms::Button^ admin_button_refresh;
	private: System::Windows::Forms::Button^ admin_button_delete;

	private: System::Windows::Forms::ListView^ admin_listview_accounts;
	private: System::Windows::Forms::Button^ admin_button_accountinfo;
	private: System::Windows::Forms::ColumnHeader^ account_guid;
	private: System::Windows::Forms::ColumnHeader^ account_type;
	private: System::Windows::Forms::ColumnHeader^ account_state;

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

		private: System::Void set_tabs_limition(System::Void);

		private: generic <class TEnum> TEnum convert_to_enum(System::String^ value);

		private: System::Void account_list_initialize(System::Void);

		private: System::Void admin_button_caradd_Click(System::Object^ sender, System::EventArgs^ e);
	
		private: System::Void admin_button_cardelete_Click(System::Object^ sender, System::EventArgs^ e);
	
		private: System::Void admin_button_upd_Click(System::Object^ sender, System::EventArgs^ e);
	
		private: System::Void admin_button_accountinfo_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void admin_button_update_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void admin_button_logout_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void admin_button_refresh_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void admin_button_delete_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
