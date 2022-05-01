#pragma once
#include "../../manager/manager.h"
#include "../../services/services.h"

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
	public ref class BankSettingsOperationView : public System::Windows::Forms::Form
	{
		Services::BankController^ bank_controller = nullptr;
	public:
		BankSettingsOperationView(System::Void) { InitializeComponent(); }

		BankSettingsOperationView(Services::BankController^ bank_controller)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon(L"./assets/my_app_icon.ico");
			this->bank_controller = bank_controller;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BankSettingsOperationView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ComboBox^ combobox_operation_type;
	private: System::Windows::Forms::NumericUpDown^ numeric_money_value;
	private: System::Windows::Forms::Button^ button_operation;
	protected:

	protected:


	private: System::Windows::Forms::Label^ label_operation_type;
	private: System::Windows::Forms::Label^ label_money_value;



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
		private: System::Void button_operation_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			System::Int32 money = System::Decimal::ToInt32(this->numeric_money_value->Value);
			System::Boolean operation_check;

			if (this->combobox_operation_type->SelectedIndex == 0) operation_check = this->bank_controller->take_money(money);
			else operation_check = this->bank_controller->put_money(money);

			if (operation_check != true) { MessageBox::Show("Невозможно совершить операцию", "Ошибка"); return; }
			MessageBox::Show("Операция совершена", "Готово");
			this->Close();
		}
	};
}
