#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string const & name): _name(name)
{
	std::cout << this << " 'Zombie'" << ". "
	<< "Constructor called. "
	<< "Name: " << _name << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << this << " 'Zombie'" << ". "
	<< "Default constructor called. " << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this << " 'Zombie'" << ". "
	<< "Default destructor called. "
	<< "Name: " << _name << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string const & name){
	this->_name = name;
}
