#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <math.h>
#include <sstream>
#include <iomanip>

class ScalarConverter 
{
public:
	static void convert(std::string & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter(void);
	ScalarConverter & operator=(ScalarConverter const & rhs);
};

#endif
