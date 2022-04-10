#pragma once
#include "../../manager/manager.h"

namespace Services 
{
	public ref class AccountManager : Manager::ServiceBase
	{
	public:
		AccountManager(System::Void) : Manager::ServiceBase() { }
		virtual ~AccountManager(System::Void) { }
	};
}