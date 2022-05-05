#include "driver_page_view.h"

using namespace Views;

void DriverPageView::InitializeComponent(void)
{
    this->driver_tabcontrol = (gcnew System::Windows::Forms::TabControl());
    this->driver_page_order = (gcnew System::Windows::Forms::TabPage());
    this->driver_label_currentstatus = (gcnew System::Windows::Forms::Label());
    this->driver_statuslist = (gcnew System::Windows::Forms::Label());
    this->driver_textbox_status = (gcnew System::Windows::Forms::TextBox());
    this->driver_button_status = (gcnew System::Windows::Forms::Button());
    this->driver_combobox_status = (gcnew System::Windows::Forms::ComboBox());
    this->driver_button_bankmoney = (gcnew System::Windows::Forms::Button());
    this->driver_button_complexinfo = (gcnew System::Windows::Forms::Button());
    this->driver_orders_list = (gcnew System::Windows::Forms::Label());
    this->driver_button_update_orders = (gcnew System::Windows::Forms::Button());
    this->driver_button_accept_order = (gcnew System::Windows::Forms::Button());
    this->driver_listview_orders = (gcnew System::Windows::Forms::ListView());
    this->order_client_guid = (gcnew System::Windows::Forms::ColumnHeader());
    this->order_car_class = (gcnew System::Windows::Forms::ColumnHeader());
    this->order_car_type = (gcnew System::Windows::Forms::ColumnHeader());
    this->order_address = (gcnew System::Windows::Forms::ColumnHeader());
    this->order_date = (gcnew System::Windows::Forms::ColumnHeader());
    this->driver_page_garage = (gcnew System::Windows::Forms::TabPage());
    this->driver_button_update_garage = (gcnew System::Windows::Forms::Button());
    this->driver_label_garage = (gcnew System::Windows::Forms::Label());
    this->driver_button_return = (gcnew System::Windows::Forms::Button());
    this->driver_button_rent = (gcnew System::Windows::Forms::Button());
    this->driver_listview_garage = (gcnew System::Windows::Forms::ListView());
    this->garage_car_class = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_type = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_color = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_speed = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_count = (gcnew System::Windows::Forms::ColumnHeader());
    this->driver_page_account = (gcnew System::Windows::Forms::TabPage());
    this->driver_checkbox_licence = (gcnew System::Windows::Forms::CheckBox());
    this->driver_checkbox_bankcard = (gcnew System::Windows::Forms::CheckBox());
    this->driver_checkbox_age = (gcnew System::Windows::Forms::CheckBox());
    this->driver_checkbox_gender = (gcnew System::Windows::Forms::CheckBox());
    this->driver_checkbox_username = (gcnew System::Windows::Forms::CheckBox());
    this->driver_textbox_licence = (gcnew System::Windows::Forms::TextBox());
    this->driver_button_bank = (gcnew System::Windows::Forms::Button());
    this->driver_label_account = (gcnew System::Windows::Forms::Label());
    this->driver_numeric_age = (gcnew System::Windows::Forms::NumericUpDown());
    this->driver_textbox_bankcard = (gcnew System::Windows::Forms::TextBox());
    this->driver_combobox_gender = (gcnew System::Windows::Forms::ComboBox());
    this->driver_textbox_username = (gcnew System::Windows::Forms::TextBox());
    this->driver_button_update = (gcnew System::Windows::Forms::Button());
    this->driver_button_logout = (gcnew System::Windows::Forms::Button());
    this->driver_listview_account = (gcnew System::Windows::Forms::ListView());
    this->account_field = (gcnew System::Windows::Forms::ColumnHeader());
    this->account_data = (gcnew System::Windows::Forms::ColumnHeader());
    this->driver_tabcontrol->SuspendLayout();
    this->driver_page_order->SuspendLayout();
    this->driver_page_garage->SuspendLayout();
    this->driver_page_account->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->driver_numeric_age))->BeginInit();
    this->SuspendLayout();
    // 
    // driver_tabcontrol
    // 
    this->driver_tabcontrol->Controls->Add(this->driver_page_order);
    this->driver_tabcontrol->Controls->Add(this->driver_page_garage);
    this->driver_tabcontrol->Controls->Add(this->driver_page_account);
    this->driver_tabcontrol->Dock = System::Windows::Forms::DockStyle::Fill;
    this->driver_tabcontrol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_tabcontrol->ItemSize = System::Drawing::Size(217, 25);
    this->driver_tabcontrol->Location = System::Drawing::Point(0, 0);
    this->driver_tabcontrol->Name = L"driver_tabcontrol";
    this->driver_tabcontrol->SelectedIndex = 0;
    this->driver_tabcontrol->Size = System::Drawing::Size(655, 500);
    this->driver_tabcontrol->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->driver_tabcontrol->TabIndex = 1;
    // 
    // driver_page_order
    // 
    this->driver_page_order->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
        static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
    this->driver_page_order->Controls->Add(this->driver_label_currentstatus);
    this->driver_page_order->Controls->Add(this->driver_statuslist);
    this->driver_page_order->Controls->Add(this->driver_textbox_status);
    this->driver_page_order->Controls->Add(this->driver_button_status);
    this->driver_page_order->Controls->Add(this->driver_combobox_status);
    this->driver_page_order->Controls->Add(this->driver_button_bankmoney);
    this->driver_page_order->Controls->Add(this->driver_button_complexinfo);
    this->driver_page_order->Controls->Add(this->driver_orders_list);
    this->driver_page_order->Controls->Add(this->driver_button_update_orders);
    this->driver_page_order->Controls->Add(this->driver_button_accept_order);
    this->driver_page_order->Controls->Add(this->driver_listview_orders);
    this->driver_page_order->Location = System::Drawing::Point(4, 29);
    this->driver_page_order->Name = L"driver_page_order";
    this->driver_page_order->Padding = System::Windows::Forms::Padding(3);
    this->driver_page_order->Size = System::Drawing::Size(647, 467);
    this->driver_page_order->TabIndex = 0;
    this->driver_page_order->Text = L"Поиск заказов";
    // 
    // driver_label_currentstatus
    // 
    this->driver_label_currentstatus->AutoSize = true;
    this->driver_label_currentstatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_label_currentstatus->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_label_currentstatus->Location = System::Drawing::Point(231, 301);
    this->driver_label_currentstatus->Name = L"driver_label_currentstatus";
    this->driver_label_currentstatus->Size = System::Drawing::Size(113, 17);
    this->driver_label_currentstatus->TabIndex = 24;
    this->driver_label_currentstatus->Text = L"Текущий статус";
    // 
    // driver_statuslist
    // 
    this->driver_statuslist->AutoSize = true;
    this->driver_statuslist->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_statuslist->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_statuslist->Location = System::Drawing::Point(23, 301);
    this->driver_statuslist->Name = L"driver_statuslist";
    this->driver_statuslist->Size = System::Drawing::Size(128, 17);
    this->driver_statuslist->TabIndex = 23;
    this->driver_statuslist->Text = L"Список состояний";
    // 
    // driver_textbox_status
    // 
    this->driver_textbox_status->BackColor = System::Drawing::SystemColors::HighlightText;
    this->driver_textbox_status->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_textbox_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
    this->driver_textbox_status->Location = System::Drawing::Point(234, 320);
    this->driver_textbox_status->Name = L"driver_textbox_status";
    this->driver_textbox_status->ReadOnly = true;
    this->driver_textbox_status->Size = System::Drawing::Size(183, 29);
    this->driver_textbox_status->TabIndex = 22;
    // 
    // driver_button_status
    // 
    this->driver_button_status->BackColor = System::Drawing::Color::White;
    this->driver_button_status->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_status->Location = System::Drawing::Point(440, 320);
    this->driver_button_status->Name = L"driver_button_status";
    this->driver_button_status->Size = System::Drawing::Size(183, 31);
    this->driver_button_status->TabIndex = 21;
    this->driver_button_status->Text = L"Изменить статус";
    this->driver_button_status->UseVisualStyleBackColor = false;
    this->driver_button_status->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_status_Click);
    // 
    // driver_combobox_status
    // 
    this->driver_combobox_status->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->driver_combobox_status->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->driver_combobox_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_combobox_status->FormattingEnabled = true;
    this->driver_combobox_status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Готов", L"Занят", L"В ожидании" });
    this->driver_combobox_status->Location = System::Drawing::Point(26, 321);
    this->driver_combobox_status->Name = L"driver_combobox_status";
    this->driver_combobox_status->Size = System::Drawing::Size(183, 28);
    this->driver_combobox_status->TabIndex = 20;
    // 
    // driver_button_bankmoney
    // 
    this->driver_button_bankmoney->BackColor = System::Drawing::Color::White;
    this->driver_button_bankmoney->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_bankmoney->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_bankmoney->Location = System::Drawing::Point(591, 415);
    this->driver_button_bankmoney->Name = L"driver_button_bankmoney";
    this->driver_button_bankmoney->Size = System::Drawing::Size(32, 29);
    this->driver_button_bankmoney->TabIndex = 19;
    this->driver_button_bankmoney->Text = L"$";
    this->driver_button_bankmoney->UseVisualStyleBackColor = false;
    this->driver_button_bankmoney->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_bankmoney_Click);
    // 
    // driver_button_complexinfo
    // 
    this->driver_button_complexinfo->BackColor = System::Drawing::Color::White;
    this->driver_button_complexinfo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_complexinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_complexinfo->Location = System::Drawing::Point(25, 415);
    this->driver_button_complexinfo->Name = L"driver_button_complexinfo";
    this->driver_button_complexinfo->Size = System::Drawing::Size(546, 31);
    this->driver_button_complexinfo->TabIndex = 11;
    this->driver_button_complexinfo->Text = L"Показать информацию о комплексе";
    this->driver_button_complexinfo->UseVisualStyleBackColor = false;
    this->driver_button_complexinfo->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_complexinfo_Click);
    // 
    // driver_orders_list
    // 
    this->driver_orders_list->AutoSize = true;
    this->driver_orders_list->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_orders_list->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_orders_list->Location = System::Drawing::Point(23, 15);
    this->driver_orders_list->Name = L"driver_orders_list";
    this->driver_orders_list->Size = System::Drawing::Size(111, 17);
    this->driver_orders_list->TabIndex = 10;
    this->driver_orders_list->Text = L"Список заказов";
    // 
    // driver_button_update_orders
    // 
    this->driver_button_update_orders->BackColor = System::Drawing::Color::White;
    this->driver_button_update_orders->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_update_orders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_update_orders->Location = System::Drawing::Point(332, 367);
    this->driver_button_update_orders->Name = L"driver_button_update_orders";
    this->driver_button_update_orders->Size = System::Drawing::Size(291, 31);
    this->driver_button_update_orders->TabIndex = 6;
    this->driver_button_update_orders->Text = L"Обновить список";
    this->driver_button_update_orders->UseVisualStyleBackColor = false;
    this->driver_button_update_orders->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_update_orders_Click);
    // 
    // driver_button_accept_order
    // 
    this->driver_button_accept_order->BackColor = System::Drawing::Color::White;
    this->driver_button_accept_order->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_accept_order->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_accept_order->Location = System::Drawing::Point(25, 367);
    this->driver_button_accept_order->Name = L"driver_button_accept_order";
    this->driver_button_accept_order->Size = System::Drawing::Size(291, 31);
    this->driver_button_accept_order->TabIndex = 5;
    this->driver_button_accept_order->Text = L"Принять заказ";
    this->driver_button_accept_order->UseVisualStyleBackColor = false;
    this->driver_button_accept_order->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_accept_order_Click);
    // 
    // driver_listview_orders
    // 
    this->driver_listview_orders->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_listview_orders->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
        this->order_client_guid,
            this->order_car_class, this->order_car_type, this->order_address, this->order_date
    });
    this->driver_listview_orders->GridLines = true;
    this->driver_listview_orders->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->driver_listview_orders->HideSelection = false;
    this->driver_listview_orders->Location = System::Drawing::Point(25, 40);
    this->driver_listview_orders->MaximumSize = System::Drawing::Size(598, 254);
    this->driver_listview_orders->MinimumSize = System::Drawing::Size(598, 254);
    this->driver_listview_orders->MultiSelect = false;
    this->driver_listview_orders->Name = L"driver_listview_orders";
    this->driver_listview_orders->Size = System::Drawing::Size(598, 254);
    this->driver_listview_orders->TabIndex = 0;
    this->driver_listview_orders->UseCompatibleStateImageBehavior = false;
    this->driver_listview_orders->View = System::Windows::Forms::View::Details;
    // 
    // order_client_guid
    // 
    this->order_client_guid->Text = L"Клиент Guid";
    this->order_client_guid->Width = 200;
    // 
    // order_car_class
    // 
    this->order_car_class->Text = L"Класс машины";
    this->order_car_class->Width = 100;
    // 
    // order_car_type
    // 
    this->order_car_type->Text = L"Тип машины";
    this->order_car_type->Width = 100;
    // 
    // order_address
    // 
    this->order_address->Text = L"Адрес";
    this->order_address->Width = 100;
    // 
    // order_date
    // 
    this->order_date->Text = L"Дата/Время";
    this->order_date->Width = 100;
    // 
    // driver_page_garage
    // 
    this->driver_page_garage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
        static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
    this->driver_page_garage->Controls->Add(this->driver_button_update_garage);
    this->driver_page_garage->Controls->Add(this->driver_label_garage);
    this->driver_page_garage->Controls->Add(this->driver_button_return);
    this->driver_page_garage->Controls->Add(this->driver_button_rent);
    this->driver_page_garage->Controls->Add(this->driver_listview_garage);
    this->driver_page_garage->Location = System::Drawing::Point(4, 29);
    this->driver_page_garage->Name = L"driver_page_garage";
    this->driver_page_garage->Size = System::Drawing::Size(647, 467);
    this->driver_page_garage->TabIndex = 2;
    this->driver_page_garage->Text = L"Просмотр машин";
    // 
    // driver_button_update_garage
    // 
    this->driver_button_update_garage->BackColor = System::Drawing::Color::White;
    this->driver_button_update_garage->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_update_garage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_update_garage->Location = System::Drawing::Point(22, 324);
    this->driver_button_update_garage->Name = L"driver_button_update_garage";
    this->driver_button_update_garage->Size = System::Drawing::Size(598, 31);
    this->driver_button_update_garage->TabIndex = 16;
    this->driver_button_update_garage->Text = L"Обновить список доступных машин";
    this->driver_button_update_garage->UseVisualStyleBackColor = false;
    this->driver_button_update_garage->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_update_garage_Click);
    // 
    // driver_label_garage
    // 
    this->driver_label_garage->AutoSize = true;
    this->driver_label_garage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_label_garage->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_label_garage->Location = System::Drawing::Point(20, 16);
    this->driver_label_garage->Name = L"driver_label_garage";
    this->driver_label_garage->Size = System::Drawing::Size(176, 17);
    this->driver_label_garage->TabIndex = 15;
    this->driver_label_garage->Text = L"Список доступных машин";
    // 
    // driver_button_return
    // 
    this->driver_button_return->BackColor = System::Drawing::Color::White;
    this->driver_button_return->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_return->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_return->Location = System::Drawing::Point(329, 374);
    this->driver_button_return->Name = L"driver_button_return";
    this->driver_button_return->Size = System::Drawing::Size(291, 31);
    this->driver_button_return->TabIndex = 14;
    this->driver_button_return->Text = L"Вернуть машину в гараж";
    this->driver_button_return->UseVisualStyleBackColor = false;
    this->driver_button_return->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_return_Click);
    // 
    // driver_button_rent
    // 
    this->driver_button_rent->BackColor = System::Drawing::Color::White;
    this->driver_button_rent->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_rent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_rent->Location = System::Drawing::Point(22, 374);
    this->driver_button_rent->Name = L"driver_button_rent";
    this->driver_button_rent->Size = System::Drawing::Size(291, 31);
    this->driver_button_rent->TabIndex = 13;
    this->driver_button_rent->Text = L"Использовать машину";
    this->driver_button_rent->UseVisualStyleBackColor = false;
    this->driver_button_rent->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_rent_Click);
    // 
    // driver_listview_garage
    // 
    this->driver_listview_garage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_listview_garage->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
        this->garage_car_class,
            this->garage_car_type, this->garage_car_color, this->garage_car_speed, this->garage_car_count
    });
    this->driver_listview_garage->GridLines = true;
    this->driver_listview_garage->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->driver_listview_garage->HideSelection = false;
    this->driver_listview_garage->Location = System::Drawing::Point(22, 41);
    this->driver_listview_garage->MultiSelect = false;
    this->driver_listview_garage->Name = L"driver_listview_garage";
    this->driver_listview_garage->Size = System::Drawing::Size(598, 262);
    this->driver_listview_garage->TabIndex = 12;
    this->driver_listview_garage->UseCompatibleStateImageBehavior = false;
    this->driver_listview_garage->View = System::Windows::Forms::View::Details;
    // 
    // garage_car_class
    // 
    this->garage_car_class->Text = L"Класс машины";
    this->garage_car_class->Width = 150;
    // 
    // garage_car_type
    // 
    this->garage_car_type->Text = L"Тип машины";
    this->garage_car_type->Width = 150;
    // 
    // garage_car_color
    // 
    this->garage_car_color->Text = L"Цвет машины";
    this->garage_car_color->Width = 130;
    // 
    // garage_car_speed
    // 
    this->garage_car_speed->Text = L"Скорость";
    this->garage_car_speed->Width = 75;
    // 
    // garage_car_count
    // 
    this->garage_car_count->Text = L"Количество";
    this->garage_car_count->Width = 90;
    // 
    // driver_page_account
    // 
    this->driver_page_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
        static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
    this->driver_page_account->Controls->Add(this->driver_checkbox_licence);
    this->driver_page_account->Controls->Add(this->driver_checkbox_bankcard);
    this->driver_page_account->Controls->Add(this->driver_checkbox_age);
    this->driver_page_account->Controls->Add(this->driver_checkbox_gender);
    this->driver_page_account->Controls->Add(this->driver_checkbox_username);
    this->driver_page_account->Controls->Add(this->driver_textbox_licence);
    this->driver_page_account->Controls->Add(this->driver_button_bank);
    this->driver_page_account->Controls->Add(this->driver_label_account);
    this->driver_page_account->Controls->Add(this->driver_numeric_age);
    this->driver_page_account->Controls->Add(this->driver_textbox_bankcard);
    this->driver_page_account->Controls->Add(this->driver_combobox_gender);
    this->driver_page_account->Controls->Add(this->driver_textbox_username);
    this->driver_page_account->Controls->Add(this->driver_button_update);
    this->driver_page_account->Controls->Add(this->driver_button_logout);
    this->driver_page_account->Controls->Add(this->driver_listview_account);
    this->driver_page_account->Location = System::Drawing::Point(4, 29);
    this->driver_page_account->Name = L"driver_page_account";
    this->driver_page_account->Padding = System::Windows::Forms::Padding(3);
    this->driver_page_account->Size = System::Drawing::Size(647, 467);
    this->driver_page_account->TabIndex = 1;
    this->driver_page_account->Text = L"Аккаунт";
    // 
    // driver_checkbox_licence
    // 
    this->driver_checkbox_licence->AutoSize = true;
    this->driver_checkbox_licence->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_checkbox_licence->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_checkbox_licence->Location = System::Drawing::Point(25, 335);
    this->driver_checkbox_licence->Name = L"driver_checkbox_licence";
    this->driver_checkbox_licence->Size = System::Drawing::Size(230, 21);
    this->driver_checkbox_licence->TabIndex = 23;
    this->driver_checkbox_licence->Text = L"Номер водительской лицензии";
    this->driver_checkbox_licence->UseVisualStyleBackColor = true;
    // 
    // driver_checkbox_bankcard
    // 
    this->driver_checkbox_bankcard->AutoSize = true;
    this->driver_checkbox_bankcard->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_checkbox_bankcard->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_checkbox_bankcard->Location = System::Drawing::Point(23, 279);
    this->driver_checkbox_bankcard->Name = L"driver_checkbox_bankcard";
    this->driver_checkbox_bankcard->Size = System::Drawing::Size(192, 21);
    this->driver_checkbox_bankcard->TabIndex = 22;
    this->driver_checkbox_bankcard->Text = L"Номер банковской карты";
    this->driver_checkbox_bankcard->UseVisualStyleBackColor = true;
    // 
    // driver_checkbox_age
    // 
    this->driver_checkbox_age->AutoSize = true;
    this->driver_checkbox_age->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_checkbox_age->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_checkbox_age->Location = System::Drawing::Point(505, 220);
    this->driver_checkbox_age->Name = L"driver_checkbox_age";
    this->driver_checkbox_age->Size = System::Drawing::Size(79, 21);
    this->driver_checkbox_age->TabIndex = 21;
    this->driver_checkbox_age->Text = L"Возраст";
    this->driver_checkbox_age->UseVisualStyleBackColor = true;
    // 
    // driver_checkbox_gender
    // 
    this->driver_checkbox_gender->AutoSize = true;
    this->driver_checkbox_gender->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_checkbox_gender->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_checkbox_gender->Location = System::Drawing::Point(297, 220);
    this->driver_checkbox_gender->Name = L"driver_checkbox_gender";
    this->driver_checkbox_gender->Size = System::Drawing::Size(51, 21);
    this->driver_checkbox_gender->TabIndex = 20;
    this->driver_checkbox_gender->Text = L"Пол";
    this->driver_checkbox_gender->UseVisualStyleBackColor = true;
    // 
    // driver_checkbox_username
    // 
    this->driver_checkbox_username->AutoSize = true;
    this->driver_checkbox_username->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_checkbox_username->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_checkbox_username->Location = System::Drawing::Point(25, 220);
    this->driver_checkbox_username->Name = L"driver_checkbox_username";
    this->driver_checkbox_username->Size = System::Drawing::Size(52, 21);
    this->driver_checkbox_username->TabIndex = 19;
    this->driver_checkbox_username->Text = L"Имя";
    this->driver_checkbox_username->UseVisualStyleBackColor = true;
    // 
    // driver_textbox_licence
    // 
    this->driver_textbox_licence->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_textbox_licence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->driver_textbox_licence->Location = System::Drawing::Point(23, 357);
    this->driver_textbox_licence->MaxLength = 36;
    this->driver_textbox_licence->Name = L"driver_textbox_licence";
    this->driver_textbox_licence->Size = System::Drawing::Size(602, 27);
    this->driver_textbox_licence->TabIndex = 15;
    // 
    // driver_button_bank
    // 
    this->driver_button_bank->BackColor = System::Drawing::Color::White;
    this->driver_button_bank->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_bank->Location = System::Drawing::Point(230, 406);
    this->driver_button_bank->Name = L"driver_button_bank";
    this->driver_button_bank->Size = System::Drawing::Size(190, 31);
    this->driver_button_bank->TabIndex = 14;
    this->driver_button_bank->Text = L"Менеджер банка";
    this->driver_button_bank->UseVisualStyleBackColor = false;
    this->driver_button_bank->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_bank_Click);
    // 
    // driver_label_account
    // 
    this->driver_label_account->AutoSize = true;
    this->driver_label_account->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->driver_label_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->driver_label_account->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->driver_label_account->Location = System::Drawing::Point(20, 12);
    this->driver_label_account->Name = L"driver_label_account";
    this->driver_label_account->Size = System::Drawing::Size(177, 17);
    this->driver_label_account->TabIndex = 9;
    this->driver_label_account->Text = L"Информация по аккаунту";
    // 
    // driver_numeric_age
    // 
    this->driver_numeric_age->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_numeric_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->driver_numeric_age->Location = System::Drawing::Point(505, 248);
    this->driver_numeric_age->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->driver_numeric_age->Name = L"driver_numeric_age";
    this->driver_numeric_age->Size = System::Drawing::Size(120, 27);
    this->driver_numeric_age->TabIndex = 8;
    this->driver_numeric_age->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    this->driver_numeric_age->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // driver_textbox_bankcard
    // 
    this->driver_textbox_bankcard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->driver_textbox_bankcard->Location = System::Drawing::Point(23, 302);
    this->driver_textbox_bankcard->MaxLength = 36;
    this->driver_textbox_bankcard->Name = L"driver_textbox_bankcard";
    this->driver_textbox_bankcard->Size = System::Drawing::Size(602, 27);
    this->driver_textbox_bankcard->TabIndex = 7;
    // 
    // driver_combobox_gender
    // 
    this->driver_combobox_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->driver_combobox_gender->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->driver_combobox_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_combobox_gender->FormattingEnabled = true;
    this->driver_combobox_gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Мужчина", L"Женщина" });
    this->driver_combobox_gender->Location = System::Drawing::Point(297, 247);
    this->driver_combobox_gender->Name = L"driver_combobox_gender";
    this->driver_combobox_gender->Size = System::Drawing::Size(186, 28);
    this->driver_combobox_gender->TabIndex = 6;
    // 
    // driver_textbox_username
    // 
    this->driver_textbox_username->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->driver_textbox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->driver_textbox_username->Location = System::Drawing::Point(23, 247);
    this->driver_textbox_username->MaxLength = 40;
    this->driver_textbox_username->Name = L"driver_textbox_username";
    this->driver_textbox_username->Size = System::Drawing::Size(249, 27);
    this->driver_textbox_username->TabIndex = 5;
    // 
    // driver_button_update
    // 
    this->driver_button_update->BackColor = System::Drawing::Color::White;
    this->driver_button_update->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_update->Location = System::Drawing::Point(23, 406);
    this->driver_button_update->Name = L"driver_button_update";
    this->driver_button_update->Size = System::Drawing::Size(192, 31);
    this->driver_button_update->TabIndex = 4;
    this->driver_button_update->Text = L"Обновить данные";
    this->driver_button_update->UseVisualStyleBackColor = false;
    this->driver_button_update->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_update_Click);
    // 
    // driver_button_logout
    // 
    this->driver_button_logout->BackColor = System::Drawing::Color::White;
    this->driver_button_logout->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->driver_button_logout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->driver_button_logout->Location = System::Drawing::Point(435, 406);
    this->driver_button_logout->Name = L"driver_button_logout";
    this->driver_button_logout->Size = System::Drawing::Size(190, 31);
    this->driver_button_logout->TabIndex = 2;
    this->driver_button_logout->Text = L"Выйти из аккаунта";
    this->driver_button_logout->UseVisualStyleBackColor = false;
    this->driver_button_logout->Click += gcnew System::EventHandler(this, &DriverPageView::driver_button_logout_Click);
    // 
    // driver_listview_account
    // 
    this->driver_listview_account->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
        this->account_field,
            this->account_data
    });
    this->driver_listview_account->GridLines = true;
    this->driver_listview_account->HideSelection = false;
    this->driver_listview_account->Location = System::Drawing::Point(23, 35);
    this->driver_listview_account->MultiSelect = false;
    this->driver_listview_account->Name = L"driver_listview_account";
    this->driver_listview_account->Size = System::Drawing::Size(602, 178);
    this->driver_listview_account->TabIndex = 1;
    this->driver_listview_account->UseCompatibleStateImageBehavior = false;
    this->driver_listview_account->View = System::Windows::Forms::View::Details;
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
    // DriverPageView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(655, 500);
    this->Controls->Add(this->driver_tabcontrol);
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(671, 539);
    this->MinimumSize = System::Drawing::Size(671, 539);
    this->Name = L"DriverPageView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"Страница Водителя";
    this->driver_tabcontrol->ResumeLayout(false);
    this->driver_page_order->ResumeLayout(false);
    this->driver_page_order->PerformLayout();
    this->driver_page_garage->ResumeLayout(false);
    this->driver_page_garage->PerformLayout();
    this->driver_page_account->ResumeLayout(false);
    this->driver_page_account->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->driver_numeric_age))->EndInit();
    this->ResumeLayout(false);

}