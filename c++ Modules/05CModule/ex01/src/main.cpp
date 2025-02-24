#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void testCanonicalForm()
{
	writeTestSeparator("Form canonical");

	{
		std::cout << "Expected: Canonical well defined" << std::endl;
		Bureaucrat bur("name", 1);
		Form test1("Test", 50, 50);
		bur.signForm(test1);
		Form test2(test1);
		Form test3;
		test3=test1;

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
	}
}

void testGoodSignForm()
{
	writeTestSeparator("Signing forms in good way");
	{
		std::cout << "Expected: Forms get signed" << std::endl;
		Bureaucrat bur("Name", 50);
		Form test1("Test 1", 50, 1);
		Form test2("Test 2", 50, 1);
		test1.beSigned(bur);
		bur.signForm(test2);
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
	}
}

void testBadSignForm()
{
	writeTestSeparator("Singing forms in bad way");
	{
		std::cout << "Expected: Bad bureaucrat sign show message. Bad form sign throws." << std::endl;
		Bureaucrat bur("Name", 51);
		Form test1("Test 1", 50, 1);
		bur.signForm(test1);
		try
		{
			test1.beSigned(bur);
		}
		catch (Form::GradeTooLowException & e)
		{
			std::cerr << "Grade too low catch " << e.what() << std::endl;
		}
	}
}

void testBadConstruction()
{
	writeTestSeparator("Bad construction");

	{
		std::cout << "Expected: Bad construction throws" << std::endl;
		try
		{
			Form test1("Test 1", 0, 50);
		}
		catch (Form::GradeTooHighException & e)
		{
			std::cout << "Too high catch " << e.what() << std::endl;
		}
		try
		{
			Form test2("Test 2", 151, 50);
		}
		catch(Form::GradeTooLowException & e)
		{
			std::cout << "Too low catch " << e.what() << std::endl;
		}
			try
		{
			Form test1("Test 1", 50, 0);
		}
		catch (Form::GradeTooHighException & e)
		{
			std::cout << "Too high catch " << e.what() << std::endl;
		}
		try
		{
			Form test2("Test 2", 50, 151);
		}
		catch(Form::GradeTooLowException & e)
		{
			std::cout << "Too low catch " << e.what() << std::endl;
		}
	}
}

void testGetters()
{
	writeTestSeparator("Test getters");
	
	{
		std::cout << "Expected: Getters work succesfully" << std::endl;
		Form test("Form name", 50, 49);
		std::cout <<test.getName()<<" "<<test.getItsSigned()<<" "<<test.getSignGrade()<<" "<<test.getExecutionGrade() << std::endl;
	}
}

int main(void)
{
	testCanonicalForm();
	testGoodSignForm();
	testBadSignForm();
	testBadConstruction();
	testGetters();
}
