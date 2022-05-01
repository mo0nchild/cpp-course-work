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

	using namespace Services;
	using namespace Models;
	/// <summary>
	/// —водка дл€ AuthorizationView
	/// </summary>
	public ref class AuthorizationView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;

		Services::BankController^ bank_controller = nullptr;
	private: System::Windows::Forms::Label^ label1;
		   Services::AccountManager^ account_manager = nullptr;
	public:
		AuthorizationView(System::Void) { InitializeComponent(); }

		AuthorizationView(Manager::ServiceManager^ service_manager)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon(L"./assets/my_app_icon.ico");
			this->service_manager = service_manager;

			Manager::IServiceProvider^ bank_controller_provider = this->service_manager->get_service<Services::BankController^>();
			Manager::IServiceProvider^ account_manager_provider = this->service_manager->get_service<Services::AccountManager^>();

			this->account_manager = (Services::AccountManager^)account_manager_provider->Service;
			this->bank_controller = (Services::BankController^)bank_controller_provider->Service;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AuthorizationView(System::Void) 
		{ 
			if (components) delete components; 
			if(this->account_manager->IsInitialized) this->account_manager->sign_out_account();
			Application::Exit();
		}

	private: System::Windows::Forms::TabControl^ page_list;
	private: System::Windows::Forms::TabPage^ page_authorization;
	private: System::Windows::Forms::TabPage^ page_registration;
	private: System::Windows::Forms::Label^ page1_label_login;
	private: System::Windows::Forms::TextBox^ page1_textbox_login;
	private: System::Windows::Forms::Button^ page1_button_authorize;
	private: System::Windows::Forms::Label^ page1_label_password;
	private: System::Windows::Forms::TextBox^ page1_textbox_password;
	private: System::Windows::Forms::Label^ page2_label_login;

	private: System::Windows::Forms::TextBox^ page2_textbox_login;
	private: System::Windows::Forms::Label^ page2_label_password;
	private: System::Windows::Forms::TextBox^ page2_textbox_password;
	private: System::Windows::Forms::Label^ page2_label_username;
	private: System::Windows::Forms::TextBox^ page2_textbox_username;
	private: System::Windows::Forms::TabControl^ page2_tabcontrol_info;
	private: System::Windows::Forms::TabPage^ page2_tabpage_client;
	private: System::Windows::Forms::TabPage^ page2_tabpage_driver;

	private: System::Windows::Forms::Label^ page2_label_age;
	private: System::Windows::Forms::NumericUpDown^ page2_numeric_age;
	private: System::Windows::Forms::Label^ page2_label_gender;
	private: System::Windows::Forms::ComboBox^ page2_combobox_gender;
	private: System::Windows::Forms::Button^ page2_button_registration;
	private: System::Windows::Forms::TabPage^ page2_tabpage_admin;
	private: System::Windows::Forms::Label^ pageclient_label_bankcard;
	private: System::Windows::Forms::TextBox^ pageclient_textbox_bankcard;
	private: System::Windows::Forms::Button^ page2_button_banksettings;

	private: System::Windows::Forms::Label^ pagedriver_label_bankcard;
	private: System::Windows::Forms::TextBox^ pagedriver_textbox_bankcard;
	private: System::Windows::Forms::Label^ pagedriver_label_licence;
	private: System::Windows::Forms::TextBox^ pagedriver_textbox_licence;
	private: System::Windows::Forms::Label^ pageadmin_label_permissions;
	private: System::Windows::Forms::ComboBox^ pageadmin_combobox_permissions;

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
		private: System::Void clear_all_textboxes(System::Void);

		private: System::Void page1_button_authorize_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void page2_button_registration_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void page2_button_banksettings_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void form_closed(System::Object^ sender, FormClosedEventArgs^ e);
	};
}
