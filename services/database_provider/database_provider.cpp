#include "database_provider.h"

using namespace Services;

List<IDatabaseManager::RequestRow^>^ SqlDatabaseManager::get_database_data(
	List<IDatabaseManager::KeyValuePair^>^ searching_param)
{
	List<IDatabaseManager::RequestRow^>^ request_result = gcnew List<IDatabaseManager::RequestRow^>();
	if (searching_param == nullptr) return request_result;

	this->db_connection->Open();
	try {
		System::String^ request = "select * from order_collection where 1";
		for each (auto item in searching_param)
		{
			request = System::String::Concat(request, " and ", item->Item1, " = \"", item->Item2, "\"");
		}

		MySqlClient::MySqlCommand^ sql_command = gcnew MySqlClient::MySqlCommand(request, this->db_connection);
		MySqlClient::MySqlDataReader^ sql_reader = sql_command->ExecuteReader();

		while (sql_reader->Read())
		{
			IDatabaseManager::RequestRow^ request_row = gcnew IDatabaseManager::RequestRow();
			for (int i = 0; i < sql_reader->FieldCount; i++) { request_row->Add(sql_reader[i]->ToString()); }
			request_result->Add(request_row);
		}
		sql_reader->Close();
	}
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); }
	finally { db_connection->Close(); }

	return request_result;
}

System::Boolean SqlDatabaseManager::send_database_data(List<IDatabaseManager::KeyValuePair^>^ request_param)
{
	if (request_param == nullptr) return false;

	this->db_connection->Open();
	try {
		System::String^ request = "select * from order_collection where 1";

		MySqlClient::MySqlCommand^ sql_command = this->db_connection->CreateCommand();
		sql_command->CommandText = "insert into order_collection(" + request_param[0]->Item1;
		for (int i = 1; i < request_param->Count; i++)
		{
			sql_command->CommandText += System::String::Concat(",", request_param[i]->Item1);
		}
		sql_command->CommandText += System::String::Concat(") values (\"", request_param[0]->Item2, "\"");

		for(int i = 1; i < request_param->Count; i++)
		{
			sql_command->CommandText += System::String::Concat(", ?", request_param[i]->Item1);
			sql_command->Parameters->Add("?" + request_param[i]->Item1, MySqlClient::MySqlDbType::VarChar)->Value 
				= request_param[i]->Item2;
		}
		sql_command->CommandText += ");";
		System::Console::WriteLine(sql_command->CommandText);

		sql_command->ExecuteNonQuery();
	}
	catch (System::Exception^ error) { System::Console::WriteLine(error->Message); return false; }
	finally { db_connection->Close(); }

	return true;
}

System::Boolean SqlDatabaseManager::delete_database_data(List<IDatabaseManager::KeyValuePair^>^ searching_param)
{
	return true;
}
