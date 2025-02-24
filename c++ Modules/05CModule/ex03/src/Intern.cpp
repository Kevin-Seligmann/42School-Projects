#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << this << " 'Intern' "
	<< "Default constructor called."
	<< std::endl;
}

Intern::Intern(Intern const & src)
{
	(void) src;
	std::cout << this << " 'Intern' "
	<< "Copy constructor called."
	<< std::endl;
}

Intern::~Intern(void)
{
	std::cout << this << " 'Intern' "
	<< "Default destructor called."
	<< std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void) rhs;
	return *this;
}

AForm * Intern::makePresidentialPardonForm(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeRobotomyRequestForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::makeShrubberyCreationForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::makeForm(std::string const & name, std::string const & target)
{
	const int formQty = 3;

	typedef AForm * (Intern::*FunctionPointers)(std::string const &);
	FunctionPointers functionArray[3] = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};
	std::string formsName[formQty] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < formQty; i++)
	{
		if (formsName[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
    		return (this->*functionArray[i])(target);
		}
	}
	std::cout << "Intern tried to fill a form, but it doesn't exists" << std::endl;
	return NULL;
}

