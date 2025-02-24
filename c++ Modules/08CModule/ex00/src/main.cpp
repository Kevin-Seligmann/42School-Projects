#include <vector>
#include <iostream>
#include "easyfind.hpp"


void printIt(std::vector<int> & v, std::vector<int>::iterator & it, int val)
{
	if (it != v.end())
	{
		std::cout << "Found: " << *it <<std::endl;
	}
	else
	{
		std::cout << "Not found: " << val << std::endl;
	}
}

int main(void)
{
	std::vector<int>::iterator it;
	std::vector<int> v;

	v.push_back(30);
	v.push_back(10);
	v.push_back(21);

	std::cout << "Expected: found" << std::endl;
	it = easyfind(v, 30);
	printIt(v, it, 30);
	std::cout << "Expected: found" << std::endl;
	it = easyfind(v, 10);
	printIt(v, it, 10);
	std::cout << "Expected: found" << std::endl;
	it = easyfind(v, 21);
	printIt(v, it, 21);
	std::cout << "Expected: not found" << std::endl;
	it = easyfind(v, 5);
	printIt(v, it, 5);
}
