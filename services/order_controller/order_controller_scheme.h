#pragma once
#include "../database_provider/database_provider.h"

namespace Services 
{
	public ref struct OrderControllerDbScheme sealed : SqlDatabaseManager::ISqlDataBaseSchemeType
	{
	public:		property System::String^ order_guid;
	public:		property System::String^ driver_guid;
	public:		property System::String^ car_type;
	public:		property System::String^ car_class;

	public:		property System::String^ address;
	public:		property System::String^ date_time;
	public:		property System::String^ order_status;

		  OrderControllerDbScheme(System::String^ p1, System::String^ p2, System::String^ p3, System::String^ p4,
			  System::String^ p5, System::String^ p6, System::String^ p7)
		  {
			  this->order_guid = p1;	this->driver_guid = p2;	this->car_type = p3;	this->car_class = p4;
			  this->address = p5;		this->date_time = p6;	this->order_status = p7;
		  }
		  OrderControllerDbScheme(System::Void)
		  {
			  this->order_guid = "";	this->driver_guid = "";	this->car_type = "";	this->car_class = "";
			  this->address = "";		this->date_time = "";	this->order_status = "";
		  }
		  virtual ~OrderControllerDbScheme(System::Void)
		  {
			  delete order_status, order_guid, driver_guid, car_class, car_type, address, date_time;
		  }
	};
}