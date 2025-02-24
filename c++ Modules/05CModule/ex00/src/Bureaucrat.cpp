#include "Bureaucrat.hpp"

// Canonic
Bureaucrat::Bureaucrat()
:_grade(_MinGrade),
_name("Unnamed bureaucrat")
{
	std::cout << this << " 'Bureaucrat'. "
	<< "Default Constructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
:_grade(grade),
_name(name)
{
	if (_grade < _MaxGrade)
	{
		throw GradeTooHighException();
	}
	if (_grade > _MinGrade)
	{
		throw GradeTooLowException();
	}
	std::cout << this << " 'Bureaucrat'. "
	<< "Constructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
:_grade(src._grade),
_name(src._name)
{
	std::cout << this << " 'Bureaucrat'. "
	<< "Copy constructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this << " 'Bureaucrat'. "
	<< "Destructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_grade = rhs._grade;
	return *this;
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

// Members
int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == _MaxGrade)
	{
		throw GradeTooHighException();
	}
	_grade --;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == _MinGrade)
	{
		throw GradeTooLowException();
	}
	_grade ++;
}

// Insertion
std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

