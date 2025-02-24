#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>
#include <iostream>

template<typename T>
void iter(T * arr, size_t size, void(*func)(T&))
{
	for (size_t i = 0; i < size; i ++)
	{
		func(arr[i]);
	}
}

template<typename T>
void iter(T const * arr, size_t size, void(*func)(T const &))
{
	for (size_t i = 0; i < size; i ++)
	{
		func(arr[i]);
	}
}

template<typename T>
void printValue(T & val)
{
	std::cout << val << std::endl;
}

template<typename T>
void printValue(T const & val)
{
	std::cout << val << std::endl;
}

#endif
