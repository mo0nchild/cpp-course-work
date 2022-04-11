#pragma once
#include "../../models/cars_model/cars_model.h"

namespace Services 
{
	public value struct OrderControllerToken sealed
	{
	public:		property System::String^ OrderAddress;
	public:		property Models::CarModelTypes CarType;
	public:		property System::Guid OrderTokenGuid;

		  OrderControllerToken(System::String^ address, Models::CarModelTypes type)
		  {
			  this->OrderTokenGuid = System::Guid::NewGuid();
			  this->OrderAddress = address;
			  this->CarType = type;
		  }
	};
}