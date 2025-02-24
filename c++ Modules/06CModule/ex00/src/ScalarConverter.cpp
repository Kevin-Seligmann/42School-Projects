#include "ScalarConverter.hpp"

namespace
{
bool isPseudoLiteral(std::string & literal)
{
	return (literal == "+inf" \
	|| literal == "-inf" \
	|| literal == "nan" \
	|| literal == "+inff" \
	|| literal == "-inff" \
	|| literal == "nanf");
}

bool isChar(std::string & literal)
{
	return (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'');
}

bool isInt(std::string & literal)
{
	std::string::iterator a = literal.begin();

	if (*a == '+' || *a == '-')
	{
		a++;
	}
	while (a != literal.end())
	{
		if (!isdigit(*a))
		{
			return false;
		}
		a ++;
	}
	return true;
}

bool isFloat(std::string & literal)
{
	std::string::iterator a = literal.begin();
	bool point = false;

	if (literal.length() < 3 || *(literal.end() - 1) != 'f' || *literal.begin() == '.')
		return false;
	if (*a == '+' || *a == '-')
		a++;
	while (a != literal.end())
	{
		if (*a == '.')
		{
			if (point == true)
				return false;
			point = true;
		}
		else if (!isdigit(*a) && a != literal.end() - 1)
			return false;
		a++ ;
	}
	return point;
}

bool isDouble(std::string & literal)
{
	bool point = false;
	std::string::iterator a = literal.begin();

	if (literal.length() < 2)
		return false;
	if (*a == '+' || *a == '-')
		a++;
	while (a != literal.end())
	{
		if (*a == '.')
		{
			if (point == true)
				return false;
			point = true;
		}
		else if (!isdigit(*a))
			return false;
		a++;
	}
	return point;
}

void printPseudoLiteral(std::string & literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
	{
		literal.erase(literal.end() - 1);
	}
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void printChar(std::string & literal)
{
	char c = literal.at(1);

	if (isprint(c))
	{
		std::cout << literal.substr(1, 1) << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << static_cast<float>(c) << std::endl;
	std::cout << static_cast<double>(c) << std::endl;
}

void printInt(std::string & literal)
{
	std::stringstream stream(literal);
	int i = 0;
	stream >> i;
	
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(i);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void printFloat(std::string & literal)
{
	std::stringstream stream(literal);
	float f = 0;
	stream >> f;

	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(f);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
	{
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "float " << f << std::endl;
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "double: " << static_cast<double>(f) << std::endl;
}

void printDouble(std::string & literal)
{
	std::stringstream stream(literal);
	double d = 0;
	stream >> d;

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(d);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
	{
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float: Impossible" << std::endl;
	}
	else
	{
		std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "float: " << static_cast<float>(d) << std::endl;
	}
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "double: " << d << std::endl;
}
}

void ScalarConverter::convert(std::string & literal)
{
	if (isPseudoLiteral(literal))
		printPseudoLiteral(literal);
	else if (isChar(literal))
		printChar(literal);
	else if (isInt(literal))
		printInt(literal);
	else if (isFloat(literal))
		printFloat(literal);
	else if (isDouble(literal))
		printDouble(literal);
	else
		std::cerr << "Invalid literal" << std::endl;
}

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(ScalarConverter const & src){(void) src;};
ScalarConverter::~ScalarConverter(void){};
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){(void) rhs; return *this;};
