#include "client_page_view.h"

using namespace Views;

void ClientPageView::InitializeComponent(void)
{
    this->client_tabcontrol = (gcnew System::Windows::Forms::TabControl());
    this->client_page_order = (gcnew System::Windows::Forms::TabPage());
    this->client_button_price = (gcnew System::Windows::Forms::Button());
    this->client_button_money = (gcnew System::Windows::Forms::Button());
    this->client_button_cancel = (gcnew System::Windows::Forms::Button());
    this->client_label_waiting = (gcnew System::Windows::Forms::Label());
    this->client_label_carclass = (gcnew System::Windows::Forms::Label());
    this->client_combobox_carclass = (gcnew System::Windows::Forms::ComboBox());
    this->client_label_cartype = (gcnew System::Windows::Forms::Label());
    this->client_label_address = (gcnew System::Windows::Forms::Label());
    this->client_textbox_address = (gcnew System::Windows::Forms::TextBox());
    this->client_button_order = (gcnew System::Windows::Forms::Button());
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
    this->client_button_bank = (gcnew System::Windows::Forms::Button());
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
    this->client_checkbox_username = (gcnew System::Windows::Forms::CheckBox());
    this->client_checkbox_gender = (gcnew System::Windows::Forms::CheckBox());
    this->client_checkbox_age = (gcnew System::Windows::Forms::CheckBox());
    this->client_checkbox_bankcard = (gcnew System::Windows::Forms::CheckBox());
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
    this->client_page_order->Controls->Add(this->client_button_price);
    this->client_page_order->Controls->Add(this->client_button_money);
    this->client_page_order->Controls->Add(this->client_button_cancel);
    this->client_page_order->Controls->Add(this->client_label_waiting);
    this->client_page_order->Controls->Add(this->client_label_carclass);
    this->client_page_order->Controls->Add(this->client_combobox_carclass);
    this->client_page_order->Controls->Add(this->client_label_cartype);
    this->client_page_order->Controls->Add(this->client_label_address);
    this->client_page_order->Controls->Add(this->client_textbox_address);
    this->client_page_order->Controls->Add(this->client_button_order);
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
    // client_button_price
    // 
    this->client_button_price->Location = System::Drawing::Point(435, 166);
    this->client_button_price->Name = L"client_button_price";
    this->client_button_price->Size = System::Drawing::Size(54, 29);
    this->client_button_price->TabIndex = 19;
    this->client_button_price->Text = L"Цены";
    this->client_button_price->UseVisualStyleBackColor = true;
    this->client_button_price->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_price_Click);
    // 
    // client_button_money
    // 
    this->client_button_money->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->client_button_money->Location = System::Drawing::Point(495, 166);
    this->client_button_money->Name = L"client_button_money";
    this->client_button_money->Size = System::Drawing::Size(29, 29);
    this->client_button_money->TabIndex = 18;
    this->client_button_money->Text = L"$";
    this->client_button_money->UseVisualStyleBackColor = true;
    this->client_button_money->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_money_Click);
    // 
    // client_button_cancel
    // 
    this->client_button_cancel->Enabled = false;
    this->client_button_cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->client_button_cancel->Location = System::Drawing::Point(335, 131);
    this->client_button_cancel->Name = L"client_button_cancel";
    this->client_button_cancel->Size = System::Drawing::Size(283, 29);
    this->client_button_cancel->TabIndex = 17;
    this->client_button_cancel->Text = L"Отменить заказ";
    this->client_button_cancel->UseVisualStyleBackColor = true;
    this->client_button_cancel->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_cancel_Click);
    // 
    // client_label_waiting
    // 
    this->client_label_waiting->AutoSize = true;
    this->client_label_waiting->Location = System::Drawing::Point(28, 391);
    this->client_label_waiting->Name = L"client_label_waiting";
    this->client_label_waiting->Size = System::Drawing::Size(128, 17);
    this->client_label_waiting->TabIndex = 16;
    this->client_label_waiting->Text = L"Состояние заказа";
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
    this->client_combobox_carclass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
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
    this->client_button_order->Text = L"Заказать машину";
    this->client_button_order->UseVisualStyleBackColor = true;
    this->client_button_order->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_order_Click);
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
    this->client_combobox_cartype->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
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
    this->client_listview_car->Location = System::Drawing::Point(28, 201);
    this->client_listview_car->MaximumSize = System::Drawing::Size(590, 183);
    this->client_listview_car->MinimumSize = System::Drawing::Size(590, 183);
    this->client_listview_car->MultiSelect = false;
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
    this->client_page_account->Controls->Add(this->client_checkbox_bankcard);
    this->client_page_account->Controls->Add(this->client_checkbox_age);
    this->client_page_account->Controls->Add(this->client_checkbox_gender);
    this->client_page_account->Controls->Add(this->client_checkbox_username);
    this->client_page_account->Controls->Add(this->client_button_bank);
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
    // client_button_bank
    // 
    this->client_button_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->client_button_bank->Location = System::Drawing::Point(230, 353);
    this->client_button_bank->Name = L"client_button_bank";
    this->client_button_bank->Size = System::Drawing::Size(190, 31);
    this->client_button_bank->TabIndex = 14;
    this->client_button_bank->Text = L"Менеджер банка";
    this->client_button_bank->UseVisualStyleBackColor = true;
    this->client_button_bank->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_bank_Click);
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
    this->client_combobox_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
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
    this->client_button_update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->client_button_update->Location = System::Drawing::Point(23, 353);
    this->client_button_update->Name = L"client_button_update";
    this->client_button_update->Size = System::Drawing::Size(192, 31);
    this->client_button_update->TabIndex = 4;
    this->client_button_update->Text = L"Обновить данные";
    this->client_button_update->UseVisualStyleBackColor = true;
    this->client_button_update->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_update_Click);
    // 
    // client_button_logout
    // 
    this->client_button_logout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->client_button_logout->Location = System::Drawing::Point(435, 353);
    this->client_button_logout->Name = L"client_button_logout";
    this->client_button_logout->Size = System::Drawing::Size(190, 31);
    this->client_button_logout->TabIndex = 2;
    this->client_button_logout->Text = L"Выйти из аккаунта";
    this->client_button_logout->UseVisualStyleBackColor = true;
    this->client_button_logout->Click += gcnew System::EventHandler(this, &ClientPageView::client_button_logout_Click);
    // 
    // client_listview_account
    // 
    this->client_listview_account->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->client_listview_account->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
        this->account_field,
            this->account_data
    });
    this->client_listview_account->HideSelection = false;
    this->client_listview_account->Location = System::Drawing::Point(23, 35);
    this->client_listview_account->MultiSelect = false;
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
    // client_checkbox_username
    // 
    this->client_checkbox_username->AutoSize = true;
    this->client_checkbox_username->Location = System::Drawing::Point(25, 221);
    this->client_checkbox_username->Name = L"client_checkbox_username";
    this->client_checkbox_username->Size = System::Drawing::Size(54, 21);
    this->client_checkbox_username->TabIndex = 15;
    this->client_checkbox_username->Text = L"Имя";
    this->client_checkbox_username->UseVisualStyleBackColor = true;
    // 
    // client_checkbox_gender
    // 
    this->client_checkbox_gender->AutoSize = true;
    this->client_checkbox_gender->Location = System::Drawing::Point(297, 221);
    this->client_checkbox_gender->Name = L"client_checkbox_gender";
    this->client_checkbox_gender->Size = System::Drawing::Size(53, 21);
    this->client_checkbox_gender->TabIndex = 16;
    this->client_checkbox_gender->Text = L"Пол";
    this->client_checkbox_gender->UseVisualStyleBackColor = true;
    // 
    // client_checkbox_age
    // 
    this->client_checkbox_age->AutoSize = true;
    this->client_checkbox_age->Location = System::Drawing::Point(505, 221);
    this->client_checkbox_age->Name = L"client_checkbox_age";
    this->client_checkbox_age->Size = System::Drawing::Size(81, 21);
    this->client_checkbox_age->TabIndex = 17;
    this->client_checkbox_age->Text = L"Возраст";
    this->client_checkbox_age->UseVisualStyleBackColor = true;
    // 
    // client_checkbox_bankcard
    // 
    this->client_checkbox_bankcard->AutoSize = true;
    this->client_checkbox_bankcard->Location = System::Drawing::Point(23, 280);
    this->client_checkbox_bankcard->Name = L"client_checkbox_bankcard";
    this->client_checkbox_bankcard->Size = System::Drawing::Size(194, 21);
    this->client_checkbox_bankcard->TabIndex = 18;
    this->client_checkbox_bankcard->Text = L"Номер банковской карты";
    this->client_checkbox_bankcard->UseVisualStyleBackColor = true;
    // 
    // ClientPageView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(655, 500);
    this->Controls->Add(this->client_tabcontrol);
    this->MaximizeBox = false;
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