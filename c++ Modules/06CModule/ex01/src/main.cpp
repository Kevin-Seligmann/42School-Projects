#include "data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	Data * datacpy;
	uintptr_t ptr;

	data.i = 5;
	ptr = Serializer::serialize(&data);
	datacpy = Serializer::deserialize(ptr);

	std::cout << datacpy->i << std::endl;
}
