#pragma once

namespace Models 
{
	public enum class CarLightModelType { CarTypeBus = 0, CarTypeTrack = 1, CarTypeBoat = 2 };

	public enum class CarHeavyModelTypes { CarTypeEconom, CarTypePremium, CarTypeChild };

	public ref class CarBaseModel abstract
	{
	public:
		CarBaseModel(System::Void) {}
		virtual ~CarBaseModel(System::Void) { }
	};

	public ref class CarLightModel sealed : CarBaseModel 
	{
		CarLightModelType light_transport_type;
	public:
		CarLightModel(System::Void): CarBaseModel() { }
		virtual ~CarLightModel(System::Void) { }
	};

	public ref class CarHeavyModel sealed : CarBaseModel
	{
		CarHeavyModelTypes heavy_transport_type;
	public:
		CarHeavyModel(System::Void) : CarBaseModel() { }
		virtual ~CarHeavyModel(System::Void) { }
	};

}