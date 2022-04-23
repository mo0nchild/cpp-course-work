#include "bank_settings_operation.h"

using namespace Views;

void BankSettingsOperationView::InitializeComponent(void)
{
	this->combobox_operation_type = (gcnew System::Windows::Forms::ComboBox());
	this->numeric_money_value = (gcnew System::Windows::Forms::NumericUpDown());
	this->button_operation = (gcnew System::Windows::Forms::Button());
	this->label_operation_type = (gcnew System::Windows::Forms::Label());
	this->label_money_value = (gcnew System::Windows::Forms::Label());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_money_value))->BeginInit();
	this->SuspendLayout();
	// 
	// combobox_operation_type
	// 
	this->combobox_operation_type->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->combobox_operation_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
	this->combobox_operation_type->FormattingEnabled = true;
	this->combobox_operation_type->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Снять деньги", L"Положить деньги" });
	this->combobox_operation_type->Location = System::Drawing::Point(25, 31);
	this->combobox_operation_type->Name = L"combobox_operation_type";
	this->combobox_operation_type->Size = System::Drawing::Size(232, 28);
	this->combobox_operation_type->TabIndex = 0;
	// 
	// numeric_money_value
	// 
	this->numeric_money_value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
	this->numeric_money_value->Location = System::Drawing::Point(27, 87);
	this->numeric_money_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
	this->numeric_money_value->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	this->numeric_money_value->Name = L"numeric_money_value";
	this->numeric_money_value->Size = System::Drawing::Size(232, 26);
	this->numeric_money_value->TabIndex = 1;
	this->numeric_money_value->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
	// 
	// button_operation
	// 
	this->button_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
	this->button_operation->Location = System::Drawing::Point(25, 134);
	this->button_operation->Name = L"button_operation";
	this->button_operation->Size = System::Drawing::Size(232, 38);
	this->button_operation->TabIndex = 2;
	this->button_operation->Text = L"Совершить операцию";
	this->button_operation->UseVisualStyleBackColor = true;
	this->button_operation->Click += gcnew System::EventHandler(this, &BankSettingsOperationView::button_operation_Click);
	// 
	// label_operation_type
	// 
	this->label_operation_type->AutoSize = true;
	this->label_operation_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
	this->label_operation_type->Location = System::Drawing::Point(22, 9);
	this->label_operation_type->Name = L"label_operation_type";
	this->label_operation_type->Size = System::Drawing::Size(101, 17);
	this->label_operation_type->TabIndex = 3;
	this->label_operation_type->Text = L"Вид операции";
	// 
	// label_money_value
	// 
	this->label_money_value->AutoSize = true;
	this->label_money_value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
	this->label_money_value->Location = System::Drawing::Point(24, 67);
	this->label_money_value->Name = L"label_money_value";
	this->label_money_value->Size = System::Drawing::Size(120, 17);
	this->label_money_value->TabIndex = 4;
	this->label_money_value->Text = L"Денежная сумма";
	// 
	// BankSettingsOperationView
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(284, 193);
	this->Controls->Add(this->label_money_value);
	this->Controls->Add(this->label_operation_type);
	this->Controls->Add(this->button_operation);
	this->Controls->Add(this->numeric_money_value);
	this->Controls->Add(this->combobox_operation_type);
	this->Name = L"BankSettingsOperationView";
	this->Text = L"Банковская операция";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_money_value))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}