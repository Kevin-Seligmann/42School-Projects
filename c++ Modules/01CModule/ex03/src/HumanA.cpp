#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const & name, Weapon & weapon)
	:_name(name)
	,_weapon(weapon)
{
	std::cout << this << " 'HumanA'" << ". "
	<< "Constructor called. "
	<< "Name: " << _name << ". "
	<< "Weapon " << &weapon << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this << " 'HumanA'" << ". "
	<< "Destructor called. "
	<< "Name: " << _name << ". "
	<< "Weapon " << &_weapon << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
