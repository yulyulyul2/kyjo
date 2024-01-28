#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
	if (rand() % 3 == 0) 
		return (new A());
	else if (rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This pointer is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "This pointer is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "This pointer is C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "This reference is A" << std::endl;
		(void)a;
	}
  	catch (std::exception&) {}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "This reference is B" << std::endl;
		(void)b;
	}
  	catch (std::exception&) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "This reference is C" << std::endl;
		(void)c;
	}
  	catch (std::exception&) {}
}
