#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat  
{

public:
	static const int MinGrade = 150;
	static const int MaxGrade = 1;

	Bureaucrat(void);
	Bureaucrat(std::string const &, int);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat(void);

	Bureaucrat & operator=(Bureaucrat const &);

	std::string const & getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form & form) const;

	class GradeTooHighException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Bureaucrat: Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Bureaucrat: Grade too low");
		}
	};
	
private:
	int					_grade;
	std::string const	_name;

};

std::ostream & operator<<(std::ostream &, Bureaucrat const &);

#endif
