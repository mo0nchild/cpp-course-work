#include "authorization_view.h"

using namespace Views;

void AuthorizationView::InitializeComponent(void)
{
    this->page_list = (gcnew System::Windows::Forms::TabControl());
    this->page_authorization = (gcnew System::Windows::Forms::TabPage());
    this->page1_label_suplogo3 = (gcnew System::Windows::Forms::Label());
    this->page1_label_suplogo2 = (gcnew System::Windows::Forms::Label());
    this->page1_picturebox_imagelogo = (gcnew System::Windows::Forms::PictureBox());
    this->page1_label_suplogo1 = (gcnew System::Windows::Forms::Label());
    this->page1_label_mainlogo = (gcnew System::Windows::Forms::Label());
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
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->page1_picturebox_imagelogo))->BeginInit();
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
    this->page_list->ItemSize = System::Drawing::Size(223, 25);
    this->page_list->Location = System::Drawing::Point(0, 0);
    this->page_list->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page_list->Multiline = true;
    this->page_list->Name = L"page_list";
    this->page_list->SelectedIndex = 0;
    this->page_list->Size = System::Drawing::Size(600, 484);
    this->page_list->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->page_list->TabIndex = 0;
    // 
    // page_authorization
    // 
    this->page_authorization->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
        static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
    this->page_authorization->Controls->Add(this->page1_label_suplogo3);
    this->page_authorization->Controls->Add(this->page1_label_suplogo2);
    this->page_authorization->Controls->Add(this->page1_picturebox_imagelogo);
    this->page_authorization->Controls->Add(this->page1_label_suplogo1);
    this->page_authorization->Controls->Add(this->page1_label_mainlogo);
    this->page_authorization->Controls->Add(this->page1_button_authorize);
    this->page_authorization->Controls->Add(this->page1_label_password);
    this->page_authorization->Controls->Add(this->page1_textbox_password);
    this->page_authorization->Controls->Add(this->page1_label_login);
    this->page_authorization->Controls->Add(this->page1_textbox_login);
    this->page_authorization->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->page_authorization->ForeColor = System::Drawing::Color::White;
    this->page_authorization->Location = System::Drawing::Point(4, 29);
    this->page_authorization->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page_authorization->Name = L"page_authorization";
    this->page_authorization->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page_authorization->Size = System::Drawing::Size(592, 451);
    this->page_authorization->TabIndex = 0;
    this->page_authorization->Text = L"�����������";
    // 
    // page1_label_suplogo3
    // 
    this->page1_label_suplogo3->AutoSize = true;
    this->page1_label_suplogo3->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_suplogo3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
    this->page1_label_suplogo3->ForeColor = System::Drawing::Color::Aquamarine;
    this->page1_label_suplogo3->Location = System::Drawing::Point(172, 100);
    this->page1_label_suplogo3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_suplogo3->Name = L"page1_label_suplogo3";
    this->page1_label_suplogo3->Size = System::Drawing::Size(59, 29);
    this->page1_label_suplogo3->TabIndex = 21;
    this->page1_label_suplogo3->Text = L"���";
    // 
    // page1_label_suplogo2
    // 
    this->page1_label_suplogo2->AutoSize = true;
    this->page1_label_suplogo2->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_suplogo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
    this->page1_label_suplogo2->Location = System::Drawing::Point(137, 100);
    this->page1_label_suplogo2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_suplogo2->Name = L"page1_label_suplogo2";
    this->page1_label_suplogo2->Size = System::Drawing::Size(252, 29);
    this->page1_label_suplogo2->TabIndex = 8;
    this->page1_label_suplogo2->Text = L"��          ������ � ��� ";
    // 
    // page1_picturebox_imagelogo
    // 
    this->page1_picturebox_imagelogo->Location = System::Drawing::Point(435, 52);
    this->page1_picturebox_imagelogo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page1_picturebox_imagelogo->Name = L"page1_picturebox_imagelogo";
    this->page1_picturebox_imagelogo->Size = System::Drawing::Size(85, 78);
    this->page1_picturebox_imagelogo->TabIndex = 7;
    this->page1_picturebox_imagelogo->TabStop = false;
    // 
    // page1_label_suplogo1
    // 
    this->page1_label_suplogo1->AutoSize = true;
    this->page1_label_suplogo1->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_suplogo1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
    this->page1_label_suplogo1->ForeColor = System::Drawing::Color::Aquamarine;
    this->page1_label_suplogo1->Location = System::Drawing::Point(100, 100);
    this->page1_label_suplogo1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_suplogo1->Name = L"page1_label_suplogo1";
    this->page1_label_suplogo1->Size = System::Drawing::Size(41, 29);
    this->page1_label_suplogo1->TabIndex = 20;
    this->page1_label_suplogo1->Text = L"��";
    this->page1_label_suplogo1->Click += gcnew System::EventHandler(this, &AuthorizationView::page1_label_suplogo1_Click);
    // 
    // page1_label_mainlogo
    // 
    this->page1_label_mainlogo->AutoSize = true;
    this->page1_label_mainlogo->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_mainlogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26));
    this->page1_label_mainlogo->Location = System::Drawing::Point(71, 52);
    this->page1_label_mainlogo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_mainlogo->Name = L"page1_label_mainlogo";
    this->page1_label_mainlogo->Size = System::Drawing::Size(335, 52);
    this->page1_label_mainlogo->TabIndex = 5;
    this->page1_label_mainlogo->Text = L"������� �����";
    // 
    // page1_button_authorize
    // 
    this->page1_button_authorize->BackColor = System::Drawing::Color::White;
    this->page1_button_authorize->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->page1_button_authorize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_button_authorize->ForeColor = System::Drawing::Color::Black;
    this->page1_button_authorize->Location = System::Drawing::Point(127, 351);
    this->page1_button_authorize->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page1_button_authorize->Name = L"page1_button_authorize";
    this->page1_button_authorize->Size = System::Drawing::Size(336, 52);
    this->page1_button_authorize->TabIndex = 4;
    this->page1_button_authorize->Text = L"����� � �������";
    this->page1_button_authorize->UseVisualStyleBackColor = false;
    this->page1_button_authorize->Click += gcnew System::EventHandler(this, &AuthorizationView::page1_button_authorize_Click);
    // 
    // page1_label_password
    // 
    this->page1_label_password->AutoSize = true;
    this->page1_label_password->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_password->Location = System::Drawing::Point(76, 247);
    this->page1_label_password->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_password->Name = L"page1_label_password";
    this->page1_label_password->Size = System::Drawing::Size(72, 20);
    this->page1_label_password->TabIndex = 3;
    this->page1_label_password->Text = L"������";
    // 
    // page1_textbox_password
    // 
    this->page1_textbox_password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page1_textbox_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_textbox_password->Location = System::Drawing::Point(80, 272);
    this->page1_textbox_password->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page1_textbox_password->MaxLength = 40;
    this->page1_textbox_password->Name = L"page1_textbox_password";
    this->page1_textbox_password->Size = System::Drawing::Size(429, 30);
    this->page1_textbox_password->TabIndex = 2;
    this->page1_textbox_password->UseSystemPasswordChar = true;
    // 
    // page1_label_login
    // 
    this->page1_label_login->AutoSize = true;
    this->page1_label_login->BackColor = System::Drawing::Color::Transparent;
    this->page1_label_login->Location = System::Drawing::Point(76, 155);
    this->page1_label_login->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page1_label_login->Name = L"page1_label_login";
    this->page1_label_login->Size = System::Drawing::Size(59, 20);
    this->page1_label_login->TabIndex = 1;
    this->page1_label_login->Text = L"�����";
    // 
    // page1_textbox_login
    // 
    this->page1_textbox_login->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page1_textbox_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page1_textbox_login->Location = System::Drawing::Point(80, 180);
    this->page1_textbox_login->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page1_textbox_login->MaxLength = 40;
    this->page1_textbox_login->Name = L"page1_textbox_login";
    this->page1_textbox_login->Size = System::Drawing::Size(429, 30);
    this->page1_textbox_login->TabIndex = 0;
    // 
    // page_registration
    // 
    this->page_registration->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
        static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
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
    this->page_registration->ForeColor = System::Drawing::Color::Black;
    this->page_registration->Location = System::Drawing::Point(4, 29);
    this->page_registration->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page_registration->Name = L"page_registration";
    this->page_registration->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page_registration->Size = System::Drawing::Size(592, 451);
    this->page_registration->TabIndex = 1;
    this->page_registration->Text = L"�����������";
    // 
    // page2_button_banksettings
    // 
    this->page2_button_banksettings->BackColor = System::Drawing::Color::White;
    this->page2_button_banksettings->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->page2_button_banksettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_button_banksettings->Location = System::Drawing::Point(381, 385);
    this->page2_button_banksettings->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_button_banksettings->Name = L"page2_button_banksettings";
    this->page2_button_banksettings->Size = System::Drawing::Size(139, 52);
    this->page2_button_banksettings->TabIndex = 14;
    this->page2_button_banksettings->Text = L"����";
    this->page2_button_banksettings->UseVisualStyleBackColor = false;
    this->page2_button_banksettings->Click += gcnew System::EventHandler(this, &AuthorizationView::page2_button_banksettings_Click);
    // 
    // page2_button_registration
    // 
    this->page2_button_registration->BackColor = System::Drawing::Color::White;
    this->page2_button_registration->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->page2_button_registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_button_registration->Location = System::Drawing::Point(69, 385);
    this->page2_button_registration->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_button_registration->Name = L"page2_button_registration";
    this->page2_button_registration->Size = System::Drawing::Size(279, 52);
    this->page2_button_registration->TabIndex = 13;
    this->page2_button_registration->Text = L"�����������";
    this->page2_button_registration->UseVisualStyleBackColor = false;
    this->page2_button_registration->Click += gcnew System::EventHandler(this, &AuthorizationView::page2_button_registration_Click);
    // 
    // page2_tabcontrol_info
    // 
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_client);
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_driver);
    this->page2_tabcontrol_info->Controls->Add(this->page2_tabpage_admin);
    this->page2_tabcontrol_info->Cursor = System::Windows::Forms::Cursors::Default;
    this->page2_tabcontrol_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->page2_tabcontrol_info->ItemSize = System::Drawing::Size(125, 20);
    this->page2_tabcontrol_info->Location = System::Drawing::Point(43, 194);
    this->page2_tabcontrol_info->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabcontrol_info->Name = L"page2_tabcontrol_info";
    this->page2_tabcontrol_info->SelectedIndex = 0;
    this->page2_tabcontrol_info->Size = System::Drawing::Size(513, 180);
    this->page2_tabcontrol_info->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->page2_tabcontrol_info->TabIndex = 12;
    // 
    // page2_tabpage_client
    // 
    this->page2_tabpage_client->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
        static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
    this->page2_tabpage_client->Controls->Add(this->pageclient_label_bankcard);
    this->page2_tabpage_client->Controls->Add(this->pageclient_textbox_bankcard);
    this->page2_tabpage_client->Location = System::Drawing::Point(4, 24);
    this->page2_tabpage_client->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabpage_client->Name = L"page2_tabpage_client";
    this->page2_tabpage_client->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabpage_client->Size = System::Drawing::Size(505, 152);
    this->page2_tabpage_client->TabIndex = 0;
    this->page2_tabpage_client->Text = L"������";
    // 
    // pageclient_label_bankcard
    // 
    this->pageclient_label_bankcard->AutoSize = true;
    this->pageclient_label_bankcard->BackColor = System::Drawing::Color::Transparent;
    this->pageclient_label_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pageclient_label_bankcard->ForeColor = System::Drawing::Color::White;
    this->pageclient_label_bankcard->Location = System::Drawing::Point(17, 4);
    this->pageclient_label_bankcard->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->pageclient_label_bankcard->Name = L"pageclient_label_bankcard";
    this->pageclient_label_bankcard->Size = System::Drawing::Size(222, 20);
    this->pageclient_label_bankcard->TabIndex = 15;
    this->pageclient_label_bankcard->Text = L"����� ���������� �����";
    // 
    // pageclient_textbox_bankcard
    // 
    this->pageclient_textbox_bankcard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->pageclient_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pageclient_textbox_bankcard->Location = System::Drawing::Point(21, 28);
    this->pageclient_textbox_bankcard->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->pageclient_textbox_bankcard->MaxLength = 36;
    this->pageclient_textbox_bankcard->Name = L"pageclient_textbox_bankcard";
    this->pageclient_textbox_bankcard->Size = System::Drawing::Size(450, 30);
    this->pageclient_textbox_bankcard->TabIndex = 14;
    // 
    // page2_tabpage_driver
    // 
    this->page2_tabpage_driver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
        static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_label_bankcard);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_textbox_bankcard);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_label_licence);
    this->page2_tabpage_driver->Controls->Add(this->pagedriver_textbox_licence);
    this->page2_tabpage_driver->Location = System::Drawing::Point(4, 24);
    this->page2_tabpage_driver->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabpage_driver->Name = L"page2_tabpage_driver";
    this->page2_tabpage_driver->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabpage_driver->Size = System::Drawing::Size(505, 152);
    this->page2_tabpage_driver->TabIndex = 1;
    this->page2_tabpage_driver->Text = L"��������";
    // 
    // pagedriver_label_bankcard
    // 
    this->pagedriver_label_bankcard->AutoSize = true;
    this->pagedriver_label_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pagedriver_label_bankcard->ForeColor = System::Drawing::Color::White;
    this->pagedriver_label_bankcard->Location = System::Drawing::Point(17, 66);
    this->pagedriver_label_bankcard->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->pagedriver_label_bankcard->Name = L"pagedriver_label_bankcard";
    this->pagedriver_label_bankcard->Size = System::Drawing::Size(222, 20);
    this->pagedriver_label_bankcard->TabIndex = 17;
    this->pagedriver_label_bankcard->Text = L"����� ���������� �����";
    // 
    // pagedriver_textbox_bankcard
    // 
    this->pagedriver_textbox_bankcard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->pagedriver_textbox_bankcard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pagedriver_textbox_bankcard->Location = System::Drawing::Point(21, 91);
    this->pagedriver_textbox_bankcard->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->pagedriver_textbox_bankcard->MaxLength = 36;
    this->pagedriver_textbox_bankcard->Name = L"pagedriver_textbox_bankcard";
    this->pagedriver_textbox_bankcard->Size = System::Drawing::Size(450, 30);
    this->pagedriver_textbox_bankcard->TabIndex = 16;
    // 
    // pagedriver_label_licence
    // 
    this->pagedriver_label_licence->AutoSize = true;
    this->pagedriver_label_licence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pagedriver_label_licence->ForeColor = System::Drawing::Color::White;
    this->pagedriver_label_licence->Location = System::Drawing::Point(17, 5);
    this->pagedriver_label_licence->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->pagedriver_label_licence->Name = L"pagedriver_label_licence";
    this->pagedriver_label_licence->Size = System::Drawing::Size(150, 20);
    this->pagedriver_label_licence->TabIndex = 15;
    this->pagedriver_label_licence->Text = L"����� ��������";
    // 
    // pagedriver_textbox_licence
    // 
    this->pagedriver_textbox_licence->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->pagedriver_textbox_licence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->pagedriver_textbox_licence->Location = System::Drawing::Point(21, 30);
    this->pagedriver_textbox_licence->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->pagedriver_textbox_licence->MaxLength = 36;
    this->pagedriver_textbox_licence->Name = L"pagedriver_textbox_licence";
    this->pagedriver_textbox_licence->Size = System::Drawing::Size(450, 30);
    this->pagedriver_textbox_licence->TabIndex = 14;
    // 
    // page2_tabpage_admin
    // 
    this->page2_tabpage_admin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
        static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
    this->page2_tabpage_admin->Controls->Add(this->pageadmin_label_permissions);
    this->page2_tabpage_admin->Controls->Add(this->pageadmin_combobox_permissions);
    this->page2_tabpage_admin->Location = System::Drawing::Point(4, 24);
    this->page2_tabpage_admin->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_tabpage_admin->Name = L"page2_tabpage_admin";
    this->page2_tabpage_admin->Size = System::Drawing::Size(505, 152);
    this->page2_tabpage_admin->TabIndex = 2;
    this->page2_tabpage_admin->Text = L"�������������";
    // 
    // pageadmin_label_permissions
    // 
    this->pageadmin_label_permissions->AutoSize = true;
    this->pageadmin_label_permissions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->pageadmin_label_permissions->ForeColor = System::Drawing::Color::White;
    this->pageadmin_label_permissions->Location = System::Drawing::Point(17, 6);
    this->pageadmin_label_permissions->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->pageadmin_label_permissions->Name = L"pageadmin_label_permissions";
    this->pageadmin_label_permissions->Size = System::Drawing::Size(113, 20);
    this->pageadmin_label_permissions->TabIndex = 16;
    this->pageadmin_label_permissions->Text = L"����������";
    // 
    // pageadmin_combobox_permissions
    // 
    this->pageadmin_combobox_permissions->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->pageadmin_combobox_permissions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->pageadmin_combobox_permissions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->pageadmin_combobox_permissions->FormattingEnabled = true;
    this->pageadmin_combobox_permissions->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
        L"������ ������", L"������ � ������",
            L"������ � ���������"
    });
    this->pageadmin_combobox_permissions->Location = System::Drawing::Point(21, 31);
    this->pageadmin_combobox_permissions->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->pageadmin_combobox_permissions->Name = L"pageadmin_combobox_permissions";
    this->pageadmin_combobox_permissions->Size = System::Drawing::Size(449, 33);
    this->pageadmin_combobox_permissions->TabIndex = 15;
    // 
    // page2_label_age
    // 
    this->page2_label_age->AutoSize = true;
    this->page2_label_age->ForeColor = System::Drawing::Color::White;
    this->page2_label_age->Location = System::Drawing::Point(377, 128);
    this->page2_label_age->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page2_label_age->Name = L"page2_label_age";
    this->page2_label_age->Size = System::Drawing::Size(79, 20);
    this->page2_label_age->TabIndex = 11;
    this->page2_label_age->Text = L"�������";
    // 
    // page2_numeric_age
    // 
    this->page2_numeric_age->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page2_numeric_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->page2_numeric_age->Location = System::Drawing::Point(381, 153);
    this->page2_numeric_age->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_numeric_age->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->page2_numeric_age->Name = L"page2_numeric_age";
    this->page2_numeric_age->Size = System::Drawing::Size(139, 30);
    this->page2_numeric_age->TabIndex = 10;
    this->page2_numeric_age->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    this->page2_numeric_age->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // page2_label_gender
    // 
    this->page2_label_gender->AutoSize = true;
    this->page2_label_gender->ForeColor = System::Drawing::Color::White;
    this->page2_label_gender->Location = System::Drawing::Point(65, 126);
    this->page2_label_gender->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page2_label_gender->Name = L"page2_label_gender";
    this->page2_label_gender->Size = System::Drawing::Size(42, 20);
    this->page2_label_gender->TabIndex = 9;
    this->page2_label_gender->Text = L"���";
    // 
    // page2_combobox_gender
    // 
    this->page2_combobox_gender->BackColor = System::Drawing::Color::White;
    this->page2_combobox_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->page2_combobox_gender->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->page2_combobox_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->page2_combobox_gender->FormattingEnabled = true;
    this->page2_combobox_gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�������", L"�������" });
    this->page2_combobox_gender->Location = System::Drawing::Point(69, 150);
    this->page2_combobox_gender->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_combobox_gender->Name = L"page2_combobox_gender";
    this->page2_combobox_gender->Size = System::Drawing::Size(277, 33);
    this->page2_combobox_gender->TabIndex = 8;
    // 
    // page2_label_username
    // 
    this->page2_label_username->AutoSize = true;
    this->page2_label_username->ForeColor = System::Drawing::Color::White;
    this->page2_label_username->Location = System::Drawing::Point(39, 68);
    this->page2_label_username->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page2_label_username->Name = L"page2_label_username";
    this->page2_label_username->Size = System::Drawing::Size(105, 20);
    this->page2_label_username->TabIndex = 7;
    this->page2_label_username->Text = L"��� (min=8)";
    // 
    // page2_textbox_username
    // 
    this->page2_textbox_username->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page2_textbox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_username->Location = System::Drawing::Point(43, 92);
    this->page2_textbox_username->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_textbox_username->MaxLength = 40;
    this->page2_textbox_username->Name = L"page2_textbox_username";
    this->page2_textbox_username->Size = System::Drawing::Size(505, 30);
    this->page2_textbox_username->TabIndex = 6;
    // 
    // page2_label_password
    // 
    this->page2_label_password->AutoSize = true;
    this->page2_label_password->ForeColor = System::Drawing::Color::White;
    this->page2_label_password->Location = System::Drawing::Point(305, 7);
    this->page2_label_password->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page2_label_password->Name = L"page2_label_password";
    this->page2_label_password->Size = System::Drawing::Size(135, 20);
    this->page2_label_password->TabIndex = 5;
    this->page2_label_password->Text = L"������ (min=4)";
    // 
    // page2_textbox_password
    // 
    this->page2_textbox_password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page2_textbox_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_password->Location = System::Drawing::Point(309, 32);
    this->page2_textbox_password->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_textbox_password->MaxLength = 40;
    this->page2_textbox_password->Name = L"page2_textbox_password";
    this->page2_textbox_password->Size = System::Drawing::Size(238, 30);
    this->page2_textbox_password->TabIndex = 4;
    this->page2_textbox_password->UseSystemPasswordChar = true;
    // 
    // page2_label_login
    // 
    this->page2_label_login->AutoSize = true;
    this->page2_label_login->ForeColor = System::Drawing::Color::White;
    this->page2_label_login->Location = System::Drawing::Point(39, 7);
    this->page2_label_login->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->page2_label_login->Name = L"page2_label_login";
    this->page2_label_login->Size = System::Drawing::Size(122, 20);
    this->page2_label_login->TabIndex = 3;
    this->page2_label_login->Text = L"����� (min=4)";
    // 
    // page2_textbox_login
    // 
    this->page2_textbox_login->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->page2_textbox_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->page2_textbox_login->Location = System::Drawing::Point(43, 32);
    this->page2_textbox_login->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->page2_textbox_login->MaxLength = 40;
    this->page2_textbox_login->Name = L"page2_textbox_login";
    this->page2_textbox_login->Size = System::Drawing::Size(238, 30);
    this->page2_textbox_login->TabIndex = 2;
    // 
    // AuthorizationView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(600, 484);
    this->Controls->Add(this->page_list);
    this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(618, 531);
    this->MinimizeBox = false;
    this->MinimumSize = System::Drawing::Size(618, 531);
    this->Name = L"AuthorizationView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"�����������";
    this->page_list->ResumeLayout(false);
    this->page_authorization->ResumeLayout(false);
    this->page_authorization->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->page1_picturebox_imagelogo))->EndInit();
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