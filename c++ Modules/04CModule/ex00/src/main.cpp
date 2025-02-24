#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void subjectTestCorrectAnimal()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void subjectTestWrongAnimal()
{
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	delete i;
}

void canonicalTestAnimal()
{
	writeTestSeparator("Canonical test");
	std::cout << "Expected: Constructor, copy, destructor, assigment works as espected" << std::endl;
	{
		// For this test, only make sure they are defined
		Animal test1;
		Animal test2(test1);
		Animal test3;

		test3 = test1;
	}
}

void soundAnimal()
{
	writeTestSeparator("Sound test");
	std::cout << "Expected: Animal sound" << std::endl;
	{
		Animal test1;
		test1.makeSound();
	}
}

void testTypeAnimal()
{
	writeTestSeparator("Type test");
	std::cout << "Expected: Animal type" << std::endl;
	{
		Animal test1;
		std::cout << test1.getType() << std::endl;
	}
}

void canonicalTestDog()
{
	writeTestSeparator("Canonical test");
	std::cout << "Expected: Constructor, copy, destructor, assigment works as espected" << std::endl;
	{
		// For this test, only make sure they are defined
		Dog test1;
		Dog test2(test1);
		Dog test3;

		test3 = test1;
	}
}
void soundDog()
{
	writeTestSeparator("Sound test");
	std::cout << "Expected: Dog sound, declared normally and as an animal" << std::endl;
	{
		Dog *test1 = new Dog();
		Animal *test2 = new Dog();
		test1->makeSound();
		test2->makeSound();
		delete test1;
		delete test2;
	}
}
void testTypeDog()
{
	writeTestSeparator("Type test");
	std::cout << "Expected: Dog type" << std::endl;
	{
		Dog test1;
		std::cout << test1.getType() << std::endl;
	}
}

void canonicalTestCat()
{
	writeTestSeparator("Canonical test");
	std::cout << "Expected: Constructor, copy, destructor, assigment works as espected" << std::endl;
	{
		// For this test, only make sure they are defined
		Cat test1;
		Cat test2(test1);
		Cat test3;

		test3 = test1;
	}
}

void soundCat()
{
	writeTestSeparator("Sound test");
	std::cout << "Expected: Cat sound, declared normally and as an animal" << std::endl;
	{
		Cat *test1 = new Cat();
		Animal *test2 = new Cat();
		test1->makeSound();
		test2->makeSound();
		delete test1;
		delete test2;
	}
}

void testTypeCat()
{
	writeTestSeparator("Type test");
	std::cout << "Expected: Cat type" << std::endl;
	{
		Cat test1;
		std::cout << test1.getType() << std::endl;
	}
}

void canonicalTestWrongAnimal()
{
	writeTestSeparator("Canonical test");
	std::cout << "Expected: Constructor, copy, destructor, assigment works as espected" << std::endl;
	{
		// For this test, only make sure they are defined
		WrongAnimal test1;
		WrongAnimal test2(test1);
		WrongAnimal test3;

		test3 = test1;
	}
}
void soundWrongAnimal()
{
	writeTestSeparator("Sound test");
	std::cout << "Expected: WrongAnimal sound" << std::endl;
	{
		WrongAnimal test1;
		test1.makeSound();
	}
}

void testTypeWrongAnimal()
{
	writeTestSeparator("Type test");
	std::cout << "Expected: WrongAnimal type" << std::endl;
	{
		WrongAnimal test1;
		std::cout << test1.getType() << std::endl;
	}
}

void canonicalTestWrongCat()
{
	writeTestSeparator("Canonical test");
	std::cout << "Expected: Constructor, copy, destructor, assigment works as espected" << std::endl;
	{
		// For this test, only make sure they are defined
		WrongCat test1;
		WrongCat test2(test1);
		WrongCat test3;

		test3 = test1;
	}
}
void soundWrongCat()
{
	writeTestSeparator("Sound test");
	std::cout << "Expected: Cat sound declared normally, animal sound declared as animal" << std::endl;
	{
		WrongCat *test1 = new WrongCat();
		WrongAnimal *test2 = new WrongCat();
		test1->makeSound();
		test2->makeSound();
		delete test1;
		delete test2;
	}
}

void testTypeWrongCat()
{
	writeTestSeparator("Type test");
	std::cout << "Expected: WrongCat type" << std::endl;
	{
		WrongCat test1;
		std::cout << test1.getType() << std::endl;
	}
}

int main (void)
{
	writeTestSeparator("Subject tests");

	subjectTestCorrectAnimal();
	subjectTestWrongAnimal();

	writeTestSeparator("Animal tests");
	canonicalTestAnimal();
	soundAnimal();
	testTypeAnimal();

	writeTestSeparator("Dog  tests");
	canonicalTestDog();
	soundDog();
	testTypeDog();

	writeTestSeparator("Cat tests");
	canonicalTestCat();
	soundCat();
	testTypeCat();

	writeTestSeparator("Wrong animal tests ");
	canonicalTestWrongAnimal();
	soundWrongAnimal();
	testTypeWrongAnimal();

	writeTestSeparator("Wrong cat tests");
	canonicalTestWrongCat();
	soundWrongCat();
	testTypeWrongCat();

	return 0;
}
