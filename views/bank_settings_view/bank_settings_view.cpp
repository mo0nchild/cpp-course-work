#include "bank_settings_view.h"

using namespace Views;

void BankSettingsView::InitializeComponent(void)
{
    this->button_create_bank = (gcnew System::Windows::Forms::Button());
    this->button_reload = (gcnew System::Windows::Forms::Button());
    this->label_bank = (gcnew System::Windows::Forms::Label());
    this->listview_bank = (gcnew System::Windows::Forms::ListView());
    this->column_guid = (gcnew System::Windows::Forms::ColumnHeader());
    this->column_money = (gcnew System::Windows::Forms::ColumnHeader());
    this->button_operation = (gcnew System::Windows::Forms::Button());
    this->button_copy = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // button_create_bank
    // 
    this->button_create_bank->BackColor = System::Drawing::Color::White;
    this->button_create_bank->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->button_create_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->button_create_bank->Location = System::Drawing::Point(21, 307);
    this->button_create_bank->Name = L"button_create_bank";
    this->button_create_bank->Size = System::Drawing::Size(116, 54);
    this->button_create_bank->TabIndex = 1;
    this->button_create_bank->Text = L"Создать аккаунт";
    this->button_create_bank->UseVisualStyleBackColor = false;
    this->button_create_bank->Click += gcnew System::EventHandler(this, &BankSettingsView::button_create_bank_Click);
    // 
    // button_reload
    // 
    this->button_reload->BackColor = System::Drawing::Color::White;
    this->button_reload->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->button_reload->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->button_reload->Location = System::Drawing::Point(290, 307);
    this->button_reload->Name = L"button_reload";
    this->button_reload->Size = System::Drawing::Size(116, 54);
    this->button_reload->TabIndex = 2;
    this->button_reload->Text = L"Обновить данные";
    this->button_reload->UseVisualStyleBackColor = false;
    this->button_reload->Click += gcnew System::EventHandler(this, &BankSettingsView::button_reload_Click);
    // 
    // label_bank
    // 
    this->label_bank->AutoSize = true;
    this->label_bank->BackColor = System::Drawing::Color::Transparent;
    this->label_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->label_bank->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    this->label_bank->Location = System::Drawing::Point(19, 17);
    this->label_bank->Name = L"label_bank";
    this->label_bank->Size = System::Drawing::Size(228, 20);
    this->label_bank->TabIndex = 3;
    this->label_bank->Text = L"Список доступных аккаунтов";
    // 
    // listview_bank
    // 
    this->listview_bank->BackColor = System::Drawing::Color::White;
    this->listview_bank->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->listview_bank->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
        this->column_guid,
            this->column_money
    });
    this->listview_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->listview_bank->ForeColor = System::Drawing::Color::Black;
    this->listview_bank->GridLines = true;
    this->listview_bank->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->listview_bank->HideSelection = false;
    this->listview_bank->Location = System::Drawing::Point(21, 43);
    this->listview_bank->MultiSelect = false;
    this->listview_bank->Name = L"listview_bank";
    this->listview_bank->Size = System::Drawing::Size(520, 253);
    this->listview_bank->TabIndex = 4;
    this->listview_bank->UseCompatibleStateImageBehavior = false;
    this->listview_bank->View = System::Windows::Forms::View::Details;
    // 
    // column_guid
    // 
    this->column_guid->Tag = L"";
    this->column_guid->Text = L"Аккаунт Guid";
    this->column_guid->Width = 340;
    // 
    // column_money
    // 
    this->column_money->Text = L"Баланс";
    this->column_money->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    this->column_money->Width = 180;
    // 
    // button_operation
    // 
    this->button_operation->BackColor = System::Drawing::Color::White;
    this->button_operation->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->button_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->button_operation->Location = System::Drawing::Point(155, 307);
    this->button_operation->Name = L"button_operation";
    this->button_operation->Size = System::Drawing::Size(116, 54);
    this->button_operation->TabIndex = 5;
    this->button_operation->Text = L"Совершить операцию";
    this->button_operation->UseVisualStyleBackColor = false;
    this->button_operation->Click += gcnew System::EventHandler(this, &BankSettingsView::button_operation_Click);
    // 
    // button_copy
    // 
    this->button_copy->BackColor = System::Drawing::Color::White;
    this->button_copy->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
    this->button_copy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->button_copy->Location = System::Drawing::Point(425, 307);
    this->button_copy->Name = L"button_copy";
    this->button_copy->Size = System::Drawing::Size(116, 54);
    this->button_copy->TabIndex = 6;
    this->button_copy->Text = L"Копировать счёт";
    this->button_copy->UseVisualStyleBackColor = false;
    this->button_copy->Click += gcnew System::EventHandler(this, &BankSettingsView::button_copy_Click);
    // 
    // BankSettingsView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
        static_cast<System::Int32>(static_cast<System::Byte>(98)));
    this->ClientSize = System::Drawing::Size(564, 388);
    this->Controls->Add(this->button_copy);
    this->Controls->Add(this->button_operation);
    this->Controls->Add(this->listview_bank);
    this->Controls->Add(this->label_bank);
    this->Controls->Add(this->button_reload);
    this->Controls->Add(this->button_create_bank);
    this->ForeColor = System::Drawing::Color::Black;
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(580, 427);
    this->MinimumSize = System::Drawing::Size(580, 427);
    this->Name = L"BankSettingsView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"Менеджер банка";
    this->ResumeLayout(false);
    this->PerformLayout();

}