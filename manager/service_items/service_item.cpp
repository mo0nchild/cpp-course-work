#include "service_items.h"

using namespace Manager;

Generic::List<System::Type^>^ ServiceProvider::get_dependencies(System::Void)
{
	Generic::List<System::Type^>^ result = gcnew Generic::List<System::Type^>(
		this->service_dependencies->Count);

	for each (System::Type^ item in this->service_dependencies) result->Add(item);
	return result;
}