#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <string>

class RPN
{
public:
	static void evaluate(std::string const & src);

private:
	RPN();
	RPN(RPN const & src);
	~RPN();
	RPN & operator=(RPN const & rhs);

	static void add(std::stack<int> & stack);
	static void subtract(std::stack<int> & stack);
	static void divide(std::stack<int> & stack);
	static void multiply(std::stack<int> & stack);

	class InvalidToken : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Invalid token");
		}
	};

	class DivideByZero : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("A division by 0 was attempted");
		}
	};
};

#endif
