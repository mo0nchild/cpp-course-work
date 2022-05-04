#include "driver_complex_view.h"

using namespace Views;

void DriverComplexView::InitializeComponent(void)
{
    this->listview = (gcnew System::Windows::Forms::ListView());
    this->listview_name = (gcnew System::Windows::Forms::ColumnHeader());
    this->listview_value = (gcnew System::Windows::Forms::ColumnHeader());
    this->SuspendLayout();
    // 
    // listview
    // 
    this->listview->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->listview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->listview_name, this->listview_value });
    this->listview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->listview->GridLines = true;
    this->listview->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->listview->HideSelection = false;
    this->listview->Location = System::Drawing::Point(3, 1);
    this->listview->MultiSelect = false;
    this->listview->Name = L"listview";
    this->listview->Size = System::Drawing::Size(416, 285);
    this->listview->TabIndex = 0;
    this->listview->UseCompatibleStateImageBehavior = false;
    this->listview->View = System::Windows::Forms::View::Details;
    // 
    // listview_name
    // 
    this->listview_name->Text = L"Название";
    this->listview_name->Width = 150;
    // 
    // listview_value
    // 
    this->listview_value->Text = L"Значение параметра";
    this->listview_value->Width = 260;
    // 
    // DriverComplexView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(424, 289);
    this->Controls->Add(this->listview);
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(440, 328);
    this->MinimizeBox = false;
    this->MinimumSize = System::Drawing::Size(440, 328);
    this->Name = L"DriverComplexView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
    this->Text = L"Машиный комлекс";
    this->ResumeLayout(false);

}
