#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe merger(argv + 1);
		merger.runVectorSort();
		merger.runListSort();
		merger.printResults();

		// Just for testing
		if (!merger.checkVectorSort()){
			return 10;
		}
		if (!merger.checkListSort()){
			return 11;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
