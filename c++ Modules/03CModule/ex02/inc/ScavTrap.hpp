#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string const & name);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		void attack(const std::string& target);
		void guardGate();
};
