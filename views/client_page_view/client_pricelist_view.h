#pragma once
#include "../../services/services.h"
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
	public ref class ClientPriceListView : public System::Windows::Forms::Form
	{
		Services::DepotManager^ service_depot_manager = nullptr;
	public:
		ClientPriceListView(Services::DepotManager^ depot_manager) 
		{ 
			InitializeComponent(); 
			this->Icon = gcnew System::Drawing::Icon(L"./assets/my_app_icon.ico");
			this->service_depot_manager = depot_manager; this->listview_initialize(); 
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClientPriceListView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ListView^ list_view;
	protected:
	private: System::Windows::Forms::ColumnHeader^ car_type;
	private: System::Windows::Forms::ColumnHeader^ car_price;

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
		private: System::Void listview_initialize(System::Void) 
		{
			this->list_view->FullRowSelect = true;
			this->list_view->Items->Clear();

			ListViewItem^ list_item = gcnew ListViewItem("CarTypeEconom");
			list_item->SubItems->Add(this->service_depot_manager
				->CarTypePrice[Models::CarModelTypes::CarTypeEconom].ToString());
			this->list_view->Items->Add(list_item);

			list_item = gcnew ListViewItem("CarTypePremium");
			list_item->SubItems->Add(this->service_depot_manager
				->CarTypePrice[Models::CarModelTypes::CarTypePremium].ToString());
			this->list_view->Items->Add(list_item);

			list_item = gcnew ListViewItem("CarTypeChild ");
			list_item->SubItems->Add(this->service_depot_manager
				->CarTypePrice[Models::CarModelTypes::CarTypeChild].ToString());
			this->list_view->Items->Add(list_item);
		}
	};
}
