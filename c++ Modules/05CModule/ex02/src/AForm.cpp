#include "AForm.hpp"

// Constructors, destructor, assignemnt
AForm::AForm(void)
:_name("Unnamed Form"),
_itsSigned(false),
_signGrade(150),
_executionGrade(150)
{
	std::cout << this << " 'AForm' "
	<< "Default Constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}

AForm::AForm(std::string const & name, int signGrade, int executionGrade)
:_name(name),
_itsSigned(false),
_signGrade(signGrade),
_executionGrade(executionGrade)
{
	if (signGrade < Bureaucrat::MaxGrade || executionGrade < Bureaucrat::MaxGrade)
	{
		throw AForm::GradeTooHighException();
	}
	if (signGrade > Bureaucrat::MinGrade || executionGrade > Bureaucrat::MinGrade)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this << " 'AForm' "
	<< "Constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}
AForm::AForm(AForm const & src)
:_name(src._name),
_itsSigned(src._itsSigned),
_signGrade(src._signGrade),
_executionGrade(src._executionGrade)
{
	std::cout << this << " 'AForm' "
	<< "Copy constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}

AForm::~AForm(void)
{
	std::cout << this << " 'AForm' "
	<< "Destructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< "Signed: " << _itsSigned << ". "
	<< std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
	_itsSigned = rhs._itsSigned;
	return *this;
}

// Getters
std::string const & AForm::getName(void) const
{
	return _name;
}

int AForm::getSignGrade(void) const
{
	return _signGrade;
}

int AForm::getExecutionGrade(void) const
{
	return _executionGrade;
}

bool AForm::getItsSigned(void) const
{
	return _itsSigned;
}

// Members
void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw AForm::GradeTooLowException();
	}
	_itsSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _executionGrade)
	{
		throw GradeTooLowException();
	}
	if (_itsSigned == false)
	{
		throw FormNotSignedExpcetion();
	}
	else
	{
		concreteExecution();
	}
}

// Insertion

std::ostream & operator<<(std::ostream & out, AForm const & AForm)
{
	std::cout << "Form: '" << "Name: " << AForm.getName() << ". "
	<< "Sign grade: " << AForm.getSignGrade() << ". "
	<< "Execution grade: " << AForm.getExecutionGrade() << ". "
	<< "Status: ";
	if (AForm.getItsSigned())
	{
		std::cout << "Signed";
	}
	else 
	{
		std::cout << "Not signed";
	}
	std::cout << "'";
	return out;
}
