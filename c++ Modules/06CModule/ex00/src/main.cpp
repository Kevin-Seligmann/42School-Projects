#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong usage. './[Program] 'literal''" << std::endl;
		return 0;
	}
	std::string str(argv[1]);
	ScalarConverter::convert(str);
}
