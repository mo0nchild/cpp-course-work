#pragma once
#include "../account_model/account_model.h"

namespace Models 
{
	public enum class CarModelTypes : System::UInt16 { CarTypeEconom, CarTypePremium, CarTypeChild };
	public enum class CarModelColor : System::UInt16 { CarColorBlack, CarColorWhite, CarColorRed, CarColorYellow };

	public ref class CarBaseModel abstract : System::ICloneable
	{
	private:	Models::CarModelTypes model_type;
	private:	Models::CarModelColor model_color;
	private:	System::UInt32 model_speed;
	public:
		property Models::CarModelTypes CarType
		{ public: CarModelTypes get(System::Void) { return this->model_type; } }

		property Models::CarModelColor CarColor
		{ public: CarModelColor get(System::Void) { return this->model_color; } }

		property System::UInt32 CarSpeed
		{ public: System::UInt32 get(System::Void) { return this->model_speed; } }
	public:
		CarBaseModel(Models::CarModelTypes car_type, Models::CarModelColor color, System::UInt32 speed)
			: model_type(car_type), model_color(color), model_speed(speed) { }
		virtual ~CarBaseModel(System::Void) { }

		virtual System::Object^ Clone(System::Void) abstract;
		virtual System::Void car_drive(System::Void) abstract;
	};

	public ref class CarLightModel sealed : CarBaseModel 
	{
	public:
		CarLightModel(Models::CarModelTypes car_type, Models::CarModelColor color, System::UInt32 speed)
			: CarBaseModel(car_type, color, speed) { }
		virtual ~CarLightModel(System::Void) { }

		virtual System::Object^ Clone(System::Void) override { return gcnew CarLightModel(CarType, CarColor, CarSpeed); }
		virtual System::Void car_drive(System::Void) override { Console::WriteLine("Идем на легковой машине"); }
	};

	public ref class CarHeavyModel sealed : CarBaseModel
	{
	public:
		CarHeavyModel(Models::CarModelTypes car_type, Models::CarModelColor color, System::UInt32 speed)
			: CarBaseModel(car_type, color, speed) { }
		virtual ~CarHeavyModel(System::Void) { }

		virtual System::Object^ Clone(System::Void) override { return gcnew CarHeavyModel(CarType, CarColor, CarSpeed); }
		virtual System::Void car_drive(System::Void) override { Console::WriteLine("Идем на легковой машине"); }
	};

}