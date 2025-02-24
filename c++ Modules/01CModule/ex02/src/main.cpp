#include <iostream>
#include <string>

int main(void)
{
	std::string msj = "HI THIS IS BRAIN";
	std::string & stringREF = msj;
	std::string *stringPTR = &msj;

	std::cout << "String's address: " << &msj << std::endl;
	std::cout << "Address held by pointer: " << stringPTR << std::endl;
	std::cout << "Address held by reference: " << &stringREF << std::endl;

	std::cout << "String's value: " << msj << std::endl;
	std::cout << "Pointer's pointed value: " << *stringPTR << std::endl;
	std::cout << "Reference's pointed value: " << stringREF << std::endl;
}
