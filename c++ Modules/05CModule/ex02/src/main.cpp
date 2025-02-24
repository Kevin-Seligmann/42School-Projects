#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void presidentialCanonTests()
{
	writeTestSeparator("Presidential canon");

	{
		std::cout << "Expected: canon well defined" << std::endl;
		PresidentialPardonForm test1("Target");
		PresidentialPardonForm test2(test1);
		PresidentialPardonForm test3;
		test3 = test1;

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
	}
}

void robotomyCanonTests()
{
	writeTestSeparator("Robotomy canon");
	{
		std::cout << "Expected: canon well defined" << std::endl;
		RobotomyRequestForm test1("Target");
		RobotomyRequestForm test2(test1);
		RobotomyRequestForm test3;
		test3 = test1;

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
	}
}

void shrubberyCanonTests()
{
	writeTestSeparator("shrubbery canon");
	{
		std::cout << "Expected: canon well defined" << std::endl;
		ShrubberyCreationForm test1("Target");
		ShrubberyCreationForm test2(test1);
		ShrubberyCreationForm test3;
		test3 = test1;

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
	}
}

void wrongSignTest()
{
	writeTestSeparator("Wrong signing forms");
	{
		std::cout << "Expected: Cant sign forms one grade lower than necessary" << std::endl;
		Bureaucrat bur1("President",26);
		Bureaucrat bur2("Robot", 73);
		Bureaucrat bur3("Shrubbery", 146);
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;
		bur1.signForm(form1);
		bur2.signForm(form2);
		bur3.signForm(form3);
	}
}

void wrongExecutionTest()
{
	writeTestSeparator("Wrong execution test");
	{
		std::cout << "Expected: Bureaucrats can't execute these forms" << std::endl;
		Bureaucrat king("King", 1);
		PresidentialPardonForm form1;
		RobotomyRequestForm form2;
		ShrubberyCreationForm form3;
		king.signForm(form1);
		king.signForm(form2);
		king.signForm(form3);

		Bureaucrat bur1("President", 6);
		Bureaucrat bur2("Robot", 46);
		Bureaucrat bur3("Shrubbery", 138);

		bur1.executeForm(form1);
		bur2.executeForm(form2);
		bur3.executeForm(form3);
	}
}

void correctExecutionTest()
{
	writeTestSeparator("Correct execution test");
	{
		PresidentialPardonForm form1("President target");
		RobotomyRequestForm form2("Robotomy target");
		ShrubberyCreationForm form3("Shrubbery target");
		std::cout << "Expected: Forms signed without error" << std::endl;
		{	
			Bureaucrat bur1("President",25);
			Bureaucrat bur2("Robot", 72);
			Bureaucrat bur3("Shrubbery", 145);
			bur1.signForm(form1);
			bur2.signForm(form2);
			bur3.signForm(form3);
		}
		std::cout << "Expected: Forms executed" << std::endl;
		{
			Bureaucrat bur1("President",5);
			Bureaucrat bur2("Robot", 45);
			Bureaucrat bur3("Shrubbery", 137);
			bur1.executeForm(form1);
			bur2.executeForm(form2);
			bur3.executeForm(form3);
		}
	}
}

int main(void)
{
	srand(time(0));

	presidentialCanonTests();
	robotomyCanonTests();
	shrubberyCanonTests();

	wrongSignTest();
	wrongExecutionTest();
	correctExecutionTest();
}
