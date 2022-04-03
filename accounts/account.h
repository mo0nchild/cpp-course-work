#pragma once
#include <string>

using namespace System;

namespace Accounts
{
	using namespace std;

	ref class Account 
	{
		uint16_t id;
		String^ name;

	public:
		
		Account(uint16_t id, String^ name) : id(id), name(name)
		{ }

		property String^ Name
		{
			String^ get() { return name; }
			void set(String^ value) { name = value; }
		};

	};

	ref class Admin: public Account
	{
		
	};

	ref class Driver: public Account {};

	ref class Passenger: public Account {};

}