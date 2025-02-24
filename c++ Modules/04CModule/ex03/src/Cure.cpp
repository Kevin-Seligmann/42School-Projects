#include "Cure.hpp"
#include <iostream>

// Constructors, destructors
Cure::Cure(void)
:AMateria("cure")
{
	std::cout << "Default constructor 'Cure'" << std::endl;
}

Cure::Cure(Cure const & src)
:AMateria("cure")
{
	(void) src;
	std::cout << "Copy constructor 'Cure': " << _type <<std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Default Destructor 'Cure': " << _type <<std::endl;
}

// Assignment
Cure & Cure::operator=(Cure const & rhs)
{
	(void) rhs;
	std::cout << "Assingment 'Cure' (type unchanged): " << _type << std::endl;
	return *this;
}

// Members
AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
