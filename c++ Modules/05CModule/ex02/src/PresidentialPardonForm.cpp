#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
:AForm("Presidental pardon", 25, 5),
_target("Unknown")
{
	std::cout << this << " 'AForm' "
	<< "Default constructor called. "
	<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
:AForm("Presidental pardon", 25, 5),
_target(target)
{
	std::cout << this << " 'PresidentialPardonForm' "
	<< "Constructor called. "
	<< "Target: " << target << ". "
	<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
:AForm("Presidental pardon", 25, 5),
_target(src._target)
{
	std::cout << this << " 'PresidentialPardonForm' "
	<< "Copy constructor called. "
	<< "Target: " << src._target << ". "
	<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << this << " 'PresidentialPardonForm' "
	<< "Default destructor called. "
	<< "Target: " << _target << ". "
	<< std::endl;
}


PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	_target = rhs._target;
	return *this;
}


void PresidentialPardonForm::concreteExecution(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
