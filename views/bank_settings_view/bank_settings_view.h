#pragma once
#include "../../manager/manager.h"
#include "../../services/services.h"
#include "bank_settings_operation.h"

namespace Views 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class BankSettingsView : public System::Windows::Forms::Form
	{
		Services::BankController^ bank_controller = nullptr;
	public:
		BankSettingsView(System::Void) { InitializeComponent(); }

		BankSettingsView(Services::BankController^ bank_controller)
		{
			InitializeComponent();
			this->bank_controller = bank_controller;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BankSettingsView(System::Void) { if (components) delete components; }

	protected:

	private: System::Windows::Forms::Button^ button_create_bank;
	private: System::Windows::Forms::Button^ button_reload;
	private: System::Windows::Forms::Label^ label_bank;
	private: System::Windows::Forms::ListView^ listview_bank;
	private: System::Windows::Forms::ColumnHeader^ column_guid;
	private: System::Windows::Forms::ColumnHeader^ column_money;
	private: System::Windows::Forms::Button^ button_operation;
	private: System::Windows::Forms::Button^ button_copy;



	protected:

	protected:

	private:
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
			this->button_create_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button_create_bank->Location = System::Drawing::Point(21, 307);
			this->button_create_bank->Name = L"button_create_bank";
			this->button_create_bank->Size = System::Drawing::Size(116, 54);
			this->button_create_bank->TabIndex = 1;
			this->button_create_bank->Text = L"Создать аккаунт";
			this->button_create_bank->UseVisualStyleBackColor = true;
			this->button_create_bank->Click += gcnew System::EventHandler(this, &BankSettingsView::button_create_bank_Click);
			// 
			// button_reload
			// 
			this->button_reload->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button_reload->Location = System::Drawing::Point(290, 307);
			this->button_reload->Name = L"button_reload";
			this->button_reload->Size = System::Drawing::Size(116, 54);
			this->button_reload->TabIndex = 2;
			this->button_reload->Text = L"Обновить данные";
			this->button_reload->UseVisualStyleBackColor = true;
			this->button_reload->Click += gcnew System::EventHandler(this, &BankSettingsView::button_reload_Click);
			// 
			// label_bank
			// 
			this->label_bank->AutoSize = true;
			this->label_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_bank->Location = System::Drawing::Point(17, 20);
			this->label_bank->Name = L"label_bank";
			this->label_bank->Size = System::Drawing::Size(228, 20);
			this->label_bank->TabIndex = 3;
			this->label_bank->Text = L"Список доступных аккаунтов";
			// 
			// listview_bank
			// 
			this->listview_bank->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->column_guid,
					this->column_money
			});
			this->listview_bank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->listview_bank->ForeColor = System::Drawing::Color::Black;
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
			this->button_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button_operation->Location = System::Drawing::Point(155, 307);
			this->button_operation->Name = L"button_operation";
			this->button_operation->Size = System::Drawing::Size(116, 54);
			this->button_operation->TabIndex = 5;
			this->button_operation->Text = L"Совершить операцию";
			this->button_operation->UseVisualStyleBackColor = true;
			this->button_operation->Click += gcnew System::EventHandler(this, &BankSettingsView::button_operation_Click);
			// 
			// button_copy
			// 
			this->button_copy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button_copy->Location = System::Drawing::Point(425, 307);
			this->button_copy->Name = L"button_copy";
			this->button_copy->Size = System::Drawing::Size(116, 54);
			this->button_copy->TabIndex = 6;
			this->button_copy->Text = L"Копировать счёт";
			this->button_copy->UseVisualStyleBackColor = true;
			this->button_copy->Click += gcnew System::EventHandler(this, &BankSettingsView::button_copy_Click);
			// 
			// BankSettingsView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 388);
			this->Controls->Add(this->button_copy);
			this->Controls->Add(this->button_operation);
			this->Controls->Add(this->listview_bank);
			this->Controls->Add(this->label_bank);
			this->Controls->Add(this->button_reload);
			this->Controls->Add(this->button_create_bank);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"BankSettingsView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Менеджер банка";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button_create_bank_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!this->bank_controller->create_bank_account(System::Guid::NewGuid()))
				MessageBox::Show("Возникла ошибка при создании счёта", "Уведомление");
			MessageBox::Show("Банковский счёт успешно создан", "Уведомление");
		}

		private: System::Void button_reload_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Generic::List<System::Guid>^ account_list = this->bank_controller->get_bank_accounts();
			if(account_list == nullptr) MessageBox::Show("Возникла ошибка при обновлении", "Уведомление");

			this->listview_bank->Items->Clear();
			this->listview_bank->FullRowSelect = true;

			for each (System::Guid item in account_list)
			{
				if(!this->bank_controller->load_bank_account(item)) continue;
				ListViewItem^ list_item = gcnew ListViewItem(this->bank_controller->AccountGuid.ToString());
				list_item->SubItems->Add(this->bank_controller->AccountMoney.ToString());
				this->listview_bank->Items->Add(list_item);
			}
			MessageBox::Show("Данные обновлены", "Уведомление");
		}

		private: System::Void button_operation_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->listview_bank->SelectedItems->Count > 0)
			{
				System::Guid account_guid;
				try { account_guid = System::Guid::Parse(this->listview_bank->SelectedItems[0]->Text); }
				catch (System::Exception^ error) { MessageBox::Show("Данные повреждены", "Ошибка"); return; }
				
				if (!this->bank_controller->load_bank_account(account_guid)) 
				{
					MessageBox::Show("Не удалось загрузить данные аккаунта", "Ошибка"); return;
				}

				Views::BankSettingsOperationView^ form = gcnew Views::BankSettingsOperationView(this->bank_controller);
				form->ShowDialog();
			}
			else MessageBox::Show("Выберите строку с аккаунтом", "Ошибка");
		}

		private: System::Void button_copy_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (this->listview_bank->SelectedItems->Count > 0)
			{
				Clipboard::SetText(this->listview_bank->SelectedItems[0]->Text);
				MessageBox::Show("Данные помещены в буфер обмена", "Успешно");
			}
			else MessageBox::Show("Выберите строку с аккаунтом", "Ошибка");
		}
	};
}
