#pragma once
//template<typename T> class Type
//{
//public:
//	virtual T* allocate()const { return new T; }
//	virtual T* cast(void* obj)const { return static_cast<T*>(obj); }
//};

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;

namespace Services
{
	generic<class TService> public ref class ServiceProvider
	{

	public:
		TService service;
		ServiceProvider(TService service) { this->service = service; }

		virtual TService select() 
		{
			return service;
		}

	};

	public ref struct ITaxiCollection abstract
	{
		virtual System::UInt32 get_size() abstract;
	};

	public ref class TaxiService
	{

	};

	public ref class TaxiServiceCollection: public ITaxiCollection
	{
	public:
		ref struct ServiceRecord
		{
			Type^ provider;
			TaxiService^ service;

			ServiceRecord(Type^ provider, TaxiService^ service)
			{ 
				this->provider = provider;
				this->service = service;
			}
		};

		List<ServiceRecord^>^ collection;
		TaxiServiceCollection() 
		{ 
			collection = gcnew List<ServiceRecord^>();
		}

		System::UInt32 get_size() override { return collection->Count; }
		
		template<class TProvider, class TService> bool add_service(TaxiService^ new_service)
		{
			auto my_service = safe_cast<TService^>(new_service);
			Console::Write("Called from TaxiServiceCollection::add_service\t");
			my_service->call();

			ServiceRecord^ record = gcnew ServiceRecord(TProvider::typeid, new_service);

			collection->Add(record);
			return true;
		}
	};
}

namespace Base 
{
	public ref class ServiceRegistration
	{
		Services::TaxiServiceCollection^ collection;
	public:
		ServiceRegistration(Services::TaxiServiceCollection^ list)
		{ 
			this->collection = list;
		}

		template<class TProvider, class TService> bool registration(Services::TaxiService^ service)
		{
			collection->add_service<TProvider, TService>(service);
			return true;
		}
	};

	public ref class ServiceManager
	{
	public:
		Services::TaxiServiceCollection^ services;
		ServiceRegistration^ registration;

		ServiceManager()
		{
			services = gcnew Services::TaxiServiceCollection();
			registration = gcnew ServiceRegistration(services);
		}

		template<class TService> Services::ServiceProvider<TService>^ get_service()
		{
			Console::WriteLine("CollectionSize:\t" + services->collection->Count);
			for(int i = 0; i < services->collection->Count; i++)
			{
				Services::TaxiServiceCollection::ServiceRecord^ record = services->collection[i];
				if (record->service->GetType() == TService::typeid)
				{
					Console::WriteLine("Type:\t" + record->provider->Name);

					Object^ type = Activator::CreateInstance(record->provider, record->service);
					Console::WriteLine("Instance:\t" + type->GetType()->Name);

					Services::ServiceProvider<TService>^ provider = safe_cast<Services::ServiceProvider<TService>^>(type);
					provider->service = (TService)record->service;

					return provider;
				}
			}
			
		}
	};

	public ref class TaxiBooking
	{
	public:
		ServiceManager^ manager;
		TaxiBooking() { manager = gcnew ServiceManager(); }
	};

}

namespace Main 
{
	using namespace System;
	using namespace Base;
	using namespace Services;

	public ref class MyService : Services::TaxiService
	{
	public:
		MyService() {}
		void call() { Console::WriteLine("My Service is Cool"); }
	};

	public ref class MyServiceProvider : Services::ServiceProvider<MyService^>
	{
	public:
		MyServiceProvider(MyService^ serv) : Services::ServiceProvider<MyService^>(serv)
		{
			test_value = 9999;
		}

		int test_value;
	};

	ref class Program 
	{
	public: static void Main(void)
		{
			Base::TaxiBooking^ booking = gcnew Base::TaxiBooking();
			ServiceManager^ manager = booking->manager;

			auto service = gcnew MyService();

			manager->registration->registration<MyServiceProvider, MyService>(service);
			MyServiceProvider^ provider = (MyServiceProvider^)(manager->get_service<MyService^>());

			auto my_service = provider->select();
			my_service->call();

			Console::WriteLine(provider->test_value);
		}
	};
}
