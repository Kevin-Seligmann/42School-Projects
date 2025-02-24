#include "BitcoinExchange.hpp"

void BitcoinExchange::displayExchange(std::string const & source, std::string const & filename)
{
	BitcoinExchange B;
	std::ifstream	fileStream;
	std::ifstream	sourceStream;

	sourceStream.open(source.c_str());
	if (sourceStream.fail())
	{
		std::cerr << "Error opening source file" << std::endl;
		return ;
	}
	fileStream.open(filename.c_str());
	if (fileStream.fail())
	{
		std::cerr << "Error opening input file" << std::endl;
		return ;
	}

	try 
	{
		B._writeSourceToMap(sourceStream);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error on source file: " << e.what() << std::endl;
		return ;
	}

	try 
	{
		B._displayExchangeFromFile(fileStream);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error displaying exchange: " << e.what() << std::endl;
		return ;
	}

}

// Source
void BitcoinExchange::_writeSourceToMap(std::ifstream & sourceStream)
{
	std::string fileLine;
	std::string date;
	float value;
	size_t separatorPosition;

	std::getline(sourceStream, fileLine); // First Line
	if (fileLine != "date,exchange_rate")
	{
		throw InvalidFormatException();
	}
	while (std::getline(sourceStream, fileLine))
	{
		separatorPosition = fileLine.find(_SeparatorSource);
		if(separatorPosition == std::string::npos || separatorPosition < _DateLength - 1)
		{
			throw InvalidFormatException();
		}
		_dateFromStr(fileLine, date, separatorPosition);
		_valueFromStr(fileLine, value, separatorPosition);
		if (_sourceValues.find(date) != _sourceValues.end())
		{
			throw RepeatedDateException();
		}
		_sourceValues[date] = value;
	}
	if (!sourceStream.eof())
	{
		throw ReadingErrorException();
	}
}

void BitcoinExchange::_dateFromStr(std::string const & sourceLine, std::string & date, size_t separatorPosition)
{
	std::string::const_iterator it;
	int year;
	int month;
	int day;

	separatorPosition --;
	while (sourceLine.at(separatorPosition) == ' ' || sourceLine.at(separatorPosition) == '\t')
	{
		separatorPosition --;
	}
	if (separatorPosition < _DateLength - 1)
	{
		throw InvalidFormatException();
	}

	it = sourceLine.begin();
	year = _validYear(it, sourceLine);
	month = _validMonth(it, sourceLine);
	day = _validDay(it, sourceLine);

	_validDate(day, month, year);

	date = sourceLine.substr(0, _DateLength);
}

void BitcoinExchange::_valueFromStr(std::string const & sourceLine, float & value, size_t separatorPosition)
{
	separatorPosition ++ ;
	while (separatorPosition != sourceLine.size() && (sourceLine.at(separatorPosition) == ' ' || sourceLine.at(separatorPosition) == '\t'))
	{
		separatorPosition ++;
	}

	if (separatorPosition == sourceLine.size())
	{
		throw InvalidFormatException();
	}

	std::string valueStr = sourceLine.substr(separatorPosition, std::string::npos);
	std::string::const_iterator it = valueStr.begin();

	value = _validValue(it, valueStr);
}

// Display
void BitcoinExchange::_displayExchangeFromFile(std::ifstream & fileStream)
{
	std::string fileLine;

	std::getline(fileStream, fileLine);
	if (fileLine != "date | value")
	{
		throw InvalidFormatException();
	}
	while (std::getline(fileStream, fileLine))
	{
		_displayLine(fileLine);
	}
	if (!fileStream.eof())
	{
		throw ReadingErrorException();
	}
}

