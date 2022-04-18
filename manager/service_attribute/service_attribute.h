#pragma once

namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	
	inline namespace ServiceAttribute
	{
		[System::AttributeUsage(System::AttributeTargets::Class, AllowMultiple = true)]
		public ref class ServiceRequireAttribute sealed : System::Attribute
		{
		private:	System::Type^ requirement = nullptr;
		public:
			property System::Type^ Requirement
			{
			public: System::Type^ get(System::Void) { return this->requirement; }
			private: System::Void set(System::Type^ value) { this->requirement = value; }
			};
		public:
			ServiceRequireAttribute(System::Type^ list) : System::Attribute() { this->Requirement = list; }
			virtual ~ServiceRequireAttribute(System::Void) { delete this->requirement; }
		};
	}
}