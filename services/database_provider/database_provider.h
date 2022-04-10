#pragma once
#include "../../manager/manager.h"

#define DATABASE_CONNECTION_STRING "server=localhost;user=root;database=test;password=prolodgy778"

namespace Services 
{
	using namespace MySql::Data;
	public interface class IDatabaseManager 
	{

	};

	public ref class SqlDatabaseManager sealed : Manager::ServiceBase, IDatabaseManager
	{
		MySqlClient::MySqlConnection^ db_connection = nullptr;

	public:
		SqlDatabaseManager(System::Void) : Manager::ServiceBase()
		{ this->db_connection = gcnew MySqlClient::MySqlConnection(DATABASE_CONNECTION_STRING); }
		
		virtual ~SqlDatabaseManager(System::Void) { delete this->db_connection; }

		System::Boolean get_data(System::Void) 
		{
			try 
			{
				db_connection->Open();

				MySqlClient::MySqlCommand^ command = gcnew MySqlClient::MySqlCommand("select * from my_table", this->db_connection);
				MySqlClient::MySqlDataReader^ reader = command->ExecuteReader();

				while (reader->Read()) 
				{
					System::Console::WriteLine(reader[1]->ToString());
				}
			}
			catch (MySqlClient::MySqlException^ error) {}
			finally { db_connection->Close(); }

			return true;
		}

	};
}