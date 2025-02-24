#include <iostream>
#include "FragTrap.hpp"

// Constructors, destructores, copy, assignment
FragTrap::FragTrap(void)
{
	std::cout << this << " FragTrap Has been created with default constructor" << std::endl;
	_hitPoints = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string const & name)
	:ClapTrap(name)
{
	std::cout << this << " FragTrap Has been created with a name " << _name << std::endl;
	_hitPoints = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src)
	:ClapTrap(src)
{
	std::cout << this << " FragTrap Has been created with copy constructor" << std::endl;
	_hitPoints = src._hitPoints;
	_energy = src._energy;
	_attackDamage = src._attackDamage;
}

FragTrap::~FragTrap(void)
{
	std::cout << this << " FragTrap Was destroyed" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << ": 'HIGH FIVE !'" << std::endl;
}
