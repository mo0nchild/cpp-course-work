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
			explicit ServiceRequireAttribute(System::Type^ list) : System::Attribute() 
			{ this->Requirement = list; }
			virtual ~ServiceRequireAttribute(System::Void) { delete this->requirement; }
		};

		[System::AttributeUsage(System::AttributeTargets::Constructor, AllowMultiple = false)]
		public ref class ServiceConfigurationAttribute sealed : System::Attribute
		{
		private: System::String^ configuration_name = nullptr;
		public:
			property System::String^ Configuration
			{
			public: System::String^ get(System::Void) { return this->configuration_name; }
			private: System::Void set(System::String^ value) { this->configuration_name = value; }
			}
		public:
			explicit ServiceConfigurationAttribute(System::String^ conf) : System::Attribute() 
			{ this->configuration_name = conf; }

			virtual ~ServiceConfigurationAttribute(System::Void) { delete configuration_name; }
		};
	}
}