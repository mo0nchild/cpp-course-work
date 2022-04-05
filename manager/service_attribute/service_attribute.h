#pragma once

namespace Manager 
{
	using namespace System::Reflection;
	namespace ServiceAttribute
	{
		[System::AttributeUsage(System::AttributeTargets::Class)]
		ref class ServiceRequireAttribute sealed : System::Attribute
		{
		private: System::Type^ requirement;
		public:
			ServiceRequireAttribute(System::Type^ list) { this->Requirement = list; }

			property System::Type^ Requirement
			{
			public: System::Type^ get(System::Void) { return requirement; }
			private: System::Void set(System::Type^ value) { requirement = value; }
			};
		};

		[System::AttributeUsage(System::AttributeTargets::Constructor)]
		ref class ServiceRequireTargetAttribute sealed : System::Attribute { };
	}
}