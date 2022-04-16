#pragma once
#include "../../manager/manager.h"
#include "database_provider_attribute.h"

#define DATABASE_CONNECTION_STRING "server=localhost;user=root;database=test;password=prolodgy778"

namespace Services 
{
	using namespace MySql::Data;
	using namespace System::Collections::Generic;
	using namespace System::Reflection;

	public interface class IDatabaseManager 
	{
	public: using KeyValuePair = System::Tuple<System::String^, System::String^>;
	public: using RequestRow = System::Object;

		List<RequestRow^>^ get_database_data(List<KeyValuePair^>^ searching_param, System::Boolean mergering);

		System::Boolean send_database_data(IDatabaseManager::RequestRow^ request_param);
		System::Boolean delete_database_data(IDatabaseManager::KeyValuePair^ searching_param);
	};

	public ref class SqlDatabaseManagerException sealed : System::Exception 
	{
	public: SqlDatabaseManagerException(System::String^ message) : System::Exception(message) { }
		  virtual ~SqlDatabaseManagerException(System::Void) { }
	};

	public ref class SqlDatabaseManager sealed : Manager::ServiceBase, IDatabaseManager
	{
	public: interface class ISqlDataBaseSchemeType { };
		  value struct SqlDatabaseFieldKey { System::String^ Attribute; System::String^ ClassField; };
	private: 
		MySqlClient::MySqlConnection^ db_connection = nullptr;
		List<SqlDatabaseFieldKey>^ db_keys_name = nullptr;

		System::String^ db_table_name = nullptr;
		System::Type^ db_scheme_type = nullptr;

	public:
		SqlDatabaseManager(System::Void) : Manager::ServiceBase()
		{ 
			this->db_connection = gcnew MySqlClient::MySqlConnection(DATABASE_CONNECTION_STRING); 
			this->db_keys_name = gcnew List<SqlDatabaseFieldKey>();
		}
		virtual ~SqlDatabaseManager(System::Void) 
		{ 
			delete this->db_connection, this->db_table_name, this->db_keys_name; 
			Manager::ServiceBase::~ServiceBase();
		}

		property System::String^ TableName 
		{
		public: System::String^ get(System::Void) { return this->db_table_name; }
		public: System::Void set(System::String^ value) { this->db_table_name = value; }
		}

		property System::String^ SchemeName 
		{ public: System::String^ get(System::Void) { return this->db_scheme_type->ToString(); } }

		property List<System::String^>^ CurrentScheme { List<System::String^>^ get(System::Void); }
		generic <class TSchemeStruct> Services::SqlDatabaseManager^ set_scheme_struct(System::Void);

		virtual System::Boolean send_database_data(IDatabaseManager::RequestRow^ request_param);
		virtual System::Boolean delete_database_data(IDatabaseManager::KeyValuePair^ searching_param);

		virtual List<IDatabaseManager::RequestRow^>^ get_database_data(
			List<IDatabaseManager::KeyValuePair^>^ searching_param, System::Boolean mergering) override;
	};
}