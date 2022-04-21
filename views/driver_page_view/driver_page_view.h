#pragma once

#include "../../manager/manager.h"
#include "../../services/services.h"

#include "../bank_settings_view/bank_settings_view.h"
#include "../admin_page_view/admin_page_view.h"
#include "../driver_page_view/driver_page_view.h"
#include "../client_page_view/client_page_view.h"

namespace Views 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Models;
	using namespace Services;

	/// <summary>
	/// ������ ��� DriverPageView
	/// </summary>
	public ref class DriverPageView : public System::Windows::Forms::Form
	{
		Manager::ServiceManager^ service_manager = nullptr;
		Windows::Forms::Form^ start_page = nullptr;

		Services::AccountManager^ service_account_manager = nullptr;
		Services::DepotManager^ service_depot_manager = nullptr;
		Services::OrderController^ service_order_controller = nullptr;
		Services::BankController^ service_bank_controller = nullptr;
	public:
		DriverPageView(System::Void) { InitializeComponent(); }

		DriverPageView(Windows::Forms::Form^ start_page, Manager::ServiceManager^ service_manager)
		{
			InitializeComponent();
			this->service_manager = service_manager;
			this->start_page = start_page;

			Manager::IServiceProvider^ provider_account_manager = this->service_manager->get_service<AccountManager^>();
			Manager::IServiceProvider^ provider_depot_manager = this->service_manager->get_service<DepotManager^>();
			Manager::IServiceProvider^ provider_order_controller = this->service_manager->get_service<OrderController^>();
			Manager::IServiceProvider^ provider_bank_controller = this->service_manager->get_service<BankController^>();

			this->service_account_manager = (Services::AccountManager^)provider_account_manager->Service;
			this->service_depot_manager = (Services::DepotManager^)provider_depot_manager->Service;
			this->service_order_controller = (Services::OrderController^)provider_order_controller->Service;
			this->service_bank_controller = (Services::BankController^)provider_bank_controller->Service;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~DriverPageView(System::Void) { if (components) delete components; }

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
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// DriverPageView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 640);
			this->Name = L"DriverPageView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������� ��������";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
