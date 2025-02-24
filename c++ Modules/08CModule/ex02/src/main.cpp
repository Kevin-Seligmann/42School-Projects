#include <iostream>
#include "MutantStack.hpp"

void printMutantStank(MutantStack<int> mut)
{
	std::cout << "{";
	for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); it ++)
	{
		std::cout << *it << " ";
	}
	std::cout << "}" << std::endl;
}

int main()
{
	MutantStack<int> mut;

	std::cout << "Basic tests" << std::endl;
	printMutantStank(mut);
	mut.push(1);
	printMutantStank(mut);
	mut.pop();
	printMutantStank(mut);
	for (int i = 0; i < 10; i ++)
	{
		mut.push(i);
		printMutantStank(mut);
	}

	std::cout << "Canonical tests" << std::endl;
	MutantStack<int> mut2(mut);
	MutantStack<int> mut3;
	mut3 = mut;
	printMutantStank(mut);
	printMutantStank(mut2);
	printMutantStank(mut3);
}
