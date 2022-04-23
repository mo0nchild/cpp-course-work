#pragma once
#include "../../models/cars_model/cars_model.h"

#define ORDER_COMPLITION_TIME 5

namespace Views 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Threading::Tasks;
	using namespace System::Threading;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class DriverDialogView : public System::Windows::Forms::Form
	{
		Models::CarBaseModel^ car_model = nullptr;

	public:
		DriverDialogView(System::Void) { InitializeComponent(); }

		DriverDialogView(Models::CarBaseModel^ car_model)
		{
			InitializeComponent();
			
			this->list_view->Items->Add(gcnew ListViewItem(car_model->car_drive()));
			this->car_model = car_model;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DriverDialogView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ProgressBar^ progress_bar;
	private: System::Windows::Forms::Button^ button;

	private: System::Windows::Forms::ListView^ list_view;
	private: System::Windows::Forms::ColumnHeader^ column_header;

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
		private: System::Void order_processing_bar(System::Void)
		{
			for (System::Int16 i = 0; i < 100; i++)
			{
				this->progress_bar->Value += 1;
				Thread::Sleep(ORDER_COMPLITION_TIME* 10);
			}
			this->Hide();
			MessageBox::Show("Поездка закончилась", "Готово");
			this->Close();
		}

		private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->button->Enabled = false;
			Task::Run(gcnew System::Action(this, &DriverDialogView::order_processing_bar));
		}
	};
}
