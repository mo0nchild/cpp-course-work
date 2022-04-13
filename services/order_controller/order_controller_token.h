#pragma once
#include "../../models/cars_model/cars_model.h"
#include "order_controller_scheme.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Reflection;

	public ref class OrderControllerTokenException sealed : System::Exception
	{
	public:
		OrderControllerTokenException(System::String^ message) : System::Exception(message) 
		{ }
		virtual ~OrderControllerTokenException(System::Void) { }
	};

	public value struct OrderControllerToken sealed
	{
	public:		System::Boolean OrderStatus;
	public:		System::DateTime OrderDate;
	public:		System::Guid OrderTokenGuid, DriverTokenGuid;
	public:		Models::CarModelTypes CarModelType;
	
	public: property System::Type^ CarModelClass;
	public:	property System::String^ OrderAddress;

	public: OrderControllerToken(String^ order_address, Models::CarModelTypes car_model, Type^ car_class) 
			: OrderTokenGuid(System::Guid::NewGuid()), OrderDate(System::DateTime::Now), OrderStatus(false)
	{
		if (car_class->IsSubclassOf(Models::CarBaseModel::typeid) != true)
		{ throw gcnew OrderControllerTokenException("From OrderControllerToken: \"car_class\" "); }
			
		this->DriverTokenGuid = System::Guid::Empty;
		this->OrderAddress = order_address;
		this->CarModelClass = car_class;
	}
	
	public: static OrderControllerToken create_from_dbscheme(OrderControllerDbScheme^ scheme) 
	{
		auto car_class = scheme->car_class == "CarLightModel" ? Models::CarLightModel::typeid :
			scheme->car_class == "CarHeavyModel" ? Models::CarHeavyModel::typeid : nullptr;

		Models::CarModelTypes car_model;
		if (scheme->car_type == "CarTypeEconom") car_model = Models::CarModelTypes::CarTypeEconom;
		else if (scheme->car_type == "CarTypePremium") car_model = Models::CarModelTypes::CarTypePremium;
		else if (scheme->car_type == "CarTypeChild") car_model = Models::CarModelTypes::CarTypeChild;
		else throw gcnew OrderControllerTokenException("From OrderControllerToken: \"create_from_dbscheme\"");

		OrderControllerToken token(scheme->address, car_model, car_class);
		token.DriverTokenGuid = System::Guid::Parse(scheme->driver_guid);
		token.OrderTokenGuid = System::Guid::Parse(scheme->order_guid);

		token.OrderStatus = Convert::ToBoolean(scheme->order_status);
		token.OrderDate = System::DateTime::Parse(scheme->date_time);
		return token;
	}
	};

	
}