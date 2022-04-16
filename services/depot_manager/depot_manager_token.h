#pragma once
#include "../../models/cars_model/cars_model.h"

namespace Services 
{
	public ref class DriveComplexTokenException sealed : System::Exception
	{
	public:
		DriveComplexTokenException(System::String^ message) : System::Exception(message) { }
		virtual ~DriveComplexTokenException(System::Void) { }
	};

	public value struct DriveComplexToken sealed
	{
	public:	enum class DriverStateType : System::UInt16 { Busy, Ready, Idle };
	public:	property Models::CarBaseModel^ CarModel;
	public:	property Models::AccountDriverModel^ DriverModel;

	private:	System::Guid complex_guid;
	private:	Services::DriveComplexToken::DriverStateType driver_state;
	public:
		property System::Guid ComplexGuid
		{ public:	System::Guid get(System::Void) { return this->complex_guid; } };

		property Services::DriveComplexToken::DriverStateType DriverState
		{ public:	DriverStateType get(System::Void) { return this->driver_state; } };

	public: DriveComplexToken(Models::CarBaseModel^ car_model, Models::AccountDriverModel^ driver_model)
		: complex_guid(System::Guid::NewGuid()), driver_state(DriverStateType::Busy)
		{ this->CarModel = car_model; this->DriverModel = driver_model; }
	};
}