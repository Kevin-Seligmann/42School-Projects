#include <iostream>
#include "Character.hpp"

// Constructors, destructors
Character::Character(void)
:_name("Anonymous")
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		_inventory[i] = NULL;
	}
	for (int i = 0; i < _FloorLimit; i ++)
	{
		_floor[i] = NULL;
	}
	std::cout << "Default constructor called, character " << _name << std::endl;
}

Character::Character(std::string const & name)
:_name(name)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		_inventory[i] = NULL;
	}
	for (int i = 0; i < _FloorLimit; i ++)
	{
		_floor[i] = NULL;
	}
	std::cout << "Constructor called, character " << _name << std::endl;
}

Character::Character(Character const & src)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (src._inventory[i] != NULL)
		{
			_inventory[i] = src._inventory[i]->clone();
		}
		else
		{
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < _FloorLimit; i ++)
	{
		_floor[i] = NULL;
	}
	_name = src._name;
	std::cout << "Copy constructor called, character " << _name << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
		}
	}
	cleanFloor();
	std::cout << "Default destructor called, character " << _name << std::endl;
}

// Assignment
Character & Character::operator=(Character const & rhs)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (rhs._inventory[i] != NULL)
		{
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	_name = rhs._name;
	std::cout << "Assignment called, character " << _name << std::endl;
	return *this;
}

// Getter
std::string const & Character::getName() const 
{
	return _name;
}


// Members
void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full, character " << _name << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _MaxInventory || _inventory[idx] == NULL)
	{
		std::cout << "Can't unequip this" << std::endl;
	}
	else 
	{
		for (int i = 0; i < _FloorLimit; i++)
		{
			if (_floor[i] == NULL)
			{
				std::cout << "Unequiped " << _inventory[idx]->getType() << std::endl;
				_floor[i] = _inventory[idx];
				_inventory[idx] = NULL;
				return ;
			}
		}
		std::cout << "Floor full, clean it to unequip safely" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _MaxInventory || _inventory[idx] == NULL)
	{
		std::cout << "Can't use this" << std::endl;
	}
	else 
	{
		_inventory[idx]->use(target);
	}
}

void Character::cleanFloor()
{
	for (int i = 0; i < _FloorLimit; i ++)
	{
		if (_floor[i])
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}
