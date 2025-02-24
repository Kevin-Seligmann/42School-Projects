#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void)
:_type("AAnimal")
{
	std::cout << "AAnimal created with default constructor" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	_type = src._type;
	std::cout << "AAnimal created with copy constructor: " << _type << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destroyed: " << _type << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	_type = rhs._type;
	std::cout << "AAnimal modified with assignment: " << _type << std::endl;
	return *this;
}

std::string const & AAnimal::getType(void) const
{
	return _type;
}

void AAnimal::setType(std::string & type)
{
	_type = type;	
}

