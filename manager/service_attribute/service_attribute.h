#pragma once


namespace Manager 
{
	using namespace System;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;

	namespace ServiceAttribute
	{
		[System::AttributeUsage(System::AttributeTargets::Class)]
		ref class ServiceRequireAttribute sealed : System::Attribute
		{
			Type^ requirement;
		public:

			property Type^ Requirement
			{
			public: Type^ get(void) { return requirement; }
			private: void set(Type^ value) { requirement = value; }
			};

			ServiceRequireAttribute(Type^ list) { this->Requirement = list; }
		};

		[System::AttributeUsage(System::AttributeTargets::Constructor)]
		ref class ServiceRequireTargetAttribute sealed : System::Attribute { };
	}
}