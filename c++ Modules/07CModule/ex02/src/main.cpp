#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

#define MAX_VAL 750
int subjectTest()
{
Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	return 0;
}

void printarr(Array<int> &test)
{
	unsigned int size = test.size();
	std::cout << "{";
	for (unsigned int i = 0; i < size ;i++)
	{
		std::cout << test[i];
		if (i < size - 1)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

void ownTests()
{
	{
		std::cout << "Expected: Canonical well defined" << std::endl;
		Array<int> test1(5);
		// Should print init error
		// printarr(test, size);
		for (int i = 0; i < 5; i ++)
			test1[i] = i;
		Array<int> test2(test1);
		Array<int> test3;

		std::cout << "Expected: Out of bounds catch" << std::endl;
		try
		{
			test3[0];
		}
		catch (Array<int>::OutOfBoundsException & e)
		{
			std::cout << "Correct catch ! - " << e.what() << std::endl;
		}

		std::cout << "Expected: all printed arrays are equal" << std::endl;
		test3 = test1;
		printarr(test1);
		printarr(test2);
		printarr(test3);

		std::cout << "Expected: Out of bounds catch" << std::endl;
		try
		{
			test3[5];
		}
		catch (Array<int>::OutOfBoundsException & e)
		{
			std::cout << "Correct catch ! - " << e.what() << std::endl;
		}
	}
}

int main(int, char**)
{
	writeTestSeparator("Subject tests");
	if (subjectTest() == 0)
		std::cout << "Subject test passed" << std::endl;
	else
		std::cout << "Subjet test failed" << std::endl;
	writeTestSeparator("Canonical tests");
	ownTests();
}
