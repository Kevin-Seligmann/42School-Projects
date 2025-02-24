#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << this << " " << _type << ": Constructed by default (Dog)" << std::endl;
}

Dog::Dog(Dog const & src)
:Animal()
{
	_type = src._type;
	std::cout << this << " " << _type << ": Constructed by copy (Dog)" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << this << " " << _type << ": Destroyed (Dog)" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	_type = rhs._type;
	std::cout << this << " " << _type << ": Assigned (Dog)" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << _type << ": Woof woof!" << std::endl;
}
