#pragma once
#include "../../manager/manager.h"

#define DATABASE_CONNECTION_STRING "server=localhost;user=root;database=test;password=prolodgy778"

namespace Services 
{
	using namespace MySql::Data;
	using namespace System::Collections::Generic;

	public interface class IDatabaseManager 
	{
	public: using KeyValuePair = System::Tuple<System::String^, System::String^>;
	public: using RequestRow = System::Collections::Generic::List<System::String^>;

		List<RequestRow^>^ get_database_data(List<KeyValuePair^>^ searching_param);
		System::Boolean send_database_data(List<KeyValuePair^>^ request_param);
		System::Boolean delete_database_data(List<KeyValuePair^>^ searching_param);
	};

	public ref class SqlDatabaseManager sealed : Manager::ServiceBase, IDatabaseManager
	{
	private: MySqlClient::MySqlConnection^ db_connection = nullptr;
		System::String^ table_name = nullptr;

	public:
		SqlDatabaseManager(System::Void) : Manager::ServiceBase()
		{ this->db_connection = gcnew MySqlClient::MySqlConnection(DATABASE_CONNECTION_STRING); }
		virtual ~SqlDatabaseManager(System::Void) { delete this->db_connection, this->table_name; }

		property System::String^ TableName 
		{
		public: System::String^ get(System::Void) { return this->table_name; }
		public: System::Void set(System::String^ value) { this->table_name = value; }
		}

		virtual System::Boolean send_database_data(List<IDatabaseManager::KeyValuePair^>^ request_param);
		virtual System::Boolean delete_database_data(List<IDatabaseManager::KeyValuePair^>^ searching_param);

		virtual List<IDatabaseManager::RequestRow^>^ get_database_data(
			List<IDatabaseManager::KeyValuePair^>^ searching_param);
	};
}