#pragma once
#include "../account_model/account_model.h"

namespace Models 
{
	public enum class CarModelTypes { CarTypeEconom, CarTypePremium, CarTypeChild };

	public ref class CarBaseModel abstract
	{
	protected: CarModelTypes model_type;
	protected: AccountDriverModel^ moder_driver = nullptr;

	public:
		CarBaseModel(CarModelTypes car_type, AccountDriverModel^ driver) 
			: model_type(car_type) { this->moder_driver = driver; }

		virtual ~CarBaseModel(System::Void) { }

		property Models::CarModelTypes CarType
		{
		public: CarModelTypes get(System::Void) { return this->model_type; }
		}
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
		AccountDriverModel^ support_driver = nullptr;
	public:
		CarHeavyModel(CarModelTypes car_type, AccountDriverModel^ driver1, AccountDriverModel^ driver2)
			: CarBaseModel(car_type, driver1) { this->support_driver = driver2; }

		virtual ~CarHeavyModel(System::Void) { }
	};

}