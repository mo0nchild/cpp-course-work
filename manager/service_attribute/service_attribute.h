#pragma once

namespace Manager 
{
	using namespace System::Reflection;
	
	inline namespace ServiceAttribute
	{
		[System::AttributeUsage(System::AttributeTargets::Class)]
		ref class ServiceRequireAttribute sealed : System::Attribute
		{
		private: System::Type^ requirement;
		public:

			ServiceRequireAttribute(System::Type^ list) { this->Requirement = list; }
			virtual ~ServiceRequireAttribute(System::Void) { }

			property System::Type^ Requirement
			{
			public: System::Type^ get(System::Void) { return this->requirement; }
			private: System::Void set(System::Type^ value) { this->requirement = value; }
			};

		};
	}
}