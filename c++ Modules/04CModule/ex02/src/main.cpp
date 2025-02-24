#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
	std::cout << "Uncomment code for testing, animal should be not instantiable" << std::endl;
//	AAnimal test;
	AAnimal *test1 = new Cat();
	Cat test2;

	test1->makeSound();
	test2.makeSound();

	delete test1;
}