void BitcoinExchange::_displayLine(std::string const & line)
{
	std::map<std::string, float>::iterator sourceIterator;
	std::string fileDate;
	float fileValue;
	size_t separatorPosition;

	separatorPosition = line.find(_SeparatorFile);
	if(separatorPosition == std::string::npos || separatorPosition < _DateLength)
	{
		std::cerr << "Error on line '" << line << "': " << "bad input" << std::endl;
		return ;
	}
	try
	{
		_dateFromStr(line, fileDate, separatorPosition); 
		_valueFromStr(line, fileValue, separatorPosition);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error on line '" << line << "': " << e.what() << std::endl;
		return ;
	}

	if (fileValue < 0 || fileValue > 1000)
	{
		std::cerr << "Error on line '" << line << "': " << "invalid value" << std::endl;
		return ;
	}
	sourceIterator = _getSourceIterator(fileDate);

	std::cout << fileDate << " => " << fileValue << " = " << fileValue * sourceIterator->second << std::endl;
}


std::map<std::string, float>::iterator BitcoinExchange::_getSourceIterator(std::string & fileDate)
{
	std::map<std::string, float>::iterator it = _sourceValues.begin();

	while (it != _sourceValues.end() && fileDate > it->first)
	{
		it ++;
	}
	if (it != _sourceValues.begin())
	{
		it --;
	}
	return it;
}

// Validation utils
void BitcoinExchange::_validDate(int day, int month, int year)
{
	bool isLeap;

	isLeap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (year < _MinYear || year > _MaxYear || month < 1 || month > 12 || day < 1)
	{
		throw InvalidDateException();
	}
	// cant use switch for some reason
	if (month == 1 && day > 31) throw InvalidDateException();
	if (month == 2 && day > 28 + isLeap) throw InvalidDateException();
	if (month == 3 && day > 31) throw InvalidDateException();
	if (month == 4 && day > 30) throw InvalidDateException();
	if (month == 5 && day > 31) throw InvalidDateException();
	if (month == 6 && day > 30) throw InvalidDateException();
	if (month == 7 && day > 31) throw InvalidDateException();
	if (month == 8 && day > 31) throw InvalidDateException();
	if (month == 9 && day > 30) throw InvalidDateException();
	if (month == 10 && day > 31) throw InvalidDateException();
	if (month == 11 && day > 30) throw InvalidDateException();
	if (month == 12 && day > 31) throw InvalidDateException();
}

int BitcoinExchange::_validYear(std::string::const_iterator & it, std::string const & line)
{
	int	year;
	int	count;

	year = 0;
	count = 0;
	while (it != line.end() && isdigit(*it))
	{
		year = year * 10 + (*it - '0');
		count ++;
		it ++;
	}
	if (*it != _DateSeparator || count != _YearLength)
	{
		throw InvalidFormatException();
	}
	it ++;
	return year;
}

int BitcoinExchange::_validMonth(std::string::const_iterator & it, std::string const & line)
{
	int	month;
	int	count;

	month = 0;
	count = 0;
	while (it != line.end() && isdigit(*it))
	{
		month = month * 10 + (*it - '0');
		count ++;
		it ++;
	}
	if (*it != _DateSeparator || count != _MonthLength)
	{
		throw InvalidFormatException();
	}
	it ++;
	return month;
}

int BitcoinExchange::_validDay(std::string::const_iterator & it, std::string const & line)
{
	int	day;
	int	count;

	day = 0;
	count = 0;
	while (it != line.end() && isdigit(*it))
	{
		day = day * 10 + (*it - '0');
		count ++;
		it ++;
	}
	if (count != _DayLength)
	{
		throw InvalidFormatException();
	}
	return day;
}

float BitcoinExchange::_validValue(std::string::const_iterator & it, std::string const & line)
{
	bool point;

	point = false;
	while (it != line.end())
	{
		if (*it == '.')
		{
			if (point == true)
			{
				throw InvalidValueException();
			}
			else
			{
				point = true;
			}
		}
		else if (!isdigit(*it ))
		{
			throw InvalidValueException();
		}
		it ++;
	}
	std::stringstream stream(line.substr(0, std::string::npos));
	float value;
	stream >> value;
	return value;
}

// Canonical
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){(void) src;}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	_sourceValues = rhs._sourceValues;
	return *this;
}
