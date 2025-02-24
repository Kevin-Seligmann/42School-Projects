#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern & operator=(Intern const & rhs);

	AForm * makeForm(std::string const & name, std::string const & target);

private:
	AForm * makePresidentialPardonForm(std::string const & target);
	AForm * makeRobotomyRequestForm(std::string const & target);
	AForm * makeShrubberyCreationForm(std::string const & target);
};

#endif
