#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
:_type("WrongAnimal")
{
	std::cout << "WrongAnimal created with default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	_type = src._type;
	std::cout << "WrongAnimal created with copy constructor: " << _type << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed: " << _type << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	_type = rhs._type;
	std::cout << "WrongAnimal modified with assignment: " << _type << std::endl;
	return *this;
}

std::string const & WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::setType(std::string & type)
{
	_type = type;	
}

void WrongAnimal::makeSound() const
{
	std::cout << _type << ": <<The sound of a WrongAnimal>>" << std::endl;
}
