#include "admin_page_view.h"

using namespace Views;

void AdminPageView::InitializeComponent(void)
{
    this->admin_tabcontrol = (gcnew System::Windows::Forms::TabControl());
    this->admin_page_garage = (gcnew System::Windows::Forms::TabPage());
    this->admin_label_carspeed = (gcnew System::Windows::Forms::Label());
    this->admin_numeric_carspeed = (gcnew System::Windows::Forms::NumericUpDown());
    this->admin_label_carcount = (gcnew System::Windows::Forms::Label());
    this->admin_label_carclass = (gcnew System::Windows::Forms::Label());
    this->admin_label_carcolor = (gcnew System::Windows::Forms::Label());
    this->admin_label_cartype = (gcnew System::Windows::Forms::Label());
    this->admin_label_carlist = (gcnew System::Windows::Forms::Label());
    this->admin_numeric_carcount = (gcnew System::Windows::Forms::NumericUpDown());
    this->admin_button_upd = (gcnew System::Windows::Forms::Button());
    this->admin_combobox_carclass = (gcnew System::Windows::Forms::ComboBox());
    this->admin_combobox_carcolor = (gcnew System::Windows::Forms::ComboBox());
    this->admin_combobox_cartype = (gcnew System::Windows::Forms::ComboBox());
    this->admin_button_cardelete = (gcnew System::Windows::Forms::Button());
    this->admin_button_caradd = (gcnew System::Windows::Forms::Button());
    this->admin_listview_carlist = (gcnew System::Windows::Forms::ListView());
    this->garage_car_groupguid = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_class = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_type = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_color = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_speed = (gcnew System::Windows::Forms::ColumnHeader());
    this->garage_car_count = (gcnew System::Windows::Forms::ColumnHeader());
    this->admin_page_clients = (gcnew System::Windows::Forms::TabPage());
    this->admin_button_accountinfo = (gcnew System::Windows::Forms::Button());
    this->admin_label_accounts = (gcnew System::Windows::Forms::Label());
    this->admin_button_refresh = (gcnew System::Windows::Forms::Button());
    this->admin_button_delete = (gcnew System::Windows::Forms::Button());
    this->admin_listview_accounts = (gcnew System::Windows::Forms::ListView());
    this->account_guid = (gcnew System::Windows::Forms::ColumnHeader());
    this->account_type = (gcnew System::Windows::Forms::ColumnHeader());
    this->account_state = (gcnew System::Windows::Forms::ColumnHeader());
    this->admin_page_account = (gcnew System::Windows::Forms::TabPage());
    this->admin_checkbox_age = (gcnew System::Windows::Forms::CheckBox());
    this->admin_checkbox_gender = (gcnew System::Windows::Forms::CheckBox());
    this->admin_checkbox_username = (gcnew System::Windows::Forms::CheckBox());
    this->admin_label_account = (gcnew System::Windows::Forms::Label());
    this->admin_numeric_age = (gcnew System::Windows::Forms::NumericUpDown());
    this->admin_combobox_gender = (gcnew System::Windows::Forms::ComboBox());
    this->admin_textbox_username = (gcnew System::Windows::Forms::TextBox());
    this->admin_button_update = (gcnew System::Windows::Forms::Button());
    this->admin_button_logout = (gcnew System::Windows::Forms::Button());
    this->admin_listview_account = (gcnew System::Windows::Forms::ListView());
    this->account_field = (gcnew System::Windows::Forms::ColumnHeader());
    this->account_data = (gcnew System::Windows::Forms::ColumnHeader());
    this->admin_tabcontrol->SuspendLayout();
    this->admin_page_garage->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_carspeed))->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_carcount))->BeginInit();
    this->admin_page_clients->SuspendLayout();
    this->admin_page_account->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_age))->BeginInit();
    this->SuspendLayout();
    // 
    // admin_tabcontrol
    // 
    this->admin_tabcontrol->Controls->Add(this->admin_page_garage);
    this->admin_tabcontrol->Controls->Add(this->admin_page_clients);
    this->admin_tabcontrol->Controls->Add(this->admin_page_account);
    this->admin_tabcontrol->Dock = System::Windows::Forms::DockStyle::Fill;
    this->admin_tabcontrol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->admin_tabcontrol->ItemSize = System::Drawing::Size(215, 25);
    this->admin_tabcontrol->Location = System::Drawing::Point(0, 0);
    this->admin_tabcontrol->Name = L"admin_tabcontrol";
    this->admin_tabcontrol->SelectedIndex = 0;
    this->admin_tabcontrol->Size = System::Drawing::Size(655, 500);
    this->admin_tabcontrol->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
    this->admin_tabcontrol->TabIndex = 1;
    // 
    // admin_page_garage
    // 
    this->admin_page_garage->Controls->Add(this->admin_label_carspeed);
    this->admin_page_garage->Controls->Add(this->admin_numeric_carspeed);
    this->admin_page_garage->Controls->Add(this->admin_label_carcount);
    this->admin_page_garage->Controls->Add(this->admin_label_carclass);
    this->admin_page_garage->Controls->Add(this->admin_label_carcolor);
    this->admin_page_garage->Controls->Add(this->admin_label_cartype);
    this->admin_page_garage->Controls->Add(this->admin_label_carlist);
    this->admin_page_garage->Controls->Add(this->admin_numeric_carcount);
    this->admin_page_garage->Controls->Add(this->admin_button_upd);
    this->admin_page_garage->Controls->Add(this->admin_combobox_carclass);
    this->admin_page_garage->Controls->Add(this->admin_combobox_carcolor);
    this->admin_page_garage->Controls->Add(this->admin_combobox_cartype);
    this->admin_page_garage->Controls->Add(this->admin_button_cardelete);
    this->admin_page_garage->Controls->Add(this->admin_button_caradd);
    this->admin_page_garage->Controls->Add(this->admin_listview_carlist);
    this->admin_page_garage->Location = System::Drawing::Point(4, 29);
    this->admin_page_garage->Name = L"admin_page_garage";
    this->admin_page_garage->Padding = System::Windows::Forms::Padding(3);
    this->admin_page_garage->Size = System::Drawing::Size(647, 467);
    this->admin_page_garage->TabIndex = 0;
    this->admin_page_garage->Text = L"Доступ к гаражу";
    this->admin_page_garage->UseVisualStyleBackColor = true;
    // 
    // admin_label_carspeed
    // 
    this->admin_label_carspeed->AutoSize = true;
    this->admin_label_carspeed->Location = System::Drawing::Point(493, 337);
    this->admin_label_carspeed->Name = L"admin_label_carspeed";
    this->admin_label_carspeed->Size = System::Drawing::Size(73, 17);
    this->admin_label_carspeed->TabIndex = 27;
    this->admin_label_carspeed->Text = L"Скорость ";
    // 
    // admin_numeric_carspeed
    // 
    this->admin_numeric_carspeed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->admin_numeric_carspeed->Location = System::Drawing::Point(496, 357);
    this->admin_numeric_carspeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
    this->admin_numeric_carspeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->admin_numeric_carspeed->Name = L"admin_numeric_carspeed";
    this->admin_numeric_carspeed->Size = System::Drawing::Size(127, 27);
    this->admin_numeric_carspeed->TabIndex = 26;
    this->admin_numeric_carspeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // admin_label_carcount
    // 
    this->admin_label_carcount->AutoSize = true;
    this->admin_label_carcount->Location = System::Drawing::Point(338, 337);
    this->admin_label_carcount->Name = L"admin_label_carcount";
    this->admin_label_carcount->Size = System::Drawing::Size(86, 17);
    this->admin_label_carcount->TabIndex = 25;
    this->admin_label_carcount->Text = L"Количество";
    // 
    // admin_label_carclass
    // 
    this->admin_label_carclass->AutoSize = true;
    this->admin_label_carclass->Location = System::Drawing::Point(25, 337);
    this->admin_label_carclass->Name = L"admin_label_carclass";
    this->admin_label_carclass->Size = System::Drawing::Size(105, 17);
    this->admin_label_carclass->TabIndex = 24;
    this->admin_label_carclass->Text = L"Класс машины";
    // 
    // admin_label_carcolor
    // 
    this->admin_label_carcolor->AutoSize = true;
    this->admin_label_carcolor->Location = System::Drawing::Point(338, 285);
    this->admin_label_carcolor->Name = L"admin_label_carcolor";
    this->admin_label_carcolor->Size = System::Drawing::Size(99, 17);
    this->admin_label_carcolor->TabIndex = 23;
    this->admin_label_carcolor->Text = L"Цвет машины";
    // 
    // admin_label_cartype
    // 
    this->admin_label_cartype->AutoSize = true;
    this->admin_label_cartype->Location = System::Drawing::Point(25, 286);
    this->admin_label_cartype->Name = L"admin_label_cartype";
    this->admin_label_cartype->Size = System::Drawing::Size(91, 17);
    this->admin_label_cartype->TabIndex = 22;
    this->admin_label_cartype->Text = L"Тип машины";
    // 
    // admin_label_carlist
    // 
    this->admin_label_carlist->AutoSize = true;
    this->admin_label_carlist->Location = System::Drawing::Point(25, 9);
    this->admin_label_carlist->Name = L"admin_label_carlist";
    this->admin_label_carlist->Size = System::Drawing::Size(176, 17);
    this->admin_label_carlist->TabIndex = 21;
    this->admin_label_carlist->Text = L"Список доступных машин";
    // 
    // admin_numeric_carcount
    // 
    this->admin_numeric_carcount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->admin_numeric_carcount->Location = System::Drawing::Point(341, 358);
    this->admin_numeric_carcount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
    this->admin_numeric_carcount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->admin_numeric_carcount->Name = L"admin_numeric_carcount";
    this->admin_numeric_carcount->Size = System::Drawing::Size(127, 27);
    this->admin_numeric_carcount->TabIndex = 20;
    this->admin_numeric_carcount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // admin_button_upd
    // 
    this->admin_button_upd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_upd->Location = System::Drawing::Point(439, 409);
    this->admin_button_upd->Name = L"admin_button_upd";
    this->admin_button_upd->Size = System::Drawing::Size(184, 33);
    this->admin_button_upd->TabIndex = 19;
    this->admin_button_upd->Text = L"Обновить";
    this->admin_button_upd->UseVisualStyleBackColor = true;
    this->admin_button_upd->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_upd_Click);
    // 
    // admin_combobox_carclass
    // 
    this->admin_combobox_carclass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->admin_combobox_carclass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_combobox_carclass->FormattingEnabled = true;
    this->admin_combobox_carclass->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Легковая машина", L"Грузовая машина" });
    this->admin_combobox_carclass->Location = System::Drawing::Point(25, 358);
    this->admin_combobox_carclass->Name = L"admin_combobox_carclass";
    this->admin_combobox_carclass->Size = System::Drawing::Size(286, 28);
    this->admin_combobox_carclass->TabIndex = 18;
    // 
    // admin_combobox_carcolor
    // 
    this->admin_combobox_carcolor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->admin_combobox_carcolor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_combobox_carcolor->FormattingEnabled = true;
    this->admin_combobox_carcolor->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
        L"Черный цвет", L"Белый цвет", L"Красный цвет",
            L"Желтый цвет"
    });
    this->admin_combobox_carcolor->Location = System::Drawing::Point(337, 306);
    this->admin_combobox_carcolor->Name = L"admin_combobox_carcolor";
    this->admin_combobox_carcolor->Size = System::Drawing::Size(286, 28);
    this->admin_combobox_carcolor->TabIndex = 17;
    // 
    // admin_combobox_cartype
    // 
    this->admin_combobox_cartype->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->admin_combobox_cartype->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_combobox_cartype->FormattingEnabled = true;
    this->admin_combobox_cartype->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
        L"Эконом машина", L"Детская машина",
            L"Премиум машина"
    });
    this->admin_combobox_cartype->Location = System::Drawing::Point(25, 306);
    this->admin_combobox_cartype->Name = L"admin_combobox_cartype";
    this->admin_combobox_cartype->Size = System::Drawing::Size(286, 28);
    this->admin_combobox_cartype->TabIndex = 16;
    // 
    // admin_button_cardelete
    // 
    this->admin_button_cardelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_cardelete->Location = System::Drawing::Point(234, 409);
    this->admin_button_cardelete->Name = L"admin_button_cardelete";
    this->admin_button_cardelete->Size = System::Drawing::Size(184, 33);
    this->admin_button_cardelete->TabIndex = 15;
    this->admin_button_cardelete->Text = L"Удалить";
    this->admin_button_cardelete->UseVisualStyleBackColor = true;
    this->admin_button_cardelete->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_cardelete_Click);
    // 
    // admin_button_caradd
    // 
    this->admin_button_caradd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_caradd->Location = System::Drawing::Point(25, 409);
    this->admin_button_caradd->Name = L"admin_button_caradd";
    this->admin_button_caradd->Size = System::Drawing::Size(184, 33);
    this->admin_button_caradd->TabIndex = 14;
    this->admin_button_caradd->Text = L"Добавить";
    this->admin_button_caradd->UseVisualStyleBackColor = true;
    this->admin_button_caradd->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_caradd_Click);
    // 
    // admin_listview_carlist
    // 
    this->admin_listview_carlist->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->admin_listview_carlist->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
        this->garage_car_groupguid,
            this->garage_car_class, this->garage_car_type, this->garage_car_color, this->garage_car_speed, this->garage_car_count
    });
    this->admin_listview_carlist->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->admin_listview_carlist->HideSelection = false;
    this->admin_listview_carlist->Location = System::Drawing::Point(25, 29);
    this->admin_listview_carlist->MultiSelect = false;
    this->admin_listview_carlist->Name = L"admin_listview_carlist";
    this->admin_listview_carlist->Size = System::Drawing::Size(598, 253);
    this->admin_listview_carlist->TabIndex = 13;
    this->admin_listview_carlist->UseCompatibleStateImageBehavior = false;
    this->admin_listview_carlist->View = System::Windows::Forms::View::Details;
    // 
    // garage_car_groupguid
    // 
    this->garage_car_groupguid->DisplayIndex = 5;
    this->garage_car_groupguid->Text = L"Guid";
    this->garage_car_groupguid->Width = 1;
    // 
    // garage_car_class
    // 
    this->garage_car_class->DisplayIndex = 0;
    this->garage_car_class->Text = L"Класс машины";
    this->garage_car_class->Width = 150;
    // 
    // garage_car_type
    // 
    this->garage_car_type->DisplayIndex = 1;
    this->garage_car_type->Text = L"Тип машины";
    this->garage_car_type->Width = 150;
    // 
    // garage_car_color
    // 
    this->garage_car_color->DisplayIndex = 2;
    this->garage_car_color->Text = L"Цвет машины";
    this->garage_car_color->Width = 130;
    // 
    // garage_car_speed
    // 
    this->garage_car_speed->DisplayIndex = 3;
    this->garage_car_speed->Text = L"Скорость";
    this->garage_car_speed->Width = 75;
    // 
    // garage_car_count
    // 
    this->garage_car_count->DisplayIndex = 4;
    this->garage_car_count->Text = L"Количество";
    this->garage_car_count->Width = 90;
    // 
    // admin_page_clients
    // 
    this->admin_page_clients->Controls->Add(this->admin_button_accountinfo);
    this->admin_page_clients->Controls->Add(this->admin_label_accounts);
    this->admin_page_clients->Controls->Add(this->admin_button_refresh);
    this->admin_page_clients->Controls->Add(this->admin_button_delete);
    this->admin_page_clients->Controls->Add(this->admin_listview_accounts);
    this->admin_page_clients->Location = System::Drawing::Point(4, 29);
    this->admin_page_clients->Name = L"admin_page_clients";
    this->admin_page_clients->Size = System::Drawing::Size(647, 467);
    this->admin_page_clients->TabIndex = 2;
    this->admin_page_clients->Text = L"Доступ к аккаунтам";
    this->admin_page_clients->UseVisualStyleBackColor = true;
    // 
    // admin_button_accountinfo
    // 
    this->admin_button_accountinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_accountinfo->Location = System::Drawing::Point(27, 360);
    this->admin_button_accountinfo->Name = L"admin_button_accountinfo";
    this->admin_button_accountinfo->Size = System::Drawing::Size(598, 33);
    this->admin_button_accountinfo->TabIndex = 23;
    this->admin_button_accountinfo->Text = L"Открыть подробную информацию";
    this->admin_button_accountinfo->UseVisualStyleBackColor = true;
    this->admin_button_accountinfo->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_accountinfo_Click);
    // 
    // admin_label_accounts
    // 
    this->admin_label_accounts->AutoSize = true;
    this->admin_label_accounts->Location = System::Drawing::Point(24, 9);
    this->admin_label_accounts->Name = L"admin_label_accounts";
    this->admin_label_accounts->Size = System::Drawing::Size(126, 17);
    this->admin_label_accounts->TabIndex = 22;
    this->admin_label_accounts->Text = L"Список аккаунтов";
    // 
    // admin_button_refresh
    // 
    this->admin_button_refresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_refresh->Location = System::Drawing::Point(27, 411);
    this->admin_button_refresh->Name = L"admin_button_refresh";
    this->admin_button_refresh->Size = System::Drawing::Size(286, 33);
    this->admin_button_refresh->TabIndex = 17;
    this->admin_button_refresh->Text = L"Обновить список";
    this->admin_button_refresh->UseVisualStyleBackColor = true;
    this->admin_button_refresh->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_refresh_Click);
    // 
    // admin_button_delete
    // 
    this->admin_button_delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_delete->Location = System::Drawing::Point(339, 411);
    this->admin_button_delete->Name = L"admin_button_delete";
    this->admin_button_delete->Size = System::Drawing::Size(286, 33);
    this->admin_button_delete->TabIndex = 16;
    this->admin_button_delete->Text = L"Удалить аккаунт";
    this->admin_button_delete->UseVisualStyleBackColor = true;
    this->admin_button_delete->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_delete_Click);
    // 
    // admin_listview_accounts
    // 
    this->admin_listview_accounts->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->admin_listview_accounts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
        this->account_guid,
            this->account_type, this->account_state
    });
    this->admin_listview_accounts->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->admin_listview_accounts->HideSelection = false;
    this->admin_listview_accounts->Location = System::Drawing::Point(27, 29);
    this->admin_listview_accounts->MultiSelect = false;
    this->admin_listview_accounts->Name = L"admin_listview_accounts";
    this->admin_listview_accounts->Size = System::Drawing::Size(598, 312);
    this->admin_listview_accounts->TabIndex = 14;
    this->admin_listview_accounts->UseCompatibleStateImageBehavior = false;
    this->admin_listview_accounts->View = System::Windows::Forms::View::Details;
    // 
    // account_guid
    // 
    this->account_guid->Text = L"Аккаунт Guid";
    this->account_guid->Width = 300;
    // 
    // account_type
    // 
    this->account_type->Text = L"Тип аккаунта";
    this->account_type->Width = 150;
    // 
    // account_state
    // 
    this->account_state->Text = L"Авторизирован";
    this->account_state->Width = 140;
    // 
    // admin_page_account
    // 
    this->admin_page_account->Controls->Add(this->admin_checkbox_age);
    this->admin_page_account->Controls->Add(this->admin_checkbox_gender);
    this->admin_page_account->Controls->Add(this->admin_checkbox_username);
    this->admin_page_account->Controls->Add(this->admin_label_account);
    this->admin_page_account->Controls->Add(this->admin_numeric_age);
    this->admin_page_account->Controls->Add(this->admin_combobox_gender);
    this->admin_page_account->Controls->Add(this->admin_textbox_username);
    this->admin_page_account->Controls->Add(this->admin_button_update);
    this->admin_page_account->Controls->Add(this->admin_button_logout);
    this->admin_page_account->Controls->Add(this->admin_listview_account);
    this->admin_page_account->Location = System::Drawing::Point(4, 29);
    this->admin_page_account->Name = L"admin_page_account";
    this->admin_page_account->Padding = System::Windows::Forms::Padding(3);
    this->admin_page_account->Size = System::Drawing::Size(647, 467);
    this->admin_page_account->TabIndex = 1;
    this->admin_page_account->Text = L"Аккаунт";
    this->admin_page_account->UseVisualStyleBackColor = true;
    // 
    // admin_checkbox_age
    // 
    this->admin_checkbox_age->AutoSize = true;
    this->admin_checkbox_age->Location = System::Drawing::Point(505, 221);
    this->admin_checkbox_age->Name = L"admin_checkbox_age";
    this->admin_checkbox_age->Size = System::Drawing::Size(81, 21);
    this->admin_checkbox_age->TabIndex = 17;
    this->admin_checkbox_age->Text = L"Возраст";
    this->admin_checkbox_age->UseVisualStyleBackColor = true;
    // 
    // admin_checkbox_gender
    // 
    this->admin_checkbox_gender->AutoSize = true;
    this->admin_checkbox_gender->Location = System::Drawing::Point(297, 221);
    this->admin_checkbox_gender->Name = L"admin_checkbox_gender";
    this->admin_checkbox_gender->Size = System::Drawing::Size(53, 21);
    this->admin_checkbox_gender->TabIndex = 16;
    this->admin_checkbox_gender->Text = L"Пол";
    this->admin_checkbox_gender->UseVisualStyleBackColor = true;
    // 
    // admin_checkbox_username
    // 
    this->admin_checkbox_username->AutoSize = true;
    this->admin_checkbox_username->Location = System::Drawing::Point(25, 221);
    this->admin_checkbox_username->Name = L"admin_checkbox_username";
    this->admin_checkbox_username->Size = System::Drawing::Size(54, 21);
    this->admin_checkbox_username->TabIndex = 15;
    this->admin_checkbox_username->Text = L"Имя";
    this->admin_checkbox_username->UseVisualStyleBackColor = true;
    // 
    // admin_label_account
    // 
    this->admin_label_account->AutoSize = true;
    this->admin_label_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->admin_label_account->Location = System::Drawing::Point(20, 15);
    this->admin_label_account->Name = L"admin_label_account";
    this->admin_label_account->Size = System::Drawing::Size(177, 17);
    this->admin_label_account->TabIndex = 9;
    this->admin_label_account->Text = L"Информация по аккаунту";
    // 
    // admin_numeric_age
    // 
    this->admin_numeric_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->admin_numeric_age->Location = System::Drawing::Point(505, 248);
    this->admin_numeric_age->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    this->admin_numeric_age->Name = L"admin_numeric_age";
    this->admin_numeric_age->Size = System::Drawing::Size(120, 27);
    this->admin_numeric_age->TabIndex = 8;
    this->admin_numeric_age->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
    // 
    // admin_combobox_gender
    // 
    this->admin_combobox_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->admin_combobox_gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_combobox_gender->FormattingEnabled = true;
    this->admin_combobox_gender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Мужчина", L"Женщина" });
    this->admin_combobox_gender->Location = System::Drawing::Point(297, 247);
    this->admin_combobox_gender->Name = L"admin_combobox_gender";
    this->admin_combobox_gender->Size = System::Drawing::Size(186, 28);
    this->admin_combobox_gender->TabIndex = 6;
    // 
    // admin_textbox_username
    // 
    this->admin_textbox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
    this->admin_textbox_username->Location = System::Drawing::Point(23, 247);
    this->admin_textbox_username->MaxLength = 40;
    this->admin_textbox_username->Name = L"admin_textbox_username";
    this->admin_textbox_username->Size = System::Drawing::Size(249, 27);
    this->admin_textbox_username->TabIndex = 5;
    // 
    // admin_button_update
    // 
    this->admin_button_update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_update->Location = System::Drawing::Point(23, 296);
    this->admin_button_update->Name = L"admin_button_update";
    this->admin_button_update->Size = System::Drawing::Size(290, 31);
    this->admin_button_update->TabIndex = 4;
    this->admin_button_update->Text = L"Обновить данные";
    this->admin_button_update->UseVisualStyleBackColor = true;
    this->admin_button_update->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_update_Click);
    // 
    // admin_button_logout
    // 
    this->admin_button_logout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->admin_button_logout->Location = System::Drawing::Point(335, 296);
    this->admin_button_logout->Name = L"admin_button_logout";
    this->admin_button_logout->Size = System::Drawing::Size(290, 31);
    this->admin_button_logout->TabIndex = 2;
    this->admin_button_logout->Text = L"Выйти из аккаунта";
    this->admin_button_logout->UseVisualStyleBackColor = true;
    this->admin_button_logout->Click += gcnew System::EventHandler(this, &AdminPageView::admin_button_logout_Click);
    // 
    // admin_listview_account
    // 
    this->admin_listview_account->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->admin_listview_account->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
        this->account_field,
            this->account_data
    });
    this->admin_listview_account->HideSelection = false;
    this->admin_listview_account->Location = System::Drawing::Point(23, 35);
    this->admin_listview_account->MultiSelect = false;
    this->admin_listview_account->Name = L"admin_listview_account";
    this->admin_listview_account->Size = System::Drawing::Size(602, 178);
    this->admin_listview_account->TabIndex = 1;
    this->admin_listview_account->UseCompatibleStateImageBehavior = false;
    this->admin_listview_account->View = System::Windows::Forms::View::Details;
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
    // AdminPageView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(655, 500);
    this->Controls->Add(this->admin_tabcontrol);
    this->MaximumSize = System::Drawing::Size(671, 539);
    this->MinimumSize = System::Drawing::Size(671, 539);
    this->Name = L"AdminPageView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"Страница Администратора";
    this->admin_tabcontrol->ResumeLayout(false);
    this->admin_page_garage->ResumeLayout(false);
    this->admin_page_garage->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_carspeed))->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_carcount))->EndInit();
    this->admin_page_clients->ResumeLayout(false);
    this->admin_page_clients->PerformLayout();
    this->admin_page_account->ResumeLayout(false);
    this->admin_page_account->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->admin_numeric_age))->EndInit();
    this->ResumeLayout(false);

}