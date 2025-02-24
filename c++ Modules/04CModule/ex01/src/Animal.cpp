#include <iostream>
#include "Animal.hpp"

Animal::Animal(void)
:_type("Animal")
{
	std::cout << this << " Animal created with default constructor" << std::endl;
}

Animal::Animal(Animal const & src)
{
	_type = src._type;
	std::cout << this << " Animal created with copy constructor: " << _type << std::endl;
}

Animal::~Animal(void)
{
	std::cout << this <<  " Animal destroyed: " << _type << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	_type = rhs._type;
	std::cout << this << " Animal modified with assignment: " << _type << std::endl;
	return *this;
}

std::string const & Animal::getType(void) const
{
	return _type;
}

void Animal::setType(std::string & type)
{
	_type = type;	
}

void Animal::makeSound() const
{
	std::cout << _type << ": <<The sound of an animal>>" << std::endl;
}
