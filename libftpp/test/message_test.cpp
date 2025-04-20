#include <string>
#include <iostream>
#include "libftpp.hpp"


int main()
{
	Message msg(4);

	msg << "Hola, message";
	msg << std::endl;

	std::cout << msg.getMessage();

	std::string s;
	msg >> s;
	std::cout << s;
}
