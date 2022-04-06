#include "service_items.h"

using namespace Manager;

System::Collections::Generic::List<System::Type^>^ ServiceProvider::get_dependencies(System::Void)
{
	List<System::Type^>^ result = gcnew List<System::Type^>(this->service_dependencies->Count);
	for each (auto item in service_dependencies) result->Add(item);

	return result;
}