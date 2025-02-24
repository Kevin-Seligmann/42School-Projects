#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat  
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & rhs);

	std::string const & getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("This operation would set a grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char * what() const throw()
		{
			return ("This operation would set a grade too low");
		}
	};

private:
	static const int _MinGrade = 150;
	static const int _MaxGrade = 1;
	int			_grade;
	std::string const _name;

};

std::ostream & operator<<(std::ostream &, Bureaucrat const &);

#endif
