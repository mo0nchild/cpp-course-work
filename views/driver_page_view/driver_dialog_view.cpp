#include "driver_dialog_view.h"

using namespace Views;

void DriverDialogView::InitializeComponent(void)
{
    this->progress_bar = (gcnew System::Windows::Forms::ProgressBar());
    this->button = (gcnew System::Windows::Forms::Button());
    this->list_view = (gcnew System::Windows::Forms::ListView());
    this->column_header = (gcnew System::Windows::Forms::ColumnHeader());
    this->SuspendLayout();
    // 
    // progress_bar
    // 
    this->progress_bar->Location = System::Drawing::Point(13, 105);
    this->progress_bar->Name = L"progress_bar";
    this->progress_bar->Size = System::Drawing::Size(314, 23);
    this->progress_bar->Step = 1;
    this->progress_bar->TabIndex = 0;
    // 
    // button
    // 
    this->button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
    this->button->Location = System::Drawing::Point(13, 143);
    this->button->Name = L"button";
    this->button->Size = System::Drawing::Size(314, 36);
    this->button->TabIndex = 1;
    this->button->Text = L"Активировать поездку";
    this->button->UseVisualStyleBackColor = true;
    this->button->Click += gcnew System::EventHandler(this, &DriverDialogView::button_Click);
    // 
    // list_view
    // 
    this->list_view->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->list_view->CheckBoxes = true;
    this->list_view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->column_header });
    this->list_view->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
    this->list_view->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
    this->list_view->HideSelection = false;
    this->list_view->Location = System::Drawing::Point(13, 12);
    this->list_view->Name = L"list_view";
    this->list_view->Size = System::Drawing::Size(314, 74);
    this->list_view->TabIndex = 3;
    this->list_view->UseCompatibleStateImageBehavior = false;
    this->list_view->View = System::Windows::Forms::View::Details;
    // 
    // column_header
    // 
    this->column_header->Text = L"Сообщение модели машины";
    this->column_header->Width = 310;
    // 
    // DriverDialogView
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(338, 202);
    this->Controls->Add(this->list_view);
    this->Controls->Add(this->button);
    this->Controls->Add(this->progress_bar);
    this->Name = L"DriverDialogView";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
    this->Text = L"Процесс вождения";
    this->ResumeLayout(false);

}