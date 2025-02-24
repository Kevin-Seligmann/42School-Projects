#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << _type << ": Constructed by default (WrongCat)" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
:WrongAnimal()
{
	_type = src._type;
	std::cout << _type << ": Constructed by copy (WrongCat)" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << _type << ": Destroyed (WrongCat)" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	_type = rhs._type;
	std::cout << _type << ": Assigned (WrongCat)" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << _type << ": Meow..." << std::endl;
}
