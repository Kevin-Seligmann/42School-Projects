#include <iostream>
#include <assert.h>
#include "whatever.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void subjectTests()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void minTest()
{
	std::cout << "Expected: Returns the second value on equality" << std::endl;

	int a = 1;
	int b = 1;
    const int& result = min(a, b);
	if (&b == &result)
		std::cout << "Test passed" << std::endl;
	else
		std::cout << "Test failed" << std::endl;
}

void maxTest()
{
	std::cout << "Expected: Returns the second value on equality" << std::endl;

	int a = 1;
	int b = 1;
    const int& result = max(a, b);
	if (&b == &result)
		std::cout << "Test passed" << std::endl;
	else
		std::cout << "Test failed" << std::endl;
}

int main( void )
{
	writeTestSeparator("Subejct tests");
	subjectTests();
	writeTestSeparator("min tests");
	minTest();
	writeTestSeparator("max tests");
	maxTest();
}
