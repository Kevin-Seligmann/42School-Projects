#include <iostream>
#include "ScavTrap.hpp"

// Constructors, destructores, copy, assignment
ScavTrap::ScavTrap(void)
{
	std::cout << this << " ScavTrap Has been created with default constructor" << std::endl;
	_hitPoints = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const & name)
	:ClapTrap(name)
{
	std::cout << this << " ScavTrap Has been created with a name " << _name << std::endl;
	_hitPoints = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src)
	:ClapTrap(src)
{
	std::cout << this << " ScavTrap Has been created with copy constructor" << std::endl;
	_hitPoints = src._hitPoints;
	_energy = src._energy;
	_attackDamage = src._attackDamage;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this << " ScavTrap Was destroyed" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

// Other members
void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " <<_name << " Tried to attack " << target
		<< ", but it's in critical state" << std::endl;
	}
	else if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name << " Tried to attack " << target
		<< ", but it's has no energy" << std::endl;
	}
	else 
	{
		_energy --;
		std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} 
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is in Gatekeeper mode" << std::endl;
}
