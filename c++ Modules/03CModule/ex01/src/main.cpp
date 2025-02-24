#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testAttributes()
{
	std::cout << std::endl << "Attributes test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 100 Health points, 50 energy points, 20 attack points" << std::endl;
		ScavTrap test("Test");
		test.printStats();
	}
};

void testGuardGate()
{
	std::cout << std::endl << "GuardGate test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Scavtrap should print a message guarding the gate" << std::endl;
		ScavTrap test("Test");
		test.guardGate();
	}
}

// Could be virtual method in ClapTrap. But runtime polymorphism is introduced in the next module. Want to keep it simple.
void testAttack()
{
	std::cout << std::endl << "Attack test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Scavtrap should print its own attack message" << std::endl;
		ScavTrap test("Test");
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
		ScavTrap test1("testName");
		test1.beRepaired(1);
		ScavTrap test2(test1);
		test2.printStats();
		ScavTrap test3("OtherName");
		test3 = test1;
		test3.printStats();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		ScavTrap test;
		test.printStats();
	}
}

int main (void)
{
	testAttributes();
	testGuardGate();
	testAttack();
	testCanonical();
	return 0;
}
