#include  <iostream>
#include "ClapTrap.hpp"

// Possible improvement: Input validation or display a different message for empty strings.
void testAttack()
{
	std::cout << std::endl << "Attack test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 10 attacks, and one failed for lack of energy" << std::endl;
		ClapTrap test("Test");
		for (int i = 0; i < 11; i ++)
			test.attack("Target");
	}
}

// Possible improvement: Display a different message for 0 damage. Display a different message if health is 0.
void testDamage()
{
	std::cout << std::endl << "Damage test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
	
	{
		std::cout << "Expected: one big hit lowers hp directly to 0" << std::endl;
		ClapTrap test1("Test1");
		test1.takeDamage(100);
		std::cout << "Expected: low health cant attack" << std::endl;
		test1.attack("Target");
	}
	{
		std::cout << "Expected: Many hits lowers hp slowly to 0" << std::endl;
		ClapTrap test2("Test2");
		for (int i = 0; i < 10; i++)
			test2.takeDamage(1);
	}
}

// Possible improvement: Repairs of 0 don't cost energy
void testRepair()
{
	std::cout << std::endl << "Repair test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 10 repairs, and one failed for lack of energy" << std::endl;
		ClapTrap test("Test");
		for (int i = 0; i < 11; i++)
			test.beRepaired(1);
	}
}

void testCanonical()
{
	std::cout << std::endl << "Canonical tests"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;

	{
		std::cout << "Expected: Copy, assignment, destructor and constructor work correctly" << std::endl;
		ClapTrap test1("testName");
		test1.beRepaired(1);
		ClapTrap test2(test1);
		ClapTrap test3("OtherName");
		test3 = test1;
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		ClapTrap test;
	}
}

int main (void)
{
	testAttack();
	testDamage();
	testRepair();
	testCanonical();
}
