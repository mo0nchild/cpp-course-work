#pragma once
#include "database_provider.h"

using namespace Services;

List<System::String^>^ SqlDatabaseManager::CurrentScheme::get(System::Void)
{
	List<System::String^>^ copy_list = gcnew List<System::String^>();
	for each (auto item in this->db_keys_name) { copy_list->Add(safe_cast<System::String^>(item->Clone())); }
	return copy_list;
}

generic <class TSchemeStruct> Services::SqlDatabaseManager^ SqlDatabaseManager::set_scheme_struct(System::Void)
{
	System::Type^ scheme_deconstruct = TSchemeStruct::typeid;
	if(scheme_deconstruct->GetInterface("ISqlDataBaseSchemeType") == nullptr) 
		throw gcnew SqlDatabaseManagerException("From SqlDatabaseManager: Does Not Implement ISqlDataBaseSchemeType");
	array<System::Reflection::PropertyInfo^>^ property_list = scheme_deconstruct->GetProperties();

	this->db_scheme_type = scheme_deconstruct;
	this->db_keys_name->Clear();
	
	for (int i = 0; i < property_list->Length; i++) { this->db_keys_name->Add(property_list[i]->Name); }
	return this;
}

List<IDatabaseManager::RequestRow^>^ SqlDatabaseManager::get_database_data(
	List<IDatabaseManager::KeyValuePair^>^ searching_param)
{
	List<IDatabaseManager::RequestRow^>^ request_result = gcnew List<IDatabaseManager::RequestRow^>();
	if (searching_param == nullptr) return request_result;

	this->db_connection->Open();
	try {
		System::String^ request = "select * from " + this->db_table_name + " where 1";
		for each (auto item in searching_param)
		{ request = System::String::Concat(request, " or ", item->Item1, " = \"", item->Item2, "\""); }

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
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); }
	finally { this->db_connection->Close(); }

	return request_result;
}

System::String^ build_request_string(IDatabaseManager::RequestRow^ request_type, System::String^ request_key)
{
	System::Reflection::PropertyInfo^ prop_info = 
		request_type->GetType()->GetProperty(request_key, BindingFlags::Public | BindingFlags::Instance);
	return prop_info->GetValue(request_type)->ToString();
}

System::String^ build_field_name(System::Reflection::PropertyInfo^ field) 
{
	SqlDatabaseFieldAttribute^ service_requirement = safe_cast<array<SqlDatabaseFieldAttribute^>^>(
		System::Attribute::GetCustomAttributes(field->GetType(), SqlDatabaseFieldAttribute::typeid))[0];

	return service_requirement->FieldName;
}

System::Boolean SqlDatabaseManager::send_database_data(IDatabaseManager::RequestRow^ request_param)
{
	System::Type^ request_type = request_param->GetType();
	if (request_param == nullptr || request_type != this->db_scheme_type) return false;
	array<System::Reflection::PropertyInfo^>^ fields_list = this->db_scheme_type->GetProperties();

	this->db_connection->Open();
	try {
		MySqlClient::MySqlCommand^ sql_command = this->db_connection->CreateCommand();
		sql_command->CommandText = "insert into " + this->db_table_name + " (" + build_field_name(fields_list[0]);
		for (int i = 1; i < fields_list->Length; i++)
		{
			sql_command->CommandText += System::String::Concat(",", build_field_name(fields_list[i]));
		}
		sql_command->CommandText += System::String::Concat(") values (\"",
			build_request_string(request_param, fields_list[0]->Name), "\"");

		for(int i = 1; i < fields_list->Length; i++)
		{
			sql_command->CommandText += System::String::Concat(", ?", fields_list[i]->Name);
			sql_command->Parameters->Add("?" + build_field_name(fields_list[i]), 
				MySqlClient::MySqlDbType::VarChar)->Value
				= build_request_string(request_param, fields_list[i]->Name);
		}
		sql_command->CommandText += ");";
		sql_command->ExecuteNonQuery();
	}
	catch (System::Exception^ error) { System::Console::WriteLine(error->Message); return false; }
	finally { db_connection->Close(); }

	return true;
}

System::Boolean SqlDatabaseManager::delete_database_data(IDatabaseManager::KeyValuePair^ searching_param)
{
	if (searching_param == nullptr) return false;

	this->db_connection->Open();
	try {
		System::String^ request = System::String::Concat( "delete from " + this->db_table_name + " where ",
			searching_param->Item1, " = \"", searching_param->Item2, "\"");

		MySqlClient::MySqlCommand^ sql_command = gcnew MySqlClient::MySqlCommand(request, this->db_connection);
		sql_command->ExecuteNonQuery();
	}
	catch (MySqlClient::MySqlException^ error) { System::Console::WriteLine(error->Message); return false; }
	finally { db_connection->Close(); }

	return true;
}
