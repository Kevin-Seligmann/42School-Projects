#include <cstdlib> 
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
:AForm("Robotomy request", 72, 45),
_target("Unknown")
{
	std::cout << this << " 'AForm' "
	<< "Default constructor called. "
	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
:AForm("Robotomy request", 72, 45),
_target(target)
{
	std::cout << this << " 'RobotomyRequestForm' "
	<< "Constructor called. "
	<< "Target: " << target << ". "
	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
:AForm("Robotomy request", 72, 45),
_target(src._target)
{
	std::cout << this << " 'RobotomyRequestForm' "
	<< "Copy constructor called. "
	<< "Target: " << src._target << ". "
	<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << this << " 'RobotomyRequestForm' "
	<< "Default destructor called. "
	<< "Target: " << _target << ". "
	<< std::endl;
}


RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	_target = rhs._target;
	return *this;
}


void RobotomyRequestForm::concreteExecution(void) const
{
	std::cout << "DRBUM BDURM BDRUM BDRUM... ";
	
	if (rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized"  << std::endl; 		
	}
	else 
	{
		std::cout << "Robotomy failed on " << _target << std::endl;
	}
}
