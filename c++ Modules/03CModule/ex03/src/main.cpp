#include <iostream>
#include "DiamondTrap.hpp"

void testAttackTrap()
{
	std::cout << std::endl << "Attack test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 10 attacks, and one failed for lack of energy" << std::endl;
		ClapTrap test("Test");
		for (int i = 0; i < 11; i ++)
		{
			test.attack("Target");
			test.printStats();
		}
	}
}

void testDamageTrap()
{
	std::cout << std::endl << "Damage test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
	
	{
		std::cout << "Expected: one big hit lowers hp directly to 0" << std::endl;
		ClapTrap test1("Test1");
		test1.takeDamage(100);
		test1.printStats();
	}
	{
		std::cout << "Expected: Many hits lowers hp slowly to 0" << std::endl;
		ClapTrap test2("Test2");
		for (int i = 0; i < 10; i++)
		{
			test2.takeDamage(1);
			test2.printStats();
		}
	}
}

void testRepairTrap()
{
	std::cout << std::endl << "Repair test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: 10 repairs, and one failed for lack of energy" << std::endl;
		ClapTrap test("Test");
		for (int i = 0; i < 11; i++)
		{
			test.beRepaired(1);
			test.printStats();
		}
	}
}

void testCanonicalTrap()
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
		test1.printStats();
		test2.printStats();
		test3.printStats();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		ClapTrap test;
		test.printStats();
	}
}

void clapTrapTests()
{
	std::cout << std::endl << "ClapTrap tests"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;
	testAttackTrap();
	testDamageTrap();
	testRepairTrap();
	testCanonicalTrap();
}

void testAttributesScav()
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

void testAttackScav()
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

void testCanonicalScav()
{
	std::cout << std::endl << "Canonical test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Copy, assignment, destructor and constructor work correctly" << std::endl;
		ScavTrap test1("testName");
		test1.beRepaired(1);
		ScavTrap test2(test1);
		ScavTrap test3("OtherName");
		test3 = test1;
		test1.printStats();
		test2.printStats();
		test3.printStats();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		ScavTrap test;
		test.printStats();
	}
}

void scavTrapTests()
{
	std::cout << std::endl << "ScavTrap tests"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;

	testAttributesScav();
	testGuardGate();
	testAttackScav();
	testCanonicalScav();
}

void testAttributesFrag()
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

void testAttackFrag()
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

void testCanonicalFrag()
{
	std::cout << std::endl << "Canonical test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Copy, assignment, destructor and constructor work correctly" << std::endl;
		FragTrap test1("testName");
		test1.beRepaired(1);
		FragTrap test2(test1);
		FragTrap test3("OtherName");
		test3 = test1;
		test1.printStats();
		test2.printStats();
		test3.printStats();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		FragTrap test;
		test.printStats();
	}
}

void fragTrapTests()
{
	std::cout << std::endl << "FragTrap tests"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;

	testAttributesFrag();
	testHighFive();
	testAttackFrag();
	testCanonicalFrag();
}

void testAttributesDiam()
{
	std::cout << std::endl << "Attributes test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Frag Health points, Scav energy points, Frag attack points." << std::endl;
		DiamondTrap test("Test");
		test.printStats();
	}
}

void testWhoAmI()
{
	std::cout << std::endl << "WnoAmI test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: DiamondTrap should print a message with diamond's name. Clap name should be different." << std::endl;
		DiamondTrap test("Test");
		test.whoAmI();
		test.printStats();
	}
}

void testAttackDiam()
{
	std::cout << std::endl << "Attack test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: DiamondTrap should print ScavTrap's attack message" << std::endl;
		DiamondTrap test("Test");
		test.attack("Target");
		test.printStats();
	}
}

void testCanonicalDiam()
{
	std::cout << std::endl << "Canonical test"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	

	{
		std::cout << "Expected: Copy, assignment, destructor and constructor work correctly" << std::endl;
		DiamondTrap test1("testName");
		test1.beRepaired(1);
		DiamondTrap test2(test1);
		
		DiamondTrap test3("OtherName");
		test3 = test1;
		test1.printStats();
		test2.printStats();
		test3.printStats();
		test1.whoAmI();
		test2.whoAmI();
		test3.whoAmI();
	}
	{
		std::cout << "Expected: Default constructor works correctly" << std::endl;
		DiamondTrap test;
		test.printStats();
	}
}

void diamondTrapTests()
{
	std::cout << std::endl << "DiamondTrap tests"
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;

	testAttributesDiam();
	testWhoAmI();
	testAttackDiam();
	testCanonicalDiam();
}

int main (void)
{
	clapTrapTests();
	scavTrapTests();
	fragTrapTests();
	diamondTrapTests();
	return 0;
}
