#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string const & name);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		void attack(const std::string& target);
		void guardGate();

	protected:
		static const unsigned int	ScavDefaultHitPoints = 100;
		static const unsigned int 	ScavDefaultEnergy = 50;
		static const unsigned int 	ScavDefaultAttackDamage = 20;
};

#endif
