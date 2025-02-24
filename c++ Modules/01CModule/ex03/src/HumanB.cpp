#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string const & name)
	:_name(name)
	,_weapon(NULL)
{
	std::cout << this << " 'HumanB'" << ". "
	<< "Constructor called. "
	<< "Name: " << _name << ". " << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this << " 'HumanB'" << ". "
	<< "Destructor called. "
	<< "Name: " << _name << ". "
	<< "Weapon " << _weapon << std::endl;
}

void HumanB::attack(void) const
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon & weapon)
{
	_weapon = &weapon;
}
