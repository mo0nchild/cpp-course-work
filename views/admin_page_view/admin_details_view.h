#pragma once
#include "../../models/account_model/account_model.h"
#include "../../services/account_manager/account_manager_token.h"

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
	public ref class AdminDetailsView: public System::Windows::Forms::Form
	{
		Models::AccountBaseModel^ model = nullptr;
		Services::AccountManagerToken::AccountManagerType type;
		System::Guid guid = System::Guid::Empty;

	public:
		AdminDetailsView(System::Void) { InitializeComponent(); }
		
		AdminDetailsView(Models::AccountBaseModel^ model, System::Guid guid,
			Services::AccountManagerToken::AccountManagerType type) : guid(guid), type(type)
		{ 
			InitializeComponent(); 
			this->model = (Models::AccountBaseModel^)model->Clone();
			this->account_data_load();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AdminDetailsView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ListView^ account_listview;
	private: System::Windows::Forms::ColumnHeader^ param_name;
	private: System::Windows::Forms::ColumnHeader^ param_value;
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
		void InitializeComponent(void);
#pragma endregion

		private: System::Void account_data_load(System::Void) 
		{
			this->account_listview->FullRowSelect = true;
			this->account_listview->Items->Clear();

			ListViewItem^ list_item = gcnew ListViewItem("Guid");
			list_item->SubItems->Add(this->guid.ToString());
			this->account_listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("Имя");
			list_item->SubItems->Add(this->model->Username);
			this->account_listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("Возраст");
			list_item->SubItems->Add(this->model->Age.ToString());
			this->account_listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("Пол");
			list_item->SubItems->Add(this->model->Gender.ToString());
			this->account_listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("Тип аккаунта");
			list_item->SubItems->Add(this->type.ToString());
			this->account_listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("Банковский счет");
			Models::AccountDriverModel^ full_model = nullptr;

			switch (this->type) 
			{
			case Services::AccountManagerToken::AccountManagerType::Client:;

				Models::AccountClientModel^ full_client_model;

				try { full_client_model = safe_cast<Models::AccountClientModel^>(model); }
				catch (System::Exception^) { MessageBox::Show("Не удалось загрузить банковский счет", "Ошибка"); return; }

				list_item->SubItems->Add(full_client_model->BankCard.ToString()); break;
			case Services::AccountManagerToken::AccountManagerType::Driver:;

				Models::AccountDriverModel^ full_driver_model;

				try { full_driver_model = safe_cast<Models::AccountDriverModel^>(model); }
				catch (System::Exception^) { MessageBox::Show("Не удалось загрузить банковский счет", "Ошибка"); return; }

				list_item->SubItems->Add(full_driver_model->BankCard.ToString()); break;
			}
			this->account_listview->Items->Add(list_item);
		}
	};
}
