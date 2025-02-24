#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap(std::string const & name);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);

		void highFivesGuys();

	protected:
		static const unsigned int	FragDefaultHitPoints = 100;
		static const unsigned int 	FragDefaultEnergy = 100;
		static const unsigned int 	FragDefaultAttackDamage = 30;
};

#endif
