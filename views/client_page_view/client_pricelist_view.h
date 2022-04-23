#pragma once

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
	public ref class ClientPriceListView : public System::Windows::Forms::Form
	{
	public:
		ClientPriceListView(System::Void) { InitializeComponent(); this->listview_initialize(); }

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ClientPriceListView(System::Void) { if (components) delete components; }
	private: System::Windows::Forms::ListView^ list_view;
	protected:
	private: System::Windows::Forms::ColumnHeader^ car_type;
	private: System::Windows::Forms::ColumnHeader^ car_price;

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
		private: System::Void listview_initialize(System::Void) 
		{
			this->list_view->FullRowSelect = true;
			this->list_view->Items->Clear();

			ListViewItem^ list_item = gcnew ListViewItem("CarTypeEconom");
			list_item->SubItems->Add("150");
			this->list_view->Items->Add(list_item);

			list_item = gcnew ListViewItem("CarTypePremium");
			list_item->SubItems->Add("700");
			this->list_view->Items->Add(list_item);

			list_item = gcnew ListViewItem("CarTypeChild ");
			list_item->SubItems->Add("300");
			this->list_view->Items->Add(list_item);
		}
	};
}