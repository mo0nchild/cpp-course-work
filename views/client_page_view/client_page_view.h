#pragma once
#include "../../manager/manager.h"
#include "../../services/services.h"

#include "../bank_settings_view/bank_settings_view.h"
#include "../admin_page_view/admin_page_view.h"
#include "../driver_page_view/driver_page_view.h"
#include "../client_page_view/client_page_view.h"

namespace Views {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Models;
	using namespace Services;
	/// <summary>
	/// Сводка для ClientPageView
	/// </summary>
	public ref class ClientPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		Services::OrderController^ service_order_controller = nullptr;
	private: System::Windows::Forms::ColumnHeader^ driver_state;

		Services::BankController^ service_bank_controller = nullptr;
	public:
		ClientPageView(System::Void) { InitializeComponent(); }

		ClientPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager)
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
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClientPageView(System::Void) 
		{
			if (this->service_account_manager->IsInitialized) this->service_account_manager->sign_out_account(); 
			if (components) delete components;
		}

	private: System::Windows::Forms::TabControl^ client_tabcontrol;
	private: System::Windows::Forms::TabPage^ client_page_order;
	private: System::Windows::Forms::Label^ client_label_carlist;
	private: System::Windows::Forms::ComboBox^ client_combobox_cartype;
	private: System::Windows::Forms::ProgressBar^ client_progressbar_waiting;
	private: System::Windows::Forms::ListView^ client_listview_car;
	private: System::Windows::Forms::TabPage^ client_page_account;
	private: System::Windows::Forms::ComboBox^ client_combobox_carcolor;
	private: System::Windows::Forms::Button^ client_button_refresh;


	private: System::Windows::Forms::TextBox^ client_textbox_address;
	private: System::Windows::Forms::Button^ client_button_order;
	private: System::Windows::Forms::Label^ client_label_cartype;
	private: System::Windows::Forms::Label^ client_label_carcolor;
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
	private: System::Windows::Forms::Label^ client_label_bankcard;

	private: System::Windows::Forms::Label^ client_label_age;
	private: System::Windows::Forms::Label^ client_label_gender;
	private: System::Windows::Forms::Label^ client_label_username;
	private: System::Windows::Forms::Label^ client_label_account;
	private: System::Windows::Forms::NumericUpDown^ client_numeric_age;
	private: System::Windows::Forms::TextBox^ client_textbox_bankcard;
	private: System::Windows::Forms::ComboBox^ client_combobox_gender;
	private: System::Windows::Forms::ColumnHeader^ account_field;
	private: System::Windows::Forms::ColumnHeader^ account_data;

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->client_tabcontrol = (gcnew System::Windows::Forms::TabControl());
			this->client_page_order = (gcnew System::Windows::Forms::TabPage());
			this->client_label_waiting = (gcnew System::Windows::Forms::Label());
			this->client_label_carclass = (gcnew System::Windows::Forms::Label());
			this->client_combobox_carclass = (gcnew System::Windows::Forms::ComboBox());
			this->client_label_cartype = (gcnew System::Windows::Forms::Label());
			this->client_label_carcolor = (gcnew System::Windows::Forms::Label());
			this->client_label_address = (gcnew System::Windows::Forms::Label());
			this->client_textbox_address = (gcnew System::Windows::Forms::TextBox());
			this->client_button_order = (gcnew System::Windows::Forms::Button());
			this->client_combobox_carcolor = (gcnew System::Windows::Forms::ComboBox());
			this->client_button_refresh = (gcnew System::Windows::Forms::Button());
			this->client_label_carlist = (gcnew System::Windows::Forms::Label());
			this->client_combobox_cartype = (gcnew System::Windows::Forms::ComboBox());
			this->client_progressbar_waiting = (gcnew System::Windows::Forms::ProgressBar());
			this->client_listview_car = (gcnew System::Windows::Forms::ListView());
			this->driver_guid = (gcnew System::Windows::Forms::ColumnHeader());
			this->car_class = (gcnew System::Windows::Forms::ColumnHeader());
			this->car_type = (gcnew System::Windows::Forms::ColumnHeader());
			this->driver_state = (gcnew System::Windows::Forms::ColumnHeader());
			this->client_page_account = (gcnew System::Windows::Forms::TabPage());
			this->client_label_bankcard = (gcnew System::Windows::Forms::Label());
			this->client_label_age = (gcnew System::Windows::Forms::Label());
			this->client_label_gender = (gcnew System::Windows::Forms::Label());
			this->client_label_username = (gcnew System::Windows::Forms::Label());
			this->client_label_account = (gcnew System::Windows::Forms::Label());
			this->client_numeric_age = (gcnew System::Windows::Forms::NumericUpDown());
			this->client_textbox_bankcard = (gcnew System::Windows::Forms::TextBox());
			this->client_combobox_gender = (gcnew System::Windows::Forms::ComboBox());
			this->client_textbox_username = (gcnew System::Windows::Forms::TextBox());
			this->client_button_update = (gcnew System::Windows::Forms::Button());
			this->client_button_logout = (gcnew System::Windows::Forms::Button());
			this->client_listview_account = (gcnew System::Windows::Forms::ListView());
			this->account_field = (gcnew System::Windows::Forms::ColumnHeader());
			this->account_data = (gcnew System::Windows::Forms::ColumnHeader());
			this->client_tabcontrol->SuspendLayout();
			this->client_page_order->SuspendLayout();
			this->client_page_account->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_numeric_age))->BeginInit();
			this->SuspendLayout();
			// 
			// client_tabcontrol
			// 
			this->client_tabcontrol->Controls->Add(this->client_page_order);
			this->client_tabcontrol->Controls->Add(this->client_page_account);
			this->client_tabcontrol->Dock = System::Windows::Forms::DockStyle::Fill;
			this->client_tabcontrol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_tabcontrol->ItemSize = System::Drawing::Size(322, 25);
			this->client_tabcontrol->Location = System::Drawing::Point(0, 0);
			this->client_tabcontrol->Name = L"client_tabcontrol";
			this->client_tabcontrol->SelectedIndex = 0;
			this->client_tabcontrol->Size = System::Drawing::Size(655, 500);
			this->client_tabcontrol->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->client_tabcontrol->TabIndex = 0;
			// 
			// client_page_order
			// 
			this->client_page_order->Controls->Add(this->client_label_waiting);
			this->client_page_order->Controls->Add(this->client_label_carclass);
			this->client_page_order->Controls->Add(this->client_combobox_carclass);
			this->client_page_order->Controls->Add(this->client_label_cartype);
			this->client_page_order->Controls->Add(this->client_label_carcolor);
			this->client_page_order->Controls->Add(this->client_label_address);
			this->client_page_order->Controls->Add(this->client_textbox_address);
			this->client_page_order->Controls->Add(this->client_button_order);
			this->client_page_order->Controls->Add(this->client_combobox_carcolor);
			this->client_page_order->Controls->Add(this->client_button_refresh);
			this->client_page_order->Controls->Add(this->client_label_carlist);
			this->client_page_order->Controls->Add(this->client_combobox_cartype);
			this->client_page_order->Controls->Add(this->client_progressbar_waiting);
			this->client_page_order->Controls->Add(this->client_listview_car);
			this->client_page_order->Location = System::Drawing::Point(4, 29);
			this->client_page_order->Name = L"client_page_order";
			this->client_page_order->Padding = System::Windows::Forms::Padding(3);
			this->client_page_order->Size = System::Drawing::Size(647, 467);
			this->client_page_order->TabIndex = 0;
			this->client_page_order->Text = L"Заказать машину";
			this->client_page_order->UseVisualStyleBackColor = true;
			// 
			// client_label_waiting
			// 
			this->client_label_waiting->AutoSize = true;
			this->client_label_waiting->Location = System::Drawing::Point(28, 391);
			this->client_label_waiting->Name = L"client_label_waiting";
			this->client_label_waiting->Size = System::Drawing::Size(192, 17);
			this->client_label_waiting->TabIndex = 16;
			this->client_label_waiting->Text = L"Ожидание принятия заказа";
			// 
			// client_label_carclass
			// 
			this->client_label_carclass->AutoSize = true;
			this->client_label_carclass->Location = System::Drawing::Point(28, 62);
			this->client_label_carclass->Name = L"client_label_carclass";
			this->client_label_carclass->Size = System::Drawing::Size(105, 17);
			this->client_label_carclass->TabIndex = 14;
			this->client_label_carclass->Text = L"Класс машины";
			// 
			// client_combobox_carclass
			// 
			this->client_combobox_carclass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_combobox_carclass->FormattingEnabled = true;
			this->client_combobox_carclass->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Легковая машина", L"Грузовая машина" });
			this->client_combobox_carclass->Location = System::Drawing::Point(28, 82);
			this->client_combobox_carclass->Name = L"client_combobox_carclass";
			this->client_combobox_carclass->Size = System::Drawing::Size(283, 28);
			this->client_combobox_carclass->TabIndex = 13;
			// 
			// client_label_cartype
			// 
			this->client_label_cartype->AutoSize = true;
			this->client_label_cartype->Location = System::Drawing::Point(332, 62);
			this->client_label_cartype->Name = L"client_label_cartype";
			this->client_label_cartype->Size = System::Drawing::Size(93, 17);
			this->client_label_cartype->TabIndex = 12;
			this->client_label_cartype->Text = L"Тип Машины";
			// 
			// client_label_carcolor
			// 
			this->client_label_carcolor->AutoSize = true;
			this->client_label_carcolor->Location = System::Drawing::Point(332, 113);
			this->client_label_carcolor->Name = L"client_label_carcolor";
			this->client_label_carcolor->Size = System::Drawing::Size(99, 17);
			this->client_label_carcolor->TabIndex = 11;
			this->client_label_carcolor->Text = L"Цвет машины";
			// 
			// client_label_address
			// 
			this->client_label_address->AutoSize = true;
			this->client_label_address->Location = System::Drawing::Point(28, 12);
			this->client_label_address->Name = L"client_label_address";
			this->client_label_address->Size = System::Drawing::Size(97, 17);
			this->client_label_address->TabIndex = 10;
			this->client_label_address->Text = L"Адрес заказа";
			// 
			// client_textbox_address
			// 
			this->client_textbox_address->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_textbox_address->Location = System::Drawing::Point(28, 31);
			this->client_textbox_address->MaxLength = 40;
			this->client_textbox_address->Name = L"client_textbox_address";
			this->client_textbox_address->Size = System::Drawing::Size(590, 26);
			this->client_textbox_address->TabIndex = 7;
			// 
			// client_button_order
			// 
			this->client_button_order->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_button_order->Location = System::Drawing::Point(28, 131);
			this->client_button_order->Name = L"client_button_order";
			this->client_button_order->Size = System::Drawing::Size(283, 29);
			this->client_button_order->TabIndex = 6;
			this->client_button_order->Text = L"Заказать";
			this->client_button_order->UseVisualStyleBackColor = true;
			this->client_button_order->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_order_Click);
			// 
			// client_combobox_carcolor
			// 
			this->client_combobox_carcolor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_combobox_carcolor->FormattingEnabled = true;
			this->client_combobox_carcolor->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Черный цвет", L"Белый цвет", L"Красный цвет",
					L"Желтый цвет"
			});
			this->client_combobox_carcolor->Location = System::Drawing::Point(335, 131);
			this->client_combobox_carcolor->Name = L"client_combobox_carcolor";
			this->client_combobox_carcolor->Size = System::Drawing::Size(283, 28);
			this->client_combobox_carcolor->TabIndex = 5;
			// 
			// client_button_refresh
			// 
			this->client_button_refresh->Location = System::Drawing::Point(530, 166);
			this->client_button_refresh->Name = L"client_button_refresh";
			this->client_button_refresh->Size = System::Drawing::Size(88, 29);
			this->client_button_refresh->TabIndex = 4;
			this->client_button_refresh->Text = L"Обновить";
			this->client_button_refresh->UseVisualStyleBackColor = true;
			this->client_button_refresh->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_refresh_Click);
			// 
			// client_label_carlist
			// 
			this->client_label_carlist->AutoSize = true;
			this->client_label_carlist->Location = System::Drawing::Point(25, 172);
			this->client_label_carlist->Name = L"client_label_carlist";
			this->client_label_carlist->Size = System::Drawing::Size(176, 17);
			this->client_label_carlist->TabIndex = 3;
			this->client_label_carlist->Text = L"Список доступных машин";
			// 
			// client_combobox_cartype
			// 
			this->client_combobox_cartype->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_combobox_cartype->FormattingEnabled = true;
			this->client_combobox_cartype->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Эконом машина", L"Детская машина",
					L"Премиум машина"
			});
			this->client_combobox_cartype->Location = System::Drawing::Point(335, 82);
			this->client_combobox_cartype->Name = L"client_combobox_cartype";
			this->client_combobox_cartype->Size = System::Drawing::Size(283, 28);
			this->client_combobox_cartype->TabIndex = 2;
			// 
			// client_progressbar_waiting
			// 
			this->client_progressbar_waiting->Location = System::Drawing::Point(28, 416);
			this->client_progressbar_waiting->Name = L"client_progressbar_waiting";
			this->client_progressbar_waiting->Size = System::Drawing::Size(590, 23);
			this->client_progressbar_waiting->TabIndex = 1;
			// 
			// client_listview_car
			// 
			this->client_listview_car->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->client_listview_car->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->driver_guid,
					this->car_class, this->car_type, this->driver_state
			});
			this->client_listview_car->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->client_listview_car->HideSelection = false;
			this->client_listview_car->Location = System::Drawing::Point(31, 201);
			this->client_listview_car->MaximumSize = System::Drawing::Size(590, 183);
			this->client_listview_car->MinimumSize = System::Drawing::Size(590, 183);
			this->client_listview_car->Name = L"client_listview_car";
			this->client_listview_car->Size = System::Drawing::Size(590, 183);
			this->client_listview_car->TabIndex = 0;
			this->client_listview_car->UseCompatibleStateImageBehavior = false;
			this->client_listview_car->View = System::Windows::Forms::View::Details;
			// 
			// driver_guid
			// 
			this->driver_guid->Text = L"Guid водителя";
			this->driver_guid->Width = 200;
			// 
			// car_class
			// 
			this->car_class->Text = L"Класс машины";
			this->car_class->Width = 150;
			// 
			// car_type
			// 
			this->car_type->Text = L"Тип машины";
			this->car_type->Width = 150;
			// 
			// driver_state
			// 
			this->driver_state->Text = L"Состояние";
			this->driver_state->Width = 100;
			// 
			// client_page_account
			// 
			this->client_page_account->Controls->Add(this->client_label_bankcard);
			this->client_page_account->Controls->Add(this->client_label_age);
			this->client_page_account->Controls->Add(this->client_label_gender);
			this->client_page_account->Controls->Add(this->client_label_username);
			this->client_page_account->Controls->Add(this->client_label_account);
			this->client_page_account->Controls->Add(this->client_numeric_age);
			this->client_page_account->Controls->Add(this->client_textbox_bankcard);
			this->client_page_account->Controls->Add(this->client_combobox_gender);
			this->client_page_account->Controls->Add(this->client_textbox_username);
			this->client_page_account->Controls->Add(this->client_button_update);
			this->client_page_account->Controls->Add(this->client_button_logout);
			this->client_page_account->Controls->Add(this->client_listview_account);
			this->client_page_account->Location = System::Drawing::Point(4, 29);
			this->client_page_account->Name = L"client_page_account";
			this->client_page_account->Padding = System::Windows::Forms::Padding(3);
			this->client_page_account->Size = System::Drawing::Size(647, 467);
			this->client_page_account->TabIndex = 1;
			this->client_page_account->Text = L"Аккаунт";
			this->client_page_account->UseVisualStyleBackColor = true;
			// 
			// client_label_bankcard
			// 
			this->client_label_bankcard->AutoSize = true;
			this->client_label_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_label_bankcard->Location = System::Drawing::Point(22, 279);
			this->client_label_bankcard->Name = L"client_label_bankcard";
			this->client_label_bankcard->Size = System::Drawing::Size(175, 17);
			this->client_label_bankcard->TabIndex = 13;
			this->client_label_bankcard->Text = L"Номер банковской карты";
			// 
			// client_label_age
			// 
			this->client_label_age->AutoSize = true;
			this->client_label_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_label_age->Location = System::Drawing::Point(501, 222);
			this->client_label_age->Name = L"client_label_age";
			this->client_label_age->Size = System::Drawing::Size(62, 17);
			this->client_label_age->TabIndex = 12;
			this->client_label_age->Text = L"Возраст";
			// 
			// client_label_gender
			// 
			this->client_label_gender->AutoSize = true;
			this->client_label_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_label_gender->Location = System::Drawing::Point(294, 222);
			this->client_label_gender->Name = L"client_label_gender";
			this->client_label_gender->Size = System::Drawing::Size(34, 17);
			this->client_label_gender->TabIndex = 11;
			this->client_label_gender->Text = L"Пол";
			// 
			// client_label_username
			// 
			this->client_label_username->AutoSize = true;
			this->client_label_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_label_username->Location = System::Drawing::Point(22, 222);
			this->client_label_username->Name = L"client_label_username";
			this->client_label_username->Size = System::Drawing::Size(35, 17);
			this->client_label_username->TabIndex = 10;
			this->client_label_username->Text = L"Имя";
			// 
			// client_label_account
			// 
			this->client_label_account->AutoSize = true;
			this->client_label_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->client_label_account->Location = System::Drawing::Point(20, 15);
			this->client_label_account->Name = L"client_label_account";
			this->client_label_account->Size = System::Drawing::Size(177, 17);
			this->client_label_account->TabIndex = 9;
			this->client_label_account->Text = L"Информация по аккаунту";
			// 
			// client_numeric_age
			// 
			this->client_numeric_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->client_numeric_age->Location = System::Drawing::Point(505, 248);
			this->client_numeric_age->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->client_numeric_age->Name = L"client_numeric_age";
			this->client_numeric_age->Size = System::Drawing::Size(120, 27);
			this->client_numeric_age->TabIndex = 8;
			this->client_numeric_age->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// client_textbox_bankcard
			// 
			this->client_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->client_textbox_bankcard->Location = System::Drawing::Point(23, 302);
			this->client_textbox_bankcard->MaxLength = 36;
			this->client_textbox_bankcard->Name = L"client_textbox_bankcard";
			this->client_textbox_bankcard->Size = System::Drawing::Size(602, 27);
			this->client_textbox_bankcard->TabIndex = 7;
			// 
			// client_combobox_gender
			// 
			this->client_combobox_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->client_combobox_gender->FormattingEnabled = true;
			this->client_combobox_gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Мужчина", L"Женщина" });
			this->client_combobox_gender->Location = System::Drawing::Point(297, 247);
			this->client_combobox_gender->Name = L"client_combobox_gender";
			this->client_combobox_gender->Size = System::Drawing::Size(186, 28);
			this->client_combobox_gender->TabIndex = 6;
			// 
			// client_textbox_username
			// 
			this->client_textbox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->client_textbox_username->Location = System::Drawing::Point(23, 247);
			this->client_textbox_username->MaxLength = 40;
			this->client_textbox_username->Name = L"client_textbox_username";
			this->client_textbox_username->Size = System::Drawing::Size(249, 27);
			this->client_textbox_username->TabIndex = 5;
			// 
			// client_button_update
			// 
			this->client_button_update->Location = System::Drawing::Point(23, 353);
			this->client_button_update->Name = L"client_button_update";
			this->client_button_update->Size = System::Drawing::Size(290, 31);
			this->client_button_update->TabIndex = 4;
			this->client_button_update->Text = L"Обновить данные";
			this->client_button_update->UseVisualStyleBackColor = true;
			this->client_button_update->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_update_Click);
			// 
			// client_button_logout
			// 
			this->client_button_logout->Location = System::Drawing::Point(344, 353);
			this->client_button_logout->Name = L"client_button_logout";
			this->client_button_logout->Size = System::Drawing::Size(281, 31);
			this->client_button_logout->TabIndex = 2;
			this->client_button_logout->Text = L"Выйти из аккаунта";
			this->client_button_logout->UseVisualStyleBackColor = true;
			this->client_button_logout->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_logout_Click);
			// 
			// client_listview_account
			// 
			this->client_listview_account->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->account_field,
					this->account_data
			});
			this->client_listview_account->HideSelection = false;
			this->client_listview_account->Location = System::Drawing::Point(23, 35);
			this->client_listview_account->Name = L"client_listview_account";
			this->client_listview_account->Size = System::Drawing::Size(602, 178);
			this->client_listview_account->TabIndex = 1;
			this->client_listview_account->UseCompatibleStateImageBehavior = false;
			this->client_listview_account->View = System::Windows::Forms::View::Details;
			// 
			// account_field
			// 
			this->account_field->Text = L"Название поля";
			this->account_field->Width = 200;
			// 
			// account_data
			// 
			this->account_data->Text = L"Установленные данные";
			this->account_data->Width = 400;
			// 
			// ClientPageView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 500);
			this->Controls->Add(this->client_tabcontrol);
			this->MaximumSize = System::Drawing::Size(671, 539);
			this->MinimumSize = System::Drawing::Size(671, 539);
			this->Name = L"ClientPageView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Страница Клиента";
			this->client_tabcontrol->ResumeLayout(false);
			this->client_page_order->ResumeLayout(false);
			this->client_page_order->PerformLayout();
			this->client_page_account->ResumeLayout(false);
			this->client_page_account->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->client_numeric_age))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void client_button_order_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (this->client_textbox_address->Text == System::String::Empty) 
			{ MessageBox::Show("Заполните текстовое поле для адреса", "Требование"); return; }

			System::String^ address_field = this->client_textbox_address->Text;
			// -------- продолжение ----------------

		}

		private: System::Void client_button_refresh_Click(System::Object^ sender, System::EventArgs^ e) 
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

		private: System::Void client_button_update_Click(System::Object^ sender, System::EventArgs^ e) 
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
			catch (System::Exception^ error) { MessageBox::Show("Неверный формат банковской карты", "Ошибка"); return; }
			if(username_field == System::String::Empty) { MessageBox::Show("Неверный формат имени", "Ошибка"); return; }

			Models::AccountClientModel^ model = gcnew Models::AccountClientModel(
				username_field, age_field, gender_field, bankcard_field);
			System::Boolean update_check = this->service_account_manager->update_account(model);
			if (update_check != true) MessageBox::Show("Не удалось обновить данные аккаунта", "Ошибка");
			
			MessageBox::Show("Данные успешно обновлены", "Готово");
			this->account_list_initialize();
		}

		private: System::Void client_button_logout_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Boolean logout_check = this->service_account_manager->sign_out_account();
			this->Close();
		}

		private: System::Void account_list_initialize(System::Void) 
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
			try{
				account_model = safe_cast<Models::AccountClientModel^>(this->service_account_manager
					->AccountToken.AccountModel);
			}
			catch (System::Exception^ error) { MessageBox::Show("Невозможно определить модель аккаунта", "Ошибка"); return; }

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
	};
}
