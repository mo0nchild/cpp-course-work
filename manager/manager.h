#pragma once

#ifndef MANAGER_INCLUDE_STUFF
#define MANAGER_INCLUDE_STUFF

#include "service_collection/service_collection.h"
#include "service_manager/service_manager.h"
#include "service_manager_builder/service_manager_builder.h"
#include "service_attribute/service_attribute.h"
#include "service_items/service_items.h"

namespace Manager
{
	public ref class ManagerBooking sealed
	{
	public: ManagerBooking(System::Void) { }
	public:	virtual ~ManagerBooking(System::Void) { }

	public: static ServiceManagerBuilder^ create_builder(System::Void) 
		{ return gcnew Manager::ServiceManagerBuilder(); }
	};
}

#endif // !MANAGER_INCLUDE_STUFF

