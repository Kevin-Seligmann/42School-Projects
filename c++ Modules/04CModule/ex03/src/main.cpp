#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

/*
	Program is made so the subject code doesn't cause leaks, so...
	- learnMateria has to free the materia it receives.
	- Character has to free the materia it received at destruction (It's forbidden to destroy at unequipment).
	- Equiping the same materia for two characters would cause a free error.
	- Creating a materia and equiping it would cause a free error if deleted.
	- Creating a materia and not equiping it would cause a leak if not deleted.

	The following rules should apply to all code written with these classes
	- Players should always equip materias from createMateria.
	- Never equip a materia on two characters.
	- learnMateria should always receive a materia created with new.
	- Materias in learnMateria should not be equiped.
	- Materia created with createMateria should be equiped.
*/

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void subjectTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void cureTest()
{
	writeTestSeparator("Cure canonical");
	{
		std::cout << "Expected: all defined and working as expected" << std::endl;
		Cure test1;
		Cure test2(test1);
		Cure test3;
		test3 = test1;
	
		std::cout << "Type: " << test1.getType() << std::endl;
		std::cout << "Type: " << test2.getType() << std::endl;
		std::cout << "Type: " << test3.getType() << std::endl;
	}
	{
		std::cout << "Expected: cure has correct type" << std::endl;
		AMateria *ice = new Ice();
		AMateria *test1 = new Cure();
		*test1 = *ice;

		std::cout << "Type: " << test1->getType() << std::endl;

		delete test1;
		delete ice;
	}
	writeTestSeparator("Cure methods");
	{
		std::cout << "Expected: correct clone, use, gettype" << std::endl;
		Cure test1;
		AMateria *test2 = test1.clone();
		std::cout << "Type: " << test2->getType() << std::endl;
		Character character("Bob");
		test1.use(character);
		delete test2;
	}
}

void iceTest()
{
	writeTestSeparator("Ice canonical");
	{
		std::cout << "Expected: all defined and working as expected" << std::endl;
		Ice test1;
		Ice test2(test1);
		Ice test3;
		test3 = test1;
	
		std::cout << "Type: " << test1.getType() << std::endl;
		std::cout << "Type: " << test2.getType() << std::endl;
		std::cout << "Type: " << test3.getType() << std::endl;
	}
	{
		std::cout << "Expected: ice has correct type" << std::endl;
		AMateria *cure = new Cure();
		AMateria *test1 = new Ice();
		*test1 = *cure;

		std::cout << "Type: " << test1->getType() << std::endl;

		delete test1;
		delete cure;
	}
	writeTestSeparator("Ice methods");
	{
		std::cout << "Expected: correct clone, use, gettype" << std::endl;
		Ice test1;
		AMateria *test2 = test1.clone();
		std::cout << "Type: " << test2->getType() << std::endl;
		Character character("Bob");
		test1.use(character);
		delete test2;
	}
}

void materiaSourceTest()
{
	writeTestSeparator("Canonical test");
	{
		std::cout << "Expected: No leaks, segfaults, or double frees" << std::endl;
		MateriaSource test1;
		test1.learnMateria(new Ice());
		test1.learnMateria(new Cure());
		MateriaSource test2(test1);
		MateriaSource test3;
		test3 = test1;
		AMateria *ice;
		ice = test1.createMateria("ice");
		delete ice;
		ice = test2.createMateria("ice");
		delete ice;
		ice = test3.createMateria("ice");
		delete ice;
	}
	writeTestSeparator("Method tests");
	{
		MateriaSource test1;
		
		std::cout << "Expected: Learn and create ice" << std::endl;
		test1.learnMateria(new Ice());
		AMateria *ice = test1.createMateria("ice");
	
		std::cout << "Expected: Unexisting materia type" << std::endl;
		AMateria *cure = test1.createMateria("cure");
		AMateria *nullCure = test1.createMateria("aasda");
		(void) nullCure;
	
		std::cout << "Expected: Learn and create cure" << std::endl;
		test1.learnMateria(new Cure());
		cure = test1.createMateria("cure");
	
		std::cout << "Expected: Handling of materiasource limit" << std::endl;
		test1.learnMateria(new Ice());
		test1.learnMateria(new Ice());
		test1.learnMateria(new Ice());

		std::cout << "Expected: Correct use" << std::endl;
		Character character("name");
		ice->use(character);
		cure->use(character);

		delete ice;
		delete cure;
	}
}

void characterTest()
{
	writeTestSeparator("Canonical test");
	{
		std::cout << "Expected: No leaks, segfault, our double free" << std::endl;
		Character test1("Name");
		test1.equip(new Ice);
		Character test2(test1);
		Character test3("Another name");
		test3 = test1;
		test1.use(0, test1);
		test2.use(0, test2);
		test3.use(0, test3);
	}
	writeTestSeparator("Equip, unequip, use");
	{
		Character test("Name");

		std::cout << "Expected: Equip handles wrong input" << std::endl;
		test.equip(NULL);
		std::cout << "Expected: Equips correctly, can use" << std::endl;
		for (int i = 0; i < 4; i ++)
		{
			test.equip(new Ice);
			test.use(i, test);
		}

		std::cout << "Expected: inventory overflow handled" << std::endl;
		Ice *ice = new Ice();
		test.equip(ice);
		delete ice;
		std::cout << "Expected: Unequip frees an slot, then can equip" << std::endl;
		test.unequip(1);
		test.equip(new Cure);
		std::cout << "Expected: unequip handles wrong input" << std::endl;
		test.unequip(3);
		test.unequip(4);
		test.unequip(3);
		test.unequip(-1);
		std::cout << "Expected: uses ice, then cure" << std::endl;
		test.use(0, test);
		test.use(1, test);
		std::cout << "Expected: use handles wrong input" << std::endl;
		test.use(4, test);
		test.use(3, test);
		test.use(-1, test);
	}
}

int main()
{
	writeTestSeparator("Subject test");
	subjectTest();
	writeTestSeparator("Cure test");
	cureTest();
	writeTestSeparator("Ice test");
	iceTest();
	writeTestSeparator("MateriaSource test");
	materiaSourceTest();
	writeTestSeparator("Character test");
	characterTest();

}
