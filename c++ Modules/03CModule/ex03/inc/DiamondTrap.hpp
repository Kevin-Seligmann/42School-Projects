#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);

		DiamondTrap & operator=(DiamondTrap const & rhs);

		void whoAmI();

	private:
		std::string _name;

		static const unsigned int	DiamondDefaultHitPoints = FragTrap::FragDefaultHitPoints;
		static const unsigned int 	DiamondDefaultEnergy = ScavTrap::ScavDefaultEnergy;
		static const unsigned int 	DiamondDefaultAttackDamage = FragTrap::FragDefaultAttackDamage;
};

#endif
