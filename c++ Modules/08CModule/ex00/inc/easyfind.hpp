#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T & container, int val)
{
	return find(container.begin(), container.end(), val);
}

#endif
