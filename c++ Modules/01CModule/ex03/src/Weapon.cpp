#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string const & type)
	:_type(type)
{
	std::cout << this << " 'Weapon'" << ". "
	<< "Constructor called. "
	<< "Type: " << type <<  ". " << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this << " 'Weapon'" << ". "
	<< "Destructor called. "
	<< "Type: " << _type << ". " << std::endl;
}

std::string const & Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(std::string const & type)
{
	_type = type;
}
