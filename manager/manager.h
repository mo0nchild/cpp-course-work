#pragma once
#ifndef SERVICE_INCLUDE_STUFF
#define SERVICE_INCLUDE_STUFF
#include "service_collection/service_collection.h"
#include "service_manager/service_manager.h"
#include "service_manager_builder/service_manager_builder.h"
#include "service_attribute/service_attribute.h"
#include "service_items/service_items.h"

namespace Manager
{
	ref class TaxiBooking
	{
	public:
		TaxiBooking(void) { }
		static ServiceManagerBuilder^ create_builder(void) { return gcnew ServiceManagerBuilder(); }
	};
}

#endif // !SERVICE_INCLUDE_STUFF

