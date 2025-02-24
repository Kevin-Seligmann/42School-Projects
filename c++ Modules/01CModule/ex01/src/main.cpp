#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

void	writeSeparator(void)
{
	std::cout << std::endl
	<< "----------------------------------------------------"
	<< std::endl << std::endl;
}

int validateInput(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "./horde QUANTITY NAME" << std::endl;
		return (-1);
	}
	if (atoi(argv[1]) <= 0)
	{
		std::cerr << "Invalid quantity" << std::endl;
		return (-1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cerr << "Invalid name" << std::endl;
		return (-1);
	}
	return (0);
}

void testZombieHorde(int N, std::string name)
{
	writeSeparator();
	std::cout << "Creating horde of zombies and naming them" << std::endl;
	Zombie *zombies = zombieHorde(N, name);
	writeSeparator();
	std::cout << "All zombies will announce themselves" << std::endl;
	for (int i = 0; i < N; i ++)
	{
		std::cout << "Zombie " << i + 1 << ". ";
		zombies[i].announce();
	}
	writeSeparator();
	std::cout << "Calling delete on the Zombie array" << std::endl;
	delete[] zombies;
}

int main(int argc, char **argv)
{
	if (validateInput(argc, argv) == -1)
		return (1);
	testZombieHorde(atoi(argv[1]), argv[2]);
}
