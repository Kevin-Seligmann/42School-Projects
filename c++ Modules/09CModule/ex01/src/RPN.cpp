#include "RPN.hpp"

void RPN::add(std::stack<int> & stack)
{
	if (stack.size() < 2)
	{
		throw InvalidToken();
	}

	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(a + b);
}

void RPN::subtract(std::stack<int> & stack)
{
	if (stack.size() < 2)
	{
		throw InvalidToken();
	}

	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b - a);
}

void RPN::divide(std::stack<int> & stack)
{
	if (stack.size() < 2)
	{
		throw InvalidToken();
	}

	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	if (a == 0)
	{
		throw DivideByZero();
	}
	stack.push(b / a);
}

void RPN::multiply(std::stack<int> & stack)
{
	if (stack.size() < 2)
	{
		throw InvalidToken();
	}

	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(a * b);
}

void RPN::evaluate(std::string const & src)
{
	std::stack<int> stack;

	for (std::string::const_iterator it = src.begin(); it != src.end(); it++)
	{
		if (isdigit(*it))
		{
			stack.push(*it - '0');
		}
		else
		{
			try
			{
				switch(*it)
				{
					case '+': RPN::add(stack); break;
					case '-': RPN::subtract(stack); break;
					case '/': RPN::divide(stack); break;
					case '*': RPN::multiply(stack); break;
					case ' ': break ;
					default: throw InvalidToken();
				}
			}
			catch (RPN::InvalidToken & e)
			{
				std::cerr << e.what() << ": near: " << *it << std::endl;
				return ;
			}
			catch (RPN::DivideByZero & e)
			{
				std::cerr << e.what() << std::endl;
				return ;
			}
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}
	
RPN::RPN(){}

RPN::RPN(RPN const & src){(void) src;}

RPN::~RPN(){}

RPN & RPN::operator=(RPN const & rhs){(void) rhs; return *this;}

