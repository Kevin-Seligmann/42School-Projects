#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* form;
	
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *form  << std::endl;;
	delete form;
	std::cout << std::endl;

	form = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *form << std::endl;;
	delete form;
	std::cout << std::endl;
	
	form = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *form << std::endl;;
	delete form;
	std::cout << std::endl;

	form = someRandomIntern.makeForm("Nuclear war plebiscite", "DJThomas");
}
