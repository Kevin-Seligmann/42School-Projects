#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	std::cout << "Harl is about to issue a debug statement: " << std::endl;
	harl.complain("DEBUG");
	std::cout << "Harl is about to issue an info statement: " << std::endl;
	harl.complain("INFO");
	std::cout << "Harl is about to issue a warning: " << std::endl;
	harl.complain("WARNING");
	std::cout << "Harl is about to issue an error statement: " << std::endl;
	harl.complain("ERROR");
	std::cout << "Harl is about to get confused: " << std::endl;
	harl.complain("blablabla");

	return 0;
}
