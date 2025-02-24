#include "ClapTrap.hpp"
#include <iostream>

// Constructors, destructors, copy, assignment
ClapTrap::ClapTrap(void)
	:_name("Default ClapTrap")
	,_hitPoints(10)
	,_energy(10)
	,_attackDamage(0)
{
	_printStats();
	std::cout << _name << " Has been created with default constructor" << std::endl;	
}
	
ClapTrap::ClapTrap(std::string const & name)
	:_name(name)
	,_hitPoints(10)
	,_energy(10)
	,_attackDamage(0)
{
	_printStats();
	std::cout << _name << " Has been created with name " << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
	:_name(src._name)
	,_hitPoints(src._hitPoints)
	,_energy(src._energy)
	,_attackDamage(src._attackDamage)
{
	_printStats();
	std::cout << _name << " Has been created with copy constructor " << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	_printStats();
	std::cout << _name << " was destroyed" << std::endl;
}
	
ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	if (&src != this) 
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energy = src._energy;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

// Print stats
void ClapTrap::_printStats(void) const
{
	std::cout << "[Health Points:" << _hitPoints
	<< " Energy:" << _energy 
	<< " Attack Damage:" << _attackDamage  << "] "
	<< "ClapTrap ";
}


// Claptrap actions
void ClapTrap::attack(std::string const & target)
{
	_printStats();
	if (_hitPoints == 0)
	{
		std::cout << _name << " Tried to attack " << target
		<< ", but it's in critical state" << std::endl;
	}
	else if (_energy == 0)
	{
		std::cout << _name << " Tried to attack " << target
		<< ", but it's has no energy" << std::endl;
	}
	else 
	{
		_energy --;
		std::cout << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_printStats();
	if (_energy == 0)
	{
		std::cout << _name << " Tried to repair itself"
		<< ", but it has no energy" << std::endl;
	}
	else if (_hitPoints == 0)
	{
		std::cout << _name << " Tried to repair itself"
		<< ", but it's in critical state" << std::endl;
	}
	else 
	{
		_hitPoints += amount;
		_energy --;
		std::cout << _name << " Got repaired by " << amount
		<< " points of health" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_printStats();
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
	}
	else
	{
		_hitPoints -= amount;
	}
	std::cout << _name << " Took " << amount
	<< " points of damage!, ";
	std::cout << _hitPoints << " Hit points left" << std::endl;
}
