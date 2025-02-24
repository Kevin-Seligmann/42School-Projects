#include "AMateria.hpp"
#include <iostream>

// Constructors, destructors
AMateria::AMateria(void){}

AMateria::AMateria(std::string const & type)
:_type(type)
{
	std::cout << "Type constructor 'AMateria': " << _type << std::endl;
}

AMateria::AMateria(AMateria const & src)
:_type(src._type)
{
	(void) src;
	std::cout << "Copy constructor 'AMateria': " << _type << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "Default destructor 'AMateria': " << _type << std::endl;
}

// Assignment
AMateria & AMateria::operator=(AMateria const & rhs)
{
	(void) rhs;
	std::cout << "Assingment 'AMateria': " << _type << std::endl;
	return *this;
}

// Getters
std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	if (_type == "ice")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else if (_type == "cure")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
