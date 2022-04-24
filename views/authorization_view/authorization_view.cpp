#include "authorization_view.h"

using namespace Views;

void AuthorizationView::InitializeComponent(void)
{
    this->page_list = (gcnew System::Windows::Forms::TabControl());
    this->page_authorization = (gcnew System::Windows::Forms::TabPage());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->page1_button_authorize = (gcnew System::Windows::Forms::Button());
    this->page1_label_password = (gcnew System::Windows::Forms::Label());
    this->page1_textbox_password = (gcnew System::Windows::Forms::TextBox());
    this->page1_label_login = (gcnew System::Windows::Forms::Label());
    this->page1_textbox_login = (gcnew System::Windows::Forms::TextBox());
    this->page_registration = (gcnew System::Windows::Forms::TabPage());
    this->page2_button_banksettings = (gcnew System::Windows::Forms::Button());
    this->page2_button_registration = (gcnew System::Windows::Forms::Button());
    this->page2_tabcontrol_info = (gcnew System::Windows::Forms::TabControl());
    this->page2_tabpage_client = (gcnew System::Windows::Forms::TabPage());
    this->pageclient_label_bankcard = (gcnew System::Windows::Forms::Label());
    this->pageclient_textbox_bankcard = (gcnew System::Windows::Forms::TextBox());
    this->page2_tabpage_driver = (gcnew System::Windows::Forms::TabPage());
    this->pagedriver_label_bankcard = (gcnew System::Windows::Forms::Label());
    this->pagedriver_textbox_bankcard = (gcnew System::Windows::Forms::TextBox());
    this->pagedriver_label_licence = (gcnew System::Windows::Forms::Label());
    this->pagedriver_textbox_licence = (gcnew System::Windows::Forms::TextBox());
    this->page2_tabpage_admin = (gcnew System::Windows::Forms::TabPage());
    this->pageadmin_label_permissions = (gcnew System::Windows::Forms::Label());
    this->pageadmin_combobox_permissions = (gcnew System::Windows::Forms::ComboBox());
    this->page2_label_age = (gcnew System::Windows::Forms::Label());
    this->page2_numeric_age = (gcnew System::Windows::Forms::NumericUpDown());
    this->page2_label_gender = (gcnew System::Windows::Forms::Label());
    this->page2_combobox_gender = (gcnew System::Windows::Forms::ComboBox());
    this->page2_label_username = (gcnew System::Windows::Forms::Label());
    this->page2_textbox_username = (gcnew System::Windows::Forms::TextBox());
    this->page2_label_password = (gcnew System::Windows::Forms::Label());
    this->page2_textbox_password = (gcnew System::Windows::Forms::TextBox());
    this->page2_label_login = (gcnew System::Windows::Forms::Label());
    this->page2_textbox_login = (gcnew System::Windows::Forms::TextBox());
    this->page_list->SuspendLayout();
    this->page_authorization->SuspendLayout();
    this->page_registration->SuspendLayout();
    this->page2_tabcontrol_info->SuspendLayout();
    this->page2_tabpage_client->SuspendLayout();
    this->page2_tabpage_driver->SuspendLayout();
    this->page2_tabpage_admin->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->page2_numeric_age))->BeginInit();
    this->SuspendLayout();
    // 
    // page_list
    // 
    this->page_list->Controls->Add(this->page_authorization);
    this->page_list->Controls->Add(this->page_registration);
    this->page_list->Dock = System::Windows::Forms::DockStyle::Fill;
    this->page_list->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->page_list->HotTrack = true;
    this->page_list->ItemSize = System::Drawing::Size(223, 20);
    this->page_list->Location = System::Drawing::Point(0, 0);
    this->page_list->Multiline = true;
    this->page_list->Name = L"page_list";
    this->page_list->SelectedIndex = 0;
    this->page_list->Size = System::Drawing::Size(452, 403);
    this->page_list->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->page_list->TabIndex = 0;
    // 
    // page_authorization
    // 
    this->page_authorization->BackColor = System::Drawing::Color::Transparent;
    this->page_authorization->Controls->Add(this->label1);
    this->page_authorization->Controls->Add(this->page1_button_authorize);
    this->page_authorization->Controls->Add(this->page1_label_password);
    this->page_authorization->Controls->Add(this->page1_textbox_password);
    this->page_authorization->Controls->Add(this->page1_label_login);
    this->page_authorization->Controls->Add(this->page1_textbox_login);
    this->page_authorization->ForeColor = System::Drawing::Color::CornflowerBlue;
    this->page_authorization->Location = System::Drawing::Point(4, 24);
    this->page_authorization->Name = L"page_authorization";
    this->page_authorization->Padding = System::Windows::Forms::Padding(3);
    this->page_authorization->Size = System::Drawing::Size(444, 375);
    this->page_authorization->TabIndex = 0;
    this->page_authorization->Text = L"Авторизация";
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26));
    this->label1->Location = System::Drawing::Point(84, 46);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(267, 39);
    this->label1->TabIndex = 5;
    this->label1->Text = L"Дешевое такси";
    // 
    // page1_button_authorize
    // 
    this->page1_button_authorize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_button_authorize->Location = System::Drawing::Point(91, 279);
    this->page1_button_authorize->Name = L"page1_button_authorize";
    this->page1_button_authorize->Size = System::Drawing::Size(252, 42);
    this->page1_button_authorize->TabIndex = 4;
    this->page1_button_authorize->Text = L"Войти в аккаунт";
    this->page1_button_authorize->UseVisualStyleBackColor = true;
    this->page1_button_authorize->Click += gcnew System::EventHandler(this, &AuthorizationView::page1_button_authorize_Click);
    // 
    // page1_label_password
    // 
    this->page1_label_password->AutoSize = true;
    this->page1_label_password->Location = System::Drawing::Point(53, 195);
    this->page1_label_password->Name = L"page1_label_password";
    this->page1_label_password->Size = System::Drawing::Size(57, 17);
    this->page1_label_password->TabIndex = 3;
    this->page1_label_password->Text = L"Пароль";
    // 
    // page1_textbox_password
    // 
    this->page1_textbox_password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page1_textbox_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_textbox_password->Location = System::Drawing::Point(56, 215);
    this->page1_textbox_password->MaxLength = 40;
    this->page1_textbox_password->Name = L"page1_textbox_password";
    this->page1_textbox_password->Size = System::Drawing::Size(322, 26);
    this->page1_textbox_password->TabIndex = 2;
    this->page1_textbox_password->UseSystemPasswordChar = true;
    // 
    // page1_label_login
    // 
    this->page1_label_login->AutoSize = true;
    this->page1_label_login->Location = System::Drawing::Point(53, 120);
    this->page1_label_login->Name = L"page1_label_login";
    this->page1_label_login->Size = System::Drawing::Size(47, 17);
    this->page1_label_login->TabIndex = 1;
    this->page1_label_login->Text = L"Логин";
    // 
    // page1_textbox_login
    // 
    this->page1_textbox_login->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page1_textbox_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_textbox_login->Location = System::Drawing::Point(56, 140);
    this->page1_textbox_login->MaxLength = 40;
    this->page1_textbox_login->Name = L"page1_textbox_login";
    this->page1_textbox_login->Size = System::Drawing::Size(322, 26);
    this->page1_textbox_login->TabIndex = 0;
    // 
    // page_registration
    // 
    this->page_registration->Controls->Add(this->page2_button_banksettings);
    this->page_registration->Controls->Add(this->page2_button_registration);
    this->page_registration->Controls->Add(this->page2_tabcontrol_info);
    this->page_registration->Controls->Add(this->page2_label_age);
    this->page_registration->Controls->Add(this->page2_numeric_age);
    this->page_registration->Controls->Add(this->page2_label_gender);
    this->page_registration->Controls->Add(this->page2_combobox_gender);
    this->page_registration->Controls->Add(this->page2_label_username);
    this->page_registration->Controls->Add(this->page2_textbox_username);
    this->page_registration->Controls->Add(this->page2_label_password);
    this->page_registration->Controls->Add(this->page2_textbox_password);
    this->page_registration->Controls->Add(this->page2_label_login);
    this->page_registration->Controls->Add(this->page2_textbox_login);
    this->page_registration->ForeColor = System::Drawing::Color::Coral;
    this->page_registration->Location = System::Drawing::Point(4, 24);
    this->page_registration->Name = L"page_registration";
    this->page_registration->Padding = System::Windows::Forms::Padding(3);
    this->page_registration->Size = System::Drawing::Size(444, 375);
    this->page_registration->TabIndex = 1;
    this->page_registration->Text = L"Регистрация";
    this->page_registration->UseVisualStyleBackColor = true;
    // 
    // page2_button_banksettings
    // 
    this->page2_button_banksettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_button_banksettings->Location = System::Drawing::Point(286, 316);
    this->page2_button_banksettings->Name = L"page2_button_banksettings";
    this->page2_button_banksettings->Size = System::Drawing::Size(104, 42);
    this->page2_button_banksettings->TabIndex = 14;
    this->page2_button_banksettings->Text = L"Банк";
    this->page2_button_banksettings->UseVisualStyleBackColor = true;
    this->page2_button_banksettings->Click += gcnew System::EventHandler(this, &AuthorizationView::page2_button_banksettings_Click);
    // 
    // page2_button_registration
    // 
    this->page2_button_registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_button_registration->Location = System::Drawing::Point(52, 316);
    this->page2_button_registration->Name = L"page2_button_registration";
    this->page2_button_registration->Size = System::Drawing::Size(209, 42);
    this->page2_button_registration->TabIndex = 13;
    this->page2_button_registration->Text = L"Регистрация";
    this->page2_button_registration->UseVisualStyleBackColor = true;
    this->page2_button_registration->Click += gcnew System::EventHandler(this, &AuthorizationView::page2_button_registration_Click);
    // 
    // page2_tabcontrol_info
    // 
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_client);
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_driver);
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_admin);
    this->page2_tabcontrol_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
    this->page2_tabcontrol_info->ItemSize = System::Drawing::Size(105, 18);
    this->page2_tabcontrol_info->Location = System::Drawing::Point(32, 164);
    this->page2_tabcontrol_info->Name = L"page2_tabcontrol_info";
    this->page2_tabcontrol_info->SelectedIndex = 0;
    this->page2_tabcontrol_info->Size = System::Drawing::Size(385, 146);
    this->page2_tabcontrol_info->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->page2_tabcontrol_info->TabIndex = 12;
    // 
    // page2_tabpage_client
    // 
    this->page2_tabpage_client->Controls->Add(this->pageclient_label_bankcard);
    this->page2_tabpage_client->Controls->Add(this->pageclient_textbox_bankcard);
    this->page2_tabpage_client->Location = System::Drawing::Point(4, 22);
    this->page2_tabpage_client->Name = L"page2_tabpage_client";
    this->page2_tabpage_client->Padding = System::Windows::Forms::Padding(3);
    this->page2_tabpage_client->Size = System::Drawing::Size(377, 120);
    this->page2_tabpage_client->TabIndex = 0;
    this->page2_tabpage_client->Text = L"Клиент";
    this->page2_tabpage_client->UseVisualStyleBackColor = true;
    // 
    // pageclient_label_bankcard
    // 
    this->pageclient_label_bankcard->AutoSize = true;
    this->pageclient_label_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pageclient_label_bankcard->Location = System::Drawing::Point(13, 3);
    this->pageclient_label_bankcard->Name = L"pageclient_label_bankcard";
    this->pageclient_label_bankcard->Size = System::Drawing::Size(175, 17);
    this->pageclient_label_bankcard->TabIndex = 15;
    this->pageclient_label_bankcard->Text = L"Номер банковской карты";
    // 
    // pageclient_textbox_bankcard
    // 
    this->pageclient_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pageclient_textbox_bankcard->Location = System::Drawing::Point(16, 23);
    this->pageclient_textbox_bankcard->MaxLength = 36;
    this->pageclient_textbox_bankcard->Name = L"pageclient_textbox_bankcard";
    this->pageclient_textbox_bankcard->Size = System::Drawing::Size(338, 26);
    this->pageclient_textbox_bankcard->TabIndex = 14;
    // 
    // page2_tabpage_driver
    // 
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_label_bankcard);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_textbox_bankcard);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_label_licence);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_textbox_licence);
    this->page2_tabpage_driver->Location = System::Drawing::Point(4, 22);
    this->page2_tabpage_driver->Name = L"page2_tabpage_driver";
    this->page2_tabpage_driver->Padding = System::Windows::Forms::Padding(3);
    this->page2_tabpage_driver->Size = System::Drawing::Size(377, 120);
    this->page2_tabpage_driver->TabIndex = 1;
    this->page2_tabpage_driver->Text = L"Водитель";
    this->page2_tabpage_driver->UseVisualStyleBackColor = true;
    // 
    // pagedriver_label_bankcard
    // 
    this->pagedriver_label_bankcard->AutoSize = true;
    this->pagedriver_label_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pagedriver_label_bankcard->Location = System::Drawing::Point(13, 54);
    this->pagedriver_label_bankcard->Name = L"pagedriver_label_bankcard";
    this->pagedriver_label_bankcard->Size = System::Drawing::Size(175, 17);
    this->pagedriver_label_bankcard->TabIndex = 17;
    this->pagedriver_label_bankcard->Text = L"Номер банковской карты";
    // 
    // pagedriver_textbox_bankcard
    // 
    this->pagedriver_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pagedriver_textbox_bankcard->Location = System::Drawing::Point(16, 74);
    this->pagedriver_textbox_bankcard->MaxLength = 36;
    this->pagedriver_textbox_bankcard->Name = L"pagedriver_textbox_bankcard";
    this->pagedriver_textbox_bankcard->Size = System::Drawing::Size(338, 26);
    this->pagedriver_textbox_bankcard->TabIndex = 16;
    // 
    // pagedriver_label_licence
    // 
    this->pagedriver_label_licence->AutoSize = true;
    this->pagedriver_label_licence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pagedriver_label_licence->Location = System::Drawing::Point(13, 4);
    this->pagedriver_label_licence->Name = L"pagedriver_label_licence";
    this->pagedriver_label_licence->Size = System::Drawing::Size(120, 17);
    this->pagedriver_label_licence->TabIndex = 15;
    this->pagedriver_label_licence->Text = L"Номер Лицензии";
    // 
    // pagedriver_textbox_licence
    // 
    this->pagedriver_textbox_licence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pagedriver_textbox_licence->Location = System::Drawing::Point(16, 24);
    this->pagedriver_textbox_licence->MaxLength = 36;
    this->pagedriver_textbox_licence->Name = L"pagedriver_textbox_licence";
    this->pagedriver_textbox_licence->Size = System::Drawing::Size(338, 26);
    this->pagedriver_textbox_licence->TabIndex = 14;
    // 
    // page2_tabpage_admin
    // 
    this->page2_tabpage_admin->Controls->Add(this->pageadmin_label_permissions);
    this->page2_tabpage_admin->Controls->Add(this->pageadmin_combobox_permissions);
    this->page2_tabpage_admin->Location = System::Drawing::Point(4, 22);
    this->page2_tabpage_admin->Name = L"page2_tabpage_admin";
    this->page2_tabpage_admin->Size = System::Drawing::Size(377, 120);
    this->page2_tabpage_admin->TabIndex = 2;
    this->page2_tabpage_admin->Text = L"Администратор";
    this->page2_tabpage_admin->UseVisualStyleBackColor = true;
    // 
    // pageadmin_label_permissions
    // 
    this->pageadmin_label_permissions->AutoSize = true;
    this->pageadmin_label_permissions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pageadmin_label_permissions->Location = System::Drawing::Point(13, 5);
    this->pageadmin_label_permissions->Name = L"pageadmin_label_permissions";
    this->pageadmin_label_permissions->Size = System::Drawing::Size(91, 17);
    this->pageadmin_label_permissions->TabIndex = 16;
    this->pageadmin_label_permissions->Text = L"Разрешения";
    // 
    // pageadmin_combobox_permissions
    // 
    this->pageadmin_combobox_permissions->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->pageadmin_combobox_permissions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->pageadmin_combobox_permissions->FormattingEnabled = true;
    this->pageadmin_combobox_permissions->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
        L"Полный доступ", L"Доступ к гаражу",
            L"Доступ к аккаунтам"
    });
    this->pageadmin_combobox_permissions->Location = System::Drawing::Point(16, 25);
    this->pageadmin_combobox_permissions->Name = L"pageadmin_combobox_permissions";
    this->pageadmin_combobox_permissions->Size = System::Drawing::Size(338, 28);
    this->pageadmin_combobox_permissions->TabIndex = 15;
    // 
    // page2_label_age
    // 
    this->page2_label_age->AutoSize = true;
    this->page2_label_age->Location = System::Drawing::Point(283, 112);
    this->page2_label_age->Name = L"page2_label_age";
    this->page2_label_age->Size = System::Drawing::Size(62, 17);
    this->page2_label_age->TabIndex = 11;
    this->page2_label_age->Text = L"Возраст";
    // 
    // page2_numeric_age
    // 
    this->page2_numeric_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->page2_numeric_age->Location = System::Drawing::Point(286, 132);
    this->page2_numeric_age->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->page2_numeric_age->Name = L"page2_numeric_age";
    this->page2_numeric_age->Size = System::Drawing::Size(104, 26);
    this->page2_numeric_age->TabIndex = 10;
    this->page2_numeric_age->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // page2_label_gender
    // 
    this->page2_label_gender->AutoSize = true;
    this->page2_label_gender->Location = System::Drawing::Point(49, 110);
    this->page2_label_gender->Name = L"page2_label_gender";
    this->page2_label_gender->Size = System::Drawing::Size(34, 17);
    this->page2_label_gender->TabIndex = 9;
    this->page2_label_gender->Text = L"Пол";
    // 
    // page2_combobox_gender
    // 
    this->page2_combobox_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->page2_combobox_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->page2_combobox_gender->FormattingEnabled = true;
    this->page2_combobox_gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Мужчина", L"Женщина" });
    this->page2_combobox_gender->Location = System::Drawing::Point(52, 130);
    this->page2_combobox_gender->Name = L"page2_combobox_gender";
    this->page2_combobox_gender->Size = System::Drawing::Size(209, 28);
    this->page2_combobox_gender->TabIndex = 8;
    // 
    // page2_label_username
    // 
    this->page2_label_username->AutoSize = true;
    this->page2_label_username->Location = System::Drawing::Point(29, 61);
    this->page2_label_username->Name = L"page2_label_username";
    this->page2_label_username->Size = System::Drawing::Size(35, 17);
    this->page2_label_username->TabIndex = 7;
    this->page2_label_username->Text = L"Имя";
    // 
    // page2_textbox_username
    // 
    this->page2_textbox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_username->Location = System::Drawing::Point(32, 81);
    this->page2_textbox_username->MaxLength = 40;
    this->page2_textbox_username->Name = L"page2_textbox_username";
    this->page2_textbox_username->Size = System::Drawing::Size(379, 26);
    this->page2_textbox_username->TabIndex = 6;
    // 
    // page2_label_password
    // 
    this->page2_label_password->AutoSize = true;
    this->page2_label_password->Location = System::Drawing::Point(229, 12);
    this->page2_label_password->Name = L"page2_label_password";
    this->page2_label_password->Size = System::Drawing::Size(57, 17);
    this->page2_label_password->TabIndex = 5;
    this->page2_label_password->Text = L"Пароль";
    // 
    // page2_textbox_password
    // 
    this->page2_textbox_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_password->Location = System::Drawing::Point(232, 32);
    this->page2_textbox_password->MaxLength = 40;
    this->page2_textbox_password->Name = L"page2_textbox_password";
    this->page2_textbox_password->Size = System::Drawing::Size(179, 26);
    this->page2_textbox_password->TabIndex = 4;
    this->page2_textbox_password->UseSystemPasswordChar = true;
    // 
    // page2_label_login
    // 
    this->page2_label_login->AutoSize = true;
    this->page2_label_login->Location = System::Drawing::Point(29, 12);
    this->page2_label_login->Name = L"page2_label_login";
    this->page2_label_login->Size = System::Drawing::Size(47, 17);
    this->page2_label_login->TabIndex = 3;
    this->page2_label_login->Text = L"Логин";
    // 
    // page2_textbox_login
    // 
    this->page2_textbox_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_login->Location = System::Drawing::Point(32, 32);
    this->page2_textbox_login->MaxLength = 40;
    this->page2_textbox_login->Name = L"page2_textbox_login";
    this->page2_textbox_login->Size = System::Drawing::Size(179, 26);
    this->page2_textbox_login->TabIndex = 2;
    // 
    // AuthorizationView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(452, 403);
    this->Controls->Add(this->page_list);
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(468, 442);
    this->MinimizeBox = false;
    this->MinimumSize = System::Drawing::Size(468, 442);
    this->Name = L"AuthorizationView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"Авторизация";
    this->page_list->ResumeLayout(false);
    this->page_authorization->ResumeLayout(false);
    this->page_authorization->PerformLayout();
    this->page_registration->ResumeLayout(false);
    this->page_registration->PerformLayout();
    this->page2_tabcontrol_info->ResumeLayout(false);
    this->page2_tabpage_client->ResumeLayout(false);
    this->page2_tabpage_client->PerformLayout();
    this->page2_tabpage_driver->ResumeLayout(false);
    this->page2_tabpage_driver->PerformLayout();
    this->page2_tabpage_admin->ResumeLayout(false);
    this->page2_tabpage_admin->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->page2_numeric_age))->EndInit();
    this->ResumeLayout(false);

}