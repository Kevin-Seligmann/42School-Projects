#include <iostream>
#include <vector>
#include "Span.hpp"

void writeTestSeparator(std::string testName)
{
	std::cout << std::endl << testName
	<< " ----------------------------------------------------"
	<< std::endl << std::endl;	
}

void printVector(std::vector<int> const & a)
{
	std::cout << "vector: {";
	for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != a.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl;
}
void ownTests()
{
	std::cout << "Own tests" << std::endl << std::endl;

	std::cout << "Canonical methods" << std::endl;
	Span a(7);
	for (int i = 0; i < 5; i ++)
	{
		a.addNumber(i);
	}
	Span b(a);
	b.addNumber(5);
	Span c;
	c = b;
	c.addNumber(6);
	printVector(a.getVector()); // 0 to 4
	printVector(b.getVector()); // 0 to 5
	printVector(c.getVector()); // 0 to 6

	std::cout << std::endl <<"Block addition" << std::endl;
	Span d(10);
	for (int i = 0; i < 5; i ++)
	{
		d.addNumber(i); // 5/10
	}
	std::vector<int> v;
	for (int i = 2; i < 5; i ++)
	{
		v.push_back(i*i*i);
	}
	d.addNumber(v.begin(), v.end()); // 8/10
	printVector(d.getVector());

	std::cout << std::endl << "Space limits" << std::endl;
	try
	{
		d.addNumber(v.begin(), v.end()); // 11/10
	}
	catch (Span::OutOfSpace & ex)
	{
		std::cout << "Caught bad block: " << ex.what() << std::endl;
	}

	d.addNumber(100); // 9/10
	d.addNumber(101); // 10/10
	printVector(d.getVector());
	try
	{
		d.addNumber(1); // 11/10
	}
	catch (Span::OutOfSpace & ex)
	{
		std::cout << "Caught bad single: " << ex.what() << std::endl;
	}

	std::cout << std::endl << "Bad method calls" << std::endl;
	Span e(1);
	try
	{
		e.shortestSpan(); // 11/10
	}
	catch (Span::SpanTooShort & ex)
	{
		std::cout << "Caught bad span call (Short): " << ex.what() << std::endl;
	}

	e.addNumber(1);
	try
	{
		e.longestSpan(); // 11/10
	}
	catch (Span::SpanTooShort & ex)
	{
		std::cout << "Caught bad span call (long): " << ex.what() << std::endl;
	}

	std::cout << std::endl << "Fill with 1000000 numbers" << std::endl;
	Span f(1000000);
	std::vector<int> vec;
	for (int j = 0; j < 1000000; j++)
	{
		vec.push_back(j);
	}
	f.addNumber(vec.begin(), vec.end());
	std::cout << "Size: " << f.getVector().size()
	<< ", Shortest span: " << f.shortestSpan() 
	<< ", Longest span: " << f.longestSpan() << std::endl;
}

void subjectTests()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void canonicalTests()
{
	{
		std::cout << "Expected: canon well defined. All prints equal." << std::endl;
		Span test1(5);
		for (int i = 0; i < 5; i++)
			test1.addNumber(i);
		Span test2(test1);
		Span test3(0);
		test3 = test1;
		printVector(test1.getVector());
		printVector(test2.getVector());
		printVector(test3.getVector());
	}
}

void addNumberTests()
{
	writeTestSeparator("Addition one by one");
	{
		std::cout << "Expected: A vector of 5 elements" << std::endl;
		Span test1(5);
		for (int i = 0; i < 5; i++)
			test1.addNumber(i);
		printVector(test1.getVector());

		std::cout << "Expected: Adding one more element throws" << std::endl;
		try
		{
			test1.addNumber(1);
		}
		catch (Span::OutOfSpace & e)
		{
			std::cout << "Caugth: " << e.what() << std::endl;
		}
	}
	writeTestSeparator("Addition with an iterator range");
	{
		std::cout << "Expected: A vector of 50 elements" << std::endl;
		Span test2(100);
		std::vector<int> v;
		for (int i = 0; i < 100; i++)
			v.push_back(i);
		test2.addNumber(v.begin(), v.end());
		printVector(test2.getVector());

		std::cout << "Expected: Adding 51 more element throws" << std::endl;
		v.push_back(4);
		try
		{
			test2.addNumber(v.begin(), v.end());
		}
		catch (Span::OutOfSpace & e)
		{
			std::cout << "Caugth: " << e.what() << std::endl;
		}
	}
}

void spanTests()
{
	{
		std::cout << "Expected: Asking for a span on a Span of range < 2 throws" << std::endl;
		Span test1(1);
		test1.addNumber(1);
		try
		{
			test1.shortestSpan();
		}
		catch(Span::SpanTooShort & e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		try
		{
			test1.longestSpan();
		}
		catch(Span::SpanTooShort & e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "Expected: Shortest span 2, largest 10" << std::endl;
		Span test1(5);
		test1.addNumber(0);
		test1.addNumber(10);
		test1.addNumber(8);
		test1.addNumber(6);
		test1.addNumber(4);
		std::cout << "Short: " << test1.shortestSpan() << ". Long: " << test1.longestSpan() << std::endl; 
	}
}

int main()
{
	writeTestSeparator("Subject tests");
	subjectTests();
	writeTestSeparator("Canonical tests");
	canonicalTests();
	writeTestSeparator("Add number tests");
	addNumberTests();
	writeTestSeparator("Span tests");
	spanTests();
	return 0;
}
