#include "client_pricelist_view.h"

using namespace Views;

void ClientPriceListView::InitializeComponent(void)
{
    System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L""));
    this->list_view = (gcnew System::Windows::Forms::ListView());
    this->car_type = (gcnew System::Windows::Forms::ColumnHeader());
    this->car_price = (gcnew System::Windows::Forms::ColumnHeader());
    this->SuspendLayout();
    // 
    // list_view
    // 
    this->list_view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->car_type, this->car_price });
    this->list_view->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
    this->list_view->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->list_view->HideSelection = false;
    this->list_view->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
    this->list_view->Location = System::Drawing::Point(1, 1);
    this->list_view->Name = L"list_view";
    this->list_view->Size = System::Drawing::Size(374, 255);
    this->list_view->TabIndex = 0;
    this->list_view->UseCompatibleStateImageBehavior = false;
    this->list_view->View = System::Windows::Forms::View::Details;
    // 
    // car_type
    // 
    this->car_type->Text = L"Тип машины";
    this->car_type->Width = 200;
    // 
    // car_price
    // 
    this->car_price->Text = L"Стоимость заказа";
    this->car_price->Width = 170;
    // 
    // ClientPriceListView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(376, 257);
    this->Controls->Add(this->list_view);
    this->Name = L"ClientPriceListView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
    this->Text = L"Цены на машиины";
    this->ResumeLayout(false);

}