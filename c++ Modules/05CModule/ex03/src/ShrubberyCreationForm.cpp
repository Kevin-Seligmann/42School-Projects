#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
:AForm("Shrubbery creation", 145, 137),
_target("Unknown")
{
	std::cout << this << " 'AForm' "
	<< "Default constructor called. "
	<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
:AForm("Shrubbery creation", 145, 137),
_target(target)
{
	std::cout << this << " 'ShrubberyCreationForm' "
	<< "Constructor called. "
	<< "Target: " << target << ". "
	<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
:AForm("Shrubbery creation", 145, 137),
_target(src._target)
{
	std::cout << this << " 'ShrubberyCreationForm' "
	<< "Copy constructor called. "
	<< "Target: " << src._target << ". "
	<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << this << " 'ShrubberyCreationForm' "
	<< "Default destructor called. "
	<< "Target: " << _target << ". "
	<< std::endl;
}


ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	_target = rhs._target;
	return *this;
}


void ShrubberyCreationForm::concreteExecution(void) const
{
	try
	{
		std::ofstream out((std::string(_target) + "_shrubbery").c_str());

		std::string tree (
		"                                                         ."
		"\n										.         ;  "
		"\n			.              .              ;%     ;;   "
		"\n			,           ,                :;%  %;   "
		"\n				:         ;                   :;%;'     .,   "
		"\n	,.        %;     %;            ;        %;'    ,;"
		"\n		;       ;%;  %%;        ,     %;    ;%;    ,%'"
		"\n		%;       %;%;      ,  ;       %;  ;%;   ,%;' "
		"\n		;%;      %;        ;%;        % ;%;  ,%;'"
		"\n			`%;.     ;%;     %;'         `;%%;.%;'"
		"\n			`:;%.    ;%%. %@;        %; ;@%;%'"
		"\n				`:%;.  :;bd%;          %;@%;'"
		"\n				`@%:.  :;%.         ;@@%;'   "
		"\n					`@%.  `;@%.      ;@@%;         "
		"\n					`@%%. `@%%    ;@@%;        "
		"\n						;@%. :@%%  %@@%;       "
		"\n						%@bd%%%bd%%:;     "
		"\n							#@%%%%%:;;"
		"\n							%@@%%%::;"
		"\n							%@@@%(o);  . '         "
		"\n							%@@@o%;:(.,'         "
		"\n						`.. %@@@o%::;         "
		"\n						`)@@@o%::;         "
		"\n							%@@(o)::;        "
		"\n						.%@@@@%::;         "
		"\n						;%@@@@%::;.          "
		"\n						;%@@@@%%:;;;. "
		"\n					...;%@@@@@%%:;;;;,..    Gilo97 https://ascii.co.uk/art/tree\n");

		out << tree;
	}
	catch (std::exception &e)
	{
		std::cout << "Shrubbery failed" << std::endl;
	}

}

