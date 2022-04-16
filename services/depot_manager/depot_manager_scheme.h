#pragma once
#include "../database_provider/database_provider.h"
#include "../database_provider/database_provider_attribute.h"

namespace Services 
{
	[Services::SqlDatabaseTableAttribute("drive_complex")]
	public ref class DriveComplexDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public:	[Services::SqlDatabaseFieldAttribute("driver_guid")]	property System::String^ driver_guid;
	public: [Services::SqlDatabaseFieldAttribute("car_type")]		property System::String^ car_type;
	public: [Services::SqlDatabaseFieldAttribute("car_class")]		property System::String^ car_class;
	public: [Services::SqlDatabaseFieldAttribute("driver_state")]	property System::String^ driver_state;

		DriveComplexDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, System::String^ p4)
		{ this->driver_guid = p1;	this->car_type = p2;	this->car_class = p3;	this->driver_state = p4; }
		DriveComplexDbScheme(System::Void)
		{ this->driver_guid = "";	this->car_type = "";	this->car_class = "";	this->driver_state = ""; }
		virtual ~DriveComplexDbScheme(System::Void) { delete driver_guid, car_type, car_class, driver_state; }
	};

	[Services::SqlDatabaseTableAttribute("car_garage")]
	public ref class CarModelDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public: [Services::SqlDatabaseFieldAttribute("car_type")]	property System::String^ car_type;
	public: [Services::SqlDatabaseFieldAttribute("car_class")]	property System::String^ car_class;
	public: [Services::SqlDatabaseFieldAttribute("car_speed")]	property System::String^ car_speed;
	public: [Services::SqlDatabaseFieldAttribute("car_color")]	property System::String^ car_color;
	public: [Services::SqlDatabaseFieldAttribute("count")]		property System::String^ car_count;

		CarModelDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, 
			System::String^ p4, System::String^ p5)
		{ this->car_type = p1;	this->car_class = p2;	this->car_speed = p3;	this->car_color = p4;	this->car_count = p5; }
		CarModelDbScheme(System::Void)
		{ this->car_type = "";	this->car_class = "";	this->car_speed = "";	this->car_color = "";	this->car_count = ""; }

		virtual ~CarModelDbScheme(System::Void) { delete car_count, car_type, car_class, car_color, car_speed; }
	};
}