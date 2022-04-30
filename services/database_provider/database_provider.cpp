#pragma once
#include "database_provider.h"

using namespace Services;
using namespace System;

List<System::String^>^ SqlDatabaseManager::CurrentScheme::get(System::Void)
{
	List<System::String^>^ copy_list = gcnew List<System::String^>();
	for each (auto item in this->db_keys_name) { copy_list->Add(safe_cast<System::String^>(item.Attribute->Clone())); }
	return copy_list;
}

System::Void SqlDatabaseManager::db_build_connection(System::Void)
{
	// "server=localhost;user=root;database=test;password=prolodgy778"
	System::String^ database_connection_string = "server=" + this->configuration["sql_connection_server"]
		+ ";user=" + this->configuration["sql_connection_user"]
		+ ";database=" + this->configuration["sql_connection_database"]
		+ ";password=" + this->configuration["sql_connection_password"];

	this->db_connection = gcnew MySqlClient::MySqlConnection(database_connection_string);
}

IServiceBase::ServiceQuery^ SqlDatabaseManager::service_query_handler(System::TimeSpan work_time)
{
	Manager::IServiceBase::ServiceQuery^ service_query = gcnew Manager::IServiceBase::ServiceQuery();

	service_query->Message = "Message from Sql Database Manager";
	service_query->ServiceType = this->GetType();
	service_query->State = this->ServiceState;

	return service_query;
}

generic <class TSchemeStruct> Services::SqlDatabaseManager^ SqlDatabaseManager::set_scheme_struct(System::Void)
{
	System::Type^ scheme_deconstruct = TSchemeStruct::typeid;
	SqlDatabaseTableAttribute^ scheme_attribute = safe_cast<SqlDatabaseTableAttribute^>(
		System::Attribute::GetCustomAttribute(scheme_deconstruct, SqlDatabaseTableAttribute::typeid));
	this->TableName = scheme_attribute->TableName;

	if(scheme_deconstruct->GetInterface("ISqlDataBaseSchemeType") == nullptr) 
		throw gcnew SqlDatabaseManagerException(SqlDatabaseManager::typeid, "Does Not Implement ISqlDataBaseSchemeType");
	array<System::Reflection::PropertyInfo^>^ property_list = scheme_deconstruct->GetProperties();

	this->db_scheme_type = scheme_deconstruct;
	this->db_keys_name->Clear();
	
	for (int i = 0; i < property_list->Length; i++) 
	{
		SqlDatabaseFieldAttribute^ field_attribute = safe_cast<SqlDatabaseFieldAttribute^>(
			System::Attribute::GetCustomAttribute(property_list[i], SqlDatabaseFieldAttribute::typeid));
		SqlDatabaseFieldKey database_key{ field_attribute->FieldName, property_list[i]->Name };
		
		if(field_attribute != nullptr) this->db_keys_name->Add(database_key);
	}
	return this;
}

System::String^ build_request_string(IDatabaseManager::RequestRow^ request_type, System::String^ request_key)
{
	System::Reflection::PropertyInfo^ prop_info = nullptr;

	try { prop_info = request_type->GetType()->GetProperty(request_key, BindingFlags::Public | BindingFlags::Instance); }
	catch (System::Exception^ error) { Console::WriteLine(error->Message); return nullptr; }

	return prop_info->GetValue(request_type)->ToString();
}

System::Boolean SqlDatabaseManager::update_database_date(IDatabaseManager::RequestRow^ request_param,
	IDatabaseManager::KeyValuePair^ searching_param)
{
	if (request_param == nullptr || searching_param == nullptr || db_keys_name->Count == 0) return false;
	this->connection_mutex->WaitOne();
	this->db_connection->Open();
	try 
	{
		System::String^ request_string = "UPDATE " + this->db_table_name + " SET ";
		for(int i = 0; i < db_keys_name->Count; i++)
		{
			request_string = String::Concat(request_string, db_keys_name[i].Attribute, " = \"",
				build_request_string(request_param, db_keys_name[i].ClassField), "\" ");
			if (i != db_keys_name->Count - 1) request_string += ", ";
		}
		request_string = String::Concat(request_string, " WHERE ", searching_param->Item1, " = \"", searching_param->Item2, "\"");

		MySqlClient::MySqlCommand^ sql_command = gcnew MySqlClient::MySqlCommand(request_string, this->db_connection);
		sql_command->ExecuteNonQuery();
	}
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); return false; }
	finally { this->db_connection->Close(); this->connection_mutex->ReleaseMutex(); }

	return true;
}

List<IDatabaseManager::RequestRow^>^ SqlDatabaseManager::get_database_data(
	List<IDatabaseManager::KeyValuePair^>^ searching_param, System::Boolean mergering)
{
	List<IDatabaseManager::RequestRow^>^ request_result = gcnew List<IDatabaseManager::RequestRow^>();
	if (searching_param == nullptr || db_keys_name->Count == 0) return request_result;

	this->connection_mutex->WaitOne();
	this->db_connection->Open();
	try {
		System::String^ request = "SELECT * FROM " + this->db_table_name + " WHERE 1";
		for each (auto item in searching_param)
		{ request = System::String::Concat(request, mergering ? " OR " : " AND ", item->Item1, " = \"", item->Item2, "\""); }

		MySqlClient::MySqlCommand^ sql_command = gcnew MySqlClient::MySqlCommand(request, this->db_connection);
		MySqlClient::MySqlDataReader^ sql_reader = sql_command->ExecuteReader();

		while (sql_reader->Read())
		{
			IDatabaseManager::RequestRow^ request_row = nullptr;
			array<System::Object^>^ param = gcnew array<System::Object^>(sql_reader->FieldCount - 1);
			for (int i = 1; i < sql_reader->FieldCount; i++) { param[i - 1] = sql_reader[i]->ToString(); }

			try { request_row = System::Activator::CreateInstance(this->db_scheme_type, param); }
			catch (System::Exception^ error)
			{ sql_reader->Close(); this->db_connection->Close(); return nullptr; }

			request_result->Add(request_row);
		}
		sql_reader->Close();
	}
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); return nullptr; }
	finally { this->db_connection->Close(); this->connection_mutex->ReleaseMutex(); }

	return request_result;
}

System::Boolean SqlDatabaseManager::send_database_data(IDatabaseManager::RequestRow^ request_param)
{
	System::Type^ request_type = request_param->GetType();
	if (request_param == nullptr || request_type != this->db_scheme_type || db_keys_name->Count == 0) return false;
	System::Boolean request_result = true;

	this->connection_mutex->WaitOne();
	this->db_connection->Open();
	try {
		MySqlClient::MySqlCommand^ sql_command = this->db_connection->CreateCommand();
		sql_command->CommandText = "INSERT INTO " + this->db_table_name + " (" + db_keys_name[0].Attribute;
		for (int i = 1; i < db_keys_name->Count; i++)
		{
			sql_command->CommandText += System::String::Concat(",", db_keys_name[i].Attribute);
		}
		sql_command->CommandText += System::String::Concat(") VALUES (\"",
			build_request_string(request_param, db_keys_name[0].ClassField), "\"");

		for(int i = 1; i < db_keys_name->Count; i++)
		{
			sql_command->CommandText += System::String::Concat(", ?", db_keys_name[i].Attribute);
			sql_command->Parameters->Add("?" + db_keys_name[i].Attribute,
				MySqlClient::MySqlDbType::VarChar)->Value
				= build_request_string(request_param, db_keys_name[i].ClassField);
		}
		sql_command->CommandText += ");";
		sql_command->ExecuteNonQuery();
	}
	catch (System::Exception^ error) { System::Console::WriteLine(error->Message); request_result = false; }
	finally { this->db_connection->Close(); this->connection_mutex->ReleaseMutex(); }

	return request_result;
}

System::Boolean SqlDatabaseManager::delete_database_data(IDatabaseManager::KeyValuePair^ searching_param)
{
	if (searching_param == nullptr || db_keys_name->Count == 0) return false;

	this->connection_mutex->WaitOne();
	this->db_connection->Open();
	try {
		System::String^ request = System::String::Concat( "DELETE FROM " + this->db_table_name + " WHERE ",
			searching_param->Item1, " = \"", searching_param->Item2, "\"");

		MySqlClient::MySqlCommand^ sql_command = gcnew MySqlClient::MySqlCommand(request, this->db_connection);
		sql_command->ExecuteNonQuery();
	}
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); return false; }
	finally { this->db_connection->Close(); this->connection_mutex->ReleaseMutex(); }

	return true;
}
