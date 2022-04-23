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
		void InitializeComponent(void);
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
