#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int i;


	i = rand() % 3;
	switch(i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{

	if (dynamic_cast<A *>(p))
	{
		std::cout << "By pointer. Type A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "By pointer. Type B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "By pointer. Type C" << std::endl;
		return ;
	}

	std::cerr << "???" << std::endl;
}

void identify(Base& p)
{
	bool exception = false;

	try
	{
		dynamic_cast<A &>(p);
	}
	catch (std::exception & e)
	{
		exception = true;
	}
	if (exception == false)
	{
		std::cout << "By reference. Type A" << std::endl;
		return ;
	}

	exception = false;
	try
	{	
		dynamic_cast<B &>(p);
	}
	catch (std::exception & e)
	{
		exception = true;
	}
	if (exception == false)
	{
		std::cout << "By reference. Type B" << std::endl;
		return ;
	}

	exception = false;
	try
	{
		dynamic_cast<C &>(p);
	}
	catch (std::exception & e)
	{
		exception = true;
	}
	if (exception == false)
	{
		std::cout << "By reference. Type C" << std::endl;
		return ;
	}
	std::cerr << "???" << std::endl;
}

int main()
{
	Base * p;

	srand(time(NULL));
	p = generate();
	identify(p);
	identify(*p);
}
