#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

void writeSeparator(void)
{
	std::cout << std::endl
	<< "----------------------------------------------------"
	<< std::endl << std::endl;
}

void testStackZombie()
{
	std::cout << "A zombie created on the stack, on a function call" << std::endl;
	randomChump("Stacky");

	writeSeparator();
	{
		std::cout << "A zombie created on the stack, inside a code block" << std::endl;
		Zombie stacky = Zombie("Stacky");
		stacky.announce();
	}
	writeSeparator();
}

void testHeapZombie()
{
	writeSeparator();
	std::cout << "A zombie created on the heap" << std::endl;
	Zombie *heapy = newZombie("Heapy");
	heapy->announce();
	std::cout << "Zombie will be deleted" << std::endl;
	delete heapy;
	writeSeparator();
}

int main(void)
{
	testHeapZombie();
	testStackZombie();
}