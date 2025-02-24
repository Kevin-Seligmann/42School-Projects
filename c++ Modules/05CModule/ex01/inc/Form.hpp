#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form(void);
	Form(std::string const & name, int signGrade, int executionGrade);
	Form(Form const & src);
	~Form(void);
		
	Form & operator=(Form const &);

	std::string const & getName(void) const;
	int getSignGrade(void) const;
	int getExecutionGrade(void) const;
	bool getItsSigned(void) const;

	void beSigned(Bureaucrat const &);
	
	class GradeTooHighException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Form: Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Form: Grade too low");
		}
	};

private:
	const std::string _name;
	bool _itsSigned;
	const int	_signGrade;
	const int	_executionGrade;
		
};

std::ostream & operator<<(std::ostream &, Form const &);

#endif
