#pragma once
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
	/// ������ ��� MyForm
	/// </summary>
	public ref class DriverDialogView : public System::Windows::Forms::Form
	{
		Models::CarBaseModel^ car_model = nullptr;
	public:
		DriverDialogView(System::Void) { InitializeComponent(); }

		DriverDialogView(Models::CarBaseModel^ car_model)
		{
			InitializeComponent();
			this->car_model = car_model;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~DriverDialogView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ProgressBar^ progress_bar;
	private: System::Windows::Forms::Button^ button;

	private: System::Windows::Forms::ListView^ list_view;
	private: System::Windows::Forms::ColumnHeader^ column_header;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
		private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			
		}
	};
}
