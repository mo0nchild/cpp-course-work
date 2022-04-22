#pragma once
#include "../../services/depot_manager/depot_manager.h"
#include "../../services/depot_manager/depot_manager_token.h"
#include "../../models/cars_model/cars_model.h"

namespace Views 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class DriverComplexView : public System::Windows::Forms::Form
	{
		Models::CarBaseModel^ car_model = nullptr;

		System::Type^ car_model_class = nullptr;
	public:
		DriverComplexView(System::Void) { InitializeComponent(); }

		DriverComplexView(Models::CarBaseModel^ car_model, System::Type^ car_model_class)
		{
			InitializeComponent();
			this->car_model_class = car_model_class;
			this->car_model = car_model;
			this->update_listview();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DriverComplexView(System::Void) { if (components) delete components; }

	private: System::Windows::Forms::ListView^ listview;

	private: System::Windows::Forms::ColumnHeader^ listview_name;
	private: System::Windows::Forms::ColumnHeader^ listview_value;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
		private: System::Void update_listview() 
		{
			this->listview->Items->Clear();
			this->listview->FullRowSelect = true;

			ListViewItem^ list_item = gcnew ListViewItem(" ласс машины");
			list_item->SubItems->Add(this->car_model_class->Name);
			this->listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("“ип машины");
			list_item->SubItems->Add(this->car_model->CarType.ToString());
			this->listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("÷вет машины");
			list_item->SubItems->Add(this->car_model->CarColor.ToString());
			this->listview->Items->Add(list_item);

			list_item = gcnew ListViewItem("—корость машины");
			list_item->SubItems->Add(this->car_model->CarSpeed.ToString());
			this->listview->Items->Add(list_item);
		}
	};
}
