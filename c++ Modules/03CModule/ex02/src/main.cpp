#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void testAttributes()
{
	std::cout << std::endl << "Attributes test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 100 Health points, 100 energy points, 30 attack points" << std::endl;
		FragTrap test("Test");
		test.printStats();
	}
};

void testHighFive()
{
	std::cout << std::endl << "HighFive test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: FragTrap should print a high five" << std::endl;
		FragTrap test("Test");
		test.highFivesGuys();
	}
}

void testAttack()
{
	std::cout << std::endl << "Attack test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: FragTrap should print ClapTrap's attack message" << std::endl;
		FragTrap test("Test");
		test.attack("Target");
		test.printStats();
	}
}

void testCanonical()
{
	std::cout << std::endl << "Canonical test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Copy, assignment, destructor and constructor work correctly" << std::endl;
		FragTrap test1("testName");
		test1.beRepaired(1);
		FragTrap test2(test1);
		test2.printStats();
		FragTrap test3("OtherName");
		test3 = test1;
		test3.printStats();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		FragTrap test;
		test.printStats();
	}
}

int main (void)
{
	testAttributes();
	testHighFive();
	testAttack();
	testCanonical();
	return 0;
}
