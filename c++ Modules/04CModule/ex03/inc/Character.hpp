#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter 
{
public:
	Character(void);
	Character(std::string const & name);
	Character(Character const & src);
	~Character(void);

	Character & operator=(Character const & rhs);

	std::string const & getName() const ;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
	void cleanFloor();

private:
	static const int 	_MaxInventory = 4;
	static const int 	_FloorLimit = 100;
	std::string			_name;
	AMateria			*_inventory[_MaxInventory];
	AMateria			*_floor[_FloorLimit];
};

#endif
