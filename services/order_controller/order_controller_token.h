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
	private:	System::Type^ exception_attach_from = nullptr;
	public:
		property System::Type^ AttachFrom
		{ public: System::Type^ get(System::Void) { return this->exception_attach_from; } }

		virtual property System::String^ Message
		{
		public: System::String^ get(System::Void) override
			{ return "From " + exception_attach_from->ToString() + ": " + Exception::Message;}
		}
	public:
		OrderControllerTokenException(System::Type^ from, System::String^ message) : System::Exception(message)
		{ this->exception_attach_from = from; }
		virtual ~OrderControllerTokenException(System::Void) { delete exception_attach_from; }
	};

	public value struct OrderControllerToken sealed
	{
	public:		System::Boolean OrderStatus;
	public:		System::DateTime OrderDate;
	public:		System::Guid ClientGuid, DriverGuid;
	public:		Models::CarModelTypes CarModelType;
	
	public: property System::Type^ CarModelClass;
	public:	property System::String^ OrderAddress;
	public: 
		OrderControllerToken(String^ order_address, Models::CarModelTypes car_model, Type^ car_class, Guid client) 
			: ClientGuid(client), DriverGuid(Guid::Empty), OrderDate(System::DateTime::Now), OrderStatus(false)
		{
			if (car_class->IsSubclassOf(Models::CarBaseModel::typeid) != true)
			{ throw gcnew OrderControllerTokenException(OrderControllerToken::typeid, "car_class"); }
			
			this->OrderAddress = order_address;
			this->CarModelClass = car_class;
			this->CarModelType = car_model;
		}
	
		public: static OrderControllerToken create_from_dbscheme(OrderControllerDbScheme^ scheme) 
		{
			System::Type^ car_class = scheme->car_class == "CarLightModel" ? Models::CarLightModel::typeid :
				scheme->car_class == "CarHeavyModel" ? Models::CarHeavyModel::typeid : nullptr;

			Models::CarModelTypes car_model;
			if (scheme->car_type == "CarTypeEconom") car_model = Models::CarModelTypes::CarTypeEconom;
			else if (scheme->car_type == "CarTypePremium") car_model = Models::CarModelTypes::CarTypePremium;
			else if (scheme->car_type == "CarTypeChild") car_model = Models::CarModelTypes::CarTypeChild;
			else throw gcnew OrderControllerTokenException(OrderControllerToken::typeid, "create_from_dbscheme");

			System::Guid driver_guid = System::Guid::Parse(scheme->driver_guid);
			System::Guid client_guid = System::Guid::Parse(scheme->client_guid);
			OrderControllerToken token(scheme->address, car_model, car_class, client_guid);
		
			token.OrderStatus = Convert::ToBoolean(scheme->order_status);
			token.OrderDate = System::DateTime::Parse(scheme->date_time);
			return token;
		}
	};

	
}