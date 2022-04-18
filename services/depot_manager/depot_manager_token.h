#pragma once
#include "../../models/cars_model/cars_model.h"

namespace Services 
{
	using namespace System;
	using namespace System::Collections;

	public ref class DriveComplexTokenException sealed : System::Exception
	{
	private:	System::Type^ exception_attach_from = nullptr;
	public:
		property System::Type^ AttachFrom 
		{ public: System::Type^ get(System::Void) { return this->exception_attach_from; } }

		virtual property System::String^ Message
		{ 
		public: System::String^ get(System::Void) override 
			{ return "From " + exception_attach_from->ToString() + ": " + Exception::Message; }
		}
	public:
		DriveComplexTokenException(System::Type^ from, System::String^ message) : System::Exception(message) 
		{ this->exception_attach_from = from; }
		virtual ~DriveComplexTokenException(System::Void) { delete exception_attach_from; }
	};

	public value struct DriveComplexToken sealed : System::ICloneable
	{
	public:	enum class DriverStateType : System::UInt16 { Busy, Ready, Idle };
	public:		property Models::CarBaseModel^ CarModel;

	private:	Services::DriveComplexToken::DriverStateType driver_state;
	private:	System::Guid driver_guid;
	public:
		property System::Guid DriverGuid
		{ 
		public:		System::Guid get(System::Void) { return this->driver_guid; }
		protected:	System::Void set(System::Guid value) { this->driver_guid = value; }
		};
		property Services::DriveComplexToken::DriverStateType DriverState
		{ 
		public:	DriverStateType get(System::Void) { return this->driver_state; } 
		public: System::Void set(DriverStateType value) { this->driver_state = value; }
		};

	public: DriveComplexToken(Models::CarBaseModel^ car_model, System::Guid driver_guid) 
		: driver_guid(System::Guid::NewGuid()), driver_state(DriverStateType::Busy) 
		{ this->CarModel = car_model;}

		virtual System::Object^ Clone(System::Void) override
		{
			Services::DriveComplexToken^ token = gcnew Services::DriveComplexToken(
				(CarBaseModel^)CarModel->Clone(), this->driver_guid);
			token->DriverState = this->driver_state;
			return token;
		}

	};
}