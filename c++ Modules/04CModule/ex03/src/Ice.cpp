#include "Ice.hpp"
#include <iostream>

// Constructors, destructors
Ice::Ice(void)
:AMateria("ice")
{
	std::cout << "Default constructor 'Ice'" << std::endl;
}

Ice::Ice(Ice const & src)
:AMateria("ice")
{
	(void) src;
	std::cout << "Copy constructor 'Ice': " << _type <<std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Default Destructor 'Ice': " << _type <<std::endl;
}

// Assignment
Ice & Ice::operator=(Ice const & rhs)
{
	(void) rhs;
	std::cout << "Assingment 'Ice' (type unchanged): " << _type << std::endl;
	return *this;
}

// Members
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
