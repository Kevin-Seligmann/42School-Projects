#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:ClapTrap("Default_clap_name"),
	_name("Default")
{
	std::cout << this << " DiamondTrap Has been created with default constructor" << std::endl;
	_hitPoints = DiamondDefaultHitPoints;
	_energy = DiamondDefaultEnergy;
	_attackDamage = DiamondDefaultAttackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << this << " DiamondTrap Has been created with a name " << _name << std::endl;
	_hitPoints = DiamondDefaultHitPoints;
	_energy = DiamondDefaultEnergy;
	_attackDamage = DiamondDefaultAttackDamage;	
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
	:ClapTrap(src._name + "_clap_name"),
	FragTrap(src._name),
	ScavTrap(src._name),
	_name(src._name)
{
	std::cout << this << " DiamondTrap Has been created with copy constructor" << std::endl;
	_hitPoints = src._hitPoints;
	_energy = src._energy;
	_attackDamage = src._attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << this << " DiamondTrap Was destroyed" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	ScavTrap::operator=(rhs);
	FragTrap::operator=(rhs);
	_name = rhs._name;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Am I " << _name << " or " << ClapTrap::_name << "?" << std::endl;
}
