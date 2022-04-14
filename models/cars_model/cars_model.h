#pragma once
#include "../account_model/account_model.h"

namespace Models 
{
	public enum class CarModelTypes : System::UInt16 { CarTypeEconom, CarTypePremium, CarTypeChild };
	public enum class CarModelColor : System::UInt16 { CarColorBlack, CarColorWhite, CarColorRed, CarColorYellow };

	public ref class CarBaseModel abstract
	{
	private:	CarModelTypes model_type;
	private:	CarModelColor model_color;
	private:	System::UInt16 car_speed;

	public:	property AccountDriverModel^ moder_driver;
		  
	public:
		CarBaseModel(CarModelTypes car_type, AccountDriverModel^ driver)
			: model_type(car_type) { this->moder_driver = driver; }

		virtual ~CarBaseModel(System::Void) { }

		property Models::CarModelTypes CarType
		{ public: CarModelTypes get(System::Void) { return this->model_type; } }
	};

	public ref class CarLightModel sealed : CarBaseModel 
	{
	public:
		CarLightModel(CarModelTypes car_type, AccountDriverModel^ driver) 
			: CarBaseModel(car_type, driver) { }
		virtual ~CarLightModel(System::Void) { }
	};

	public ref class CarHeavyModel sealed : CarBaseModel
	{
		property AccountDriverModel^ support_driver;
	public:
		CarHeavyModel(CarModelTypes car_type, AccountDriverModel^ driver1, AccountDriverModel^ driver2)
			: CarBaseModel(car_type, driver1) { this->support_driver = driver2; }

		virtual ~CarHeavyModel(System::Void) { }
	};

}