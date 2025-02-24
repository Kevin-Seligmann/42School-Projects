#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ \"expression\"" << std::endl;
		return (0);
	}
	std::string str(argv[1]);

	RPN::evaluate(str);
}
