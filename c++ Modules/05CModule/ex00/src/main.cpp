#include <iostream>
#include "Bureaucrat.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void canonicalTest()
{
	writeTestSeparator("Canonical test");
	{
		std::cout << "Expected: canonical functions well defined. No exception should be thrown" << std::endl;
		Bureaucrat test1("Name", 1);
		Bureaucrat test2(test1);
		Bureaucrat test3;
		test3 = test1;

		std::cout  << test1 << std::endl;
		std::cout  << test2 << std::endl;
		std::cout  << test3 << std::endl;
	}
}

void limitTests()
{
	writeTestSeparator("Increment to limit tests");

	std::cout << "Expected: Incrementing or decrementing towards the limit should not throw" << std::endl;
	{
		Bureaucrat test1("name", 2);
		Bureaucrat test2("other name", 149);
		test1.incrementGrade();
		test2.decrementGrade();
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
	}
}

void badConstructorTest()
{
	writeTestSeparator("Bad constructor test");

	{
		std::cout << "Expected: Bad constructors throw exceptions" << std::endl;
		try
		{
			Bureaucrat test1("Name", 151);
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << "Low threw correctly: " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat test1("Name", 0);
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << "High threw correctly: " << e.what() << std::endl;
		}
	}
}

void badIncrementTest()
{
	writeTestSeparator("Bad increment test");

	{
		std::cout << "Expected: Incrementing over the limit throws" << std::endl;
		try
		{
			Bureaucrat test1("Name", 150);
			test1.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << "Low threw correctly: " << e.what() << std::endl;
		}
		try
		{
			Bureaucrat test1("Name", 1);
			test1.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << "High threw correctly: " << e.what() << std::endl;
		}
	}
}
int main(void)
{
	canonicalTest();
	limitTests();
	badConstructorTest();
	badIncrementTest();
}
