#pragma once
#include "../../manager/manager.h"
#include "database_provider_attribute.h"
//#define DATABASE_CONNECTION_STRING "server=localhost;user=root;database=test;password=prolodgy778"

namespace Services 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;
	using namespace MySql::Data;
	using namespace Manager;

	public interface class IDatabaseManager 
	{
	public: using KeyValuePair = System::Tuple<System::String^, System::String^>;
	public: using RequestRow = System::Object;

		List<RequestRow^>^ get_database_data(List<KeyValuePair^>^ searching_param, System::Boolean mergering);
		System::Boolean update_database_date(RequestRow^ request_param, KeyValuePair^ searching_param);

		System::Boolean send_database_data(IDatabaseManager::RequestRow^ request_param);
		System::Boolean delete_database_data(IDatabaseManager::KeyValuePair^ searching_param);
	};

	public ref class SqlDatabaseManagerException sealed : System::Exception
	{
	private:	System::Type^ exception_attach_from = nullptr;
	public:
		property System::Type^ AttachFrom
		{ public: System::Type^ get(System::Void) { return this->exception_attach_from; } }

		virtual property System::String^ Message
		{
		public: System::String^ get(System::Void) override
			{ return "From " + exception_attach_from->ToString() + ": " + Exception::Message; }
		}
	public:
		SqlDatabaseManagerException(System::Type^ from, System::String^ message) : System::Exception(message)
		{ this->exception_attach_from = from; }
		virtual ~SqlDatabaseManagerException(System::Void) { delete exception_attach_from; }
	};

	public ref class SqlDatabaseManager sealed : Manager::ServiceBase, IDatabaseManager
	{
	public: interface class ISqlDataBaseSchemeType { };
		  value struct SqlDatabaseFieldKey { System::String^ Attribute; System::String^ ClassField; };
	private: 
		MySqlClient::MySqlConnection^ db_connection = nullptr;
		List<SqlDatabaseFieldKey>^ db_keys_name = nullptr;

	private:	Threading::Mutex^ connection_mutex = nullptr;
	private:	System::String^ db_table_name = nullptr;
	private:	System::Type^ db_scheme_type = nullptr;
	public:
		property System::String^ TableName
		{
		public: System::String^ get(System::Void) { return this->db_table_name; }
		public: System::Void set(System::String^ value) { this->db_table_name = value; }
		}

		property System::String^ SchemeName
		{ public: System::String^ get(System::Void) { return this->db_scheme_type->ToString(); } }

		property List<System::String^>^ CurrentScheme { List<System::String^>^ get(System::Void); }
	private:	System::Void db_build_connection(System::Void);
	public:
		[Manager::ServiceConfigurationAttribute("database_provider")]
		SqlDatabaseManager(IServiceBase::ServiceCtorConfiguration^ conf) : Manager::ServiceBase(conf)
		{
			this->db_keys_name = gcnew List<SqlDatabaseFieldKey>();
			this->connection_mutex = gcnew Threading::Mutex();
			this->db_build_connection();
		}
		virtual ~SqlDatabaseManager(System::Void) 
		{
			delete this->db_connection, this->db_table_name, this->db_keys_name; 
			Manager::ServiceBase::~ServiceBase();
		}
		generic <class TSchemeStruct> Services::SqlDatabaseManager^ set_scheme_struct(System::Void);

		virtual System::Boolean update_database_date(IDatabaseManager::RequestRow^ request_param,
			IDatabaseManager::KeyValuePair^ searching_param) override;

		virtual System::Boolean send_database_data(IDatabaseManager::RequestRow^ request_param);
		virtual System::Boolean delete_database_data(IDatabaseManager::KeyValuePair^ searching_param);

		virtual List<IDatabaseManager::RequestRow^>^ get_database_data(
			List<IDatabaseManager::KeyValuePair^>^ searching_param, System::Boolean mergering) override;

		virtual IServiceBase::ServiceQuery^ service_query_handler(System::TimeSpan work_time) override;
	};
}