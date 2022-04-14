#pragma once
#include "../database_provider/database_provider.h"
#include "../database_provider/database_provider_attribute.h"

namespace Services 
{
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

	public ref class CarModelDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public: [Services::SqlDatabaseFieldAttribute("count")]	property System::String^ drive_guid;
	public: [Services::SqlDatabaseFieldAttribute("type")]	property System::String^ car_type;
	public: [Services::SqlDatabaseFieldAttribute("class")]	property System::String^ car_class;
	public: [Services::SqlDatabaseFieldAttribute("speed")]	property System::String^ car_speed;
	public: [Services::SqlDatabaseFieldAttribute("color")]	property System::String^ car_color;

		  CarModelDbScheme(System::String^ p1, System::String^ p2, System::String^ p3)
		  {
			  this->drive_guid = p1;	this->car_type = p2;	this->car_class = p3;
		  }

		  CarModelDbScheme(System::Void)
		  {
			  this->drive_guid = "";	this->car_type = "";	this->car_class = "";
		  }

		  virtual ~CarModelDbScheme(System::Void) { delete drive_guid, car_type, car_class; }
	};
}