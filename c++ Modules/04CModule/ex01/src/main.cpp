#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void subjectTest()
{
	Animal *animals[10];

	for (int i = 0; i < 10; i ++)
	{
		if (i < 5)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < 10; i ++)
	{
		delete animals[i];
	}
}

void testBrainCanonical()
{
	writeTestSeparator("Brain canonical test");

	{
		std::cout << "Expected: Canonicals are well defined." << std::endl;
		Brain test1;
		for (int i = 0; i < 100; i ++)
			test1.setIdea("Idea", i);
		Brain test2(test1);
		Brain test3;

		test3 = test1;
		std::cout << test1.getIdea(50) << " " << test2.getIdea(50) << " " << test3.getIdea(50) << std::endl;
	}
}

void testBrainGetSet()
{
	writeTestSeparator("Get and set test");

	{
		std::cout << "Expected: Get and set work correctly" << std::endl;
		Brain test1;
		std::cout << "Setting..." << std::endl;
		for (int i = 0; i < 101; i ++)
			test1.setIdea("Idea", i);
		std::cout << "Getting..." << std::endl;
		for (int i = 0; i < 101; i ++)
			std::cout << test1.getIdea(i) << std::endl;
	}
}

void testCatCanonical()
{
	writeTestSeparator("Cat canonical");

	{
		std::cout << "Expected: Canonicals are defined and work properly. Deep copies, no segfault or leaks." << std::endl;
		Brain brain;
		for (int i = 0; i < 100; i ++)
			brain.setIdea("Idea", i);
		Cat test1;
		test1.setBrain(brain);
		Cat test2(test1);
		Cat test3;

		test3 = test2;
		test1.speakYourMind(50);
		test2.speakYourMind(50);
		test3.speakYourMind(50);
	}
}
void testDogCanonical()
{
	writeTestSeparator("Dog canonical");

	{
		std::cout << "Expected: Canonicals are defined and work properly. Deep copies, no segfault or leaks." << std::endl;
		Brain brain;
		for (int i = 0; i < 100; i ++)
			brain.setIdea("Idea", i);
		Dog test1;
		test1.setBrain(brain);
		Dog test2(test1);
		Dog test3;

		test3 = test2;
		test1.speakYourMind(50);
		test2.speakYourMind(50);
		test3.speakYourMind(50);
	}
}

int main (void)
{
	writeTestSeparator("Subject test");
	subjectTest();

	writeTestSeparator("Brain tests");
	testBrainGetSet();
	testBrainCanonical();

	writeTestSeparator("Cat and god tests");
	testCatCanonical();
	testDogCanonical();
	
	return 0;
}
