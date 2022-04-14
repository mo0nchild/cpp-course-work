#pragma once

namespace Services 
{
	[System::AttributeUsage(System::AttributeTargets::Property, AllowMultiple = false)]
	public ref class SqlDatabaseFieldAttribute sealed : System::Attribute
	{
		System::String^ database_field_name = nullptr;
	public:
		SqlDatabaseFieldAttribute(System::String^ field_name) : System::Attribute()
		{ this->database_field_name = field_name; }
		virtual ~SqlDatabaseFieldAttribute(System::Void) { delete this->database_field_name; }

		property System::String^ FieldName
		{ System::String^ get(System::Void) { return this->database_field_name; } }
	};
}