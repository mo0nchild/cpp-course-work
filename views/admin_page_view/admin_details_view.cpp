#include "admin_details_view.h"

using namespace Views;

void AdminDetailsView::InitializeComponent(void)
{
    this->account_listview = (gcnew System::Windows::Forms::ListView());
    this->param_name = (gcnew System::Windows::Forms::ColumnHeader());
    this->param_value = (gcnew System::Windows::Forms::ColumnHeader());
    this->SuspendLayout();
    // 
    // account_listview
    // 
    this->account_listview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
        this->param_name,
            this->param_value
    });
    this->account_listview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->account_listview->GridLines = true;
    this->account_listview->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->account_listview->HideSelection = false;
    this->account_listview->Location = System::Drawing::Point(1, 1);
    this->account_listview->Name = L"account_listview";
    this->account_listview->Size = System::Drawing::Size(446, 334);
    this->account_listview->TabIndex = 0;
    this->account_listview->UseCompatibleStateImageBehavior = false;
    this->account_listview->View = System::Windows::Forms::View::Details;
    // 
    // param_name
    // 
    this->param_name->Text = L"Название параметра";
    this->param_name->Width = 180;
    // 
    // param_value
    // 
    this->param_value->Text = L"Значение параметра";
    this->param_value->Width = 260;
    // 
    // AdminDetailsView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(448, 336);
    this->Controls->Add(this->account_listview);
    this->MaximizeBox = false;
    this->MaximumSize = System::Drawing::Size(464, 375);
    this->MinimizeBox = false;
    this->MinimumSize = System::Drawing::Size(464, 375);
    this->Name = L"AdminDetailsView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
    this->Text = L"Подробная информация аккаунта";
    this->ResumeLayout(false);

}