#include "Form.hpp"

// Constructors, destructor, assignemnt
Form::Form(void)
:_name("Unnamed Form"),
_itsSigned(false),
_signGrade(150),
_executionGrade(150)
{
	std::cout << this << " 'Form' "
	<< "Default Constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}

Form::Form(std::string const & name, int signGrade, int executionGrade)
:_name(name),
_itsSigned(false),
_signGrade(signGrade),
_executionGrade(executionGrade)
{
	if (signGrade < Bureaucrat::MaxGrade || executionGrade < Bureaucrat::MaxGrade)
	{
		throw Form::GradeTooHighException();
	}
	if (signGrade > Bureaucrat::MinGrade || executionGrade > Bureaucrat::MinGrade)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << this << " 'Form' "
	<< "Constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}
Form::Form(Form const & src)
:_name(src._name),
_itsSigned(src._itsSigned),
_signGrade(src._signGrade),
_executionGrade(src._executionGrade)
{
	std::cout << this << " 'Form' "
	<< "Copy constructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< std::endl;
}

Form::~Form(void)
{
	std::cout << this << " 'Form' "
	<< "Destructor called. "
	<< "Name: " << _name << ". "
	<< "Sign grade: " << _signGrade << ". "
	<< "Execution grade: " << _executionGrade << ". "
	<< "Signed: " << _itsSigned << ". "
	<< std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	_itsSigned = rhs._itsSigned;
	return *this;
}

// Getters
std::string const & Form::getName(void) const
{
	return _name;
}

int Form::getSignGrade(void) const
{
	return _signGrade;
}

int Form::getExecutionGrade(void) const
{
	return _executionGrade;
}

bool Form::getItsSigned(void) const
{
	return _itsSigned;
}

// Members
void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw Form::GradeTooLowException();
	}
	_itsSigned = true;
}

// Insertion

std::ostream & operator<<(std::ostream & out, Form const & form)
{
	std::cout << "Name: " << form.getName() << ". "
	<< "Sign grade: " << form.getSignGrade() << ". "
	<< "Execution grade: " << form.getExecutionGrade() << ". ";
	if (form.getItsSigned())
	{
		std::cout << "Signed";
	}
	else 
	{
		std::cout << "Not signed";
	}
	return out;
}
