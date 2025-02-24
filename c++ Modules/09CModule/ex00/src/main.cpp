#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong usage: ./bsp file" << std::endl;
	}

	BitcoinExchange::displayExchange("data.csv", argv[1]);
}
