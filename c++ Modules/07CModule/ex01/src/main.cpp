#include "iter.hpp"

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	const int arrc[5] = {6, 7, 8, 9, 10};

	iter(arr, 5, printValue);
	iter(arrc, 5, printValue);
}
