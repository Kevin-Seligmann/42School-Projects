#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(std::string const & name, int signGrade, int executionGrade);
	AForm(AForm const & src);
	virtual ~AForm(void);

	AForm & operator=(AForm const &);

	std::string const & getName(void) const;
	int getSignGrade(void) const;
	int getExecutionGrade(void) const;
	bool getItsSigned(void) const;

	void beSigned(Bureaucrat const &);
	virtual void execute(Bureaucrat const & executor) const;
	virtual void concreteExecution(void) const = 0;
	
	class GradeTooHighException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Grade too low");
		}
	};

	class FormNotSignedExpcetion : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Form not signed");
		}
	};

private:
	const std::string _name;
	bool _itsSigned;
	const int	_signGrade;
	const int	_executionGrade;

	AForm(void);
};

std::ostream & operator<<(std::ostream &, AForm const &);

#endif
