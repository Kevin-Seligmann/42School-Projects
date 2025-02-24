#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <map>
#include <math.h>

class BitcoinExchange 
{
public:
	static void displayExchange(std::string const & source, std::string const & filename);


private:
	static const size_t _DateLength = 10; // yyyy-mm-dd
	static const size_t _YearLength = 4;
	static const size_t _MonthLength = 2;
	static const size_t _DayLength = 2;
	static const char _DateSeparator = '-';
	static const char _SeparatorSource = ',';
	static const char _SeparatorFile = '|';
	static const int _MinYear = 2000;
	static const int _MaxYear = 2030;

	std::map<std::string, float> _sourceValues;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange();
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

	void _writeSourceToMap(std::ifstream & sourceStream);
	void _displayExchangeFromFile(std::ifstream & sourceStream);
	void _parseSourceLine(std::string const & line);
	int _validYear(std::string::const_iterator & it, std::string const & line);
	int _validMonth(std::string::const_iterator & it, std::string const & line);
	int _validDay(std::string::const_iterator & it, std::string const & line);
	void _validSeparator(std::string::const_iterator & it, std::string const & line);
	float _validValue(std::string::const_iterator & it, std::string const & line);
	void _validDate(int day, int month, int year);
	void _displayLine(std::string const & line);
	std::map<std::string, float>::iterator _getSourceIterator(std::string & fileDate);
	void _dateFromStr(std::string const & sourceLine, std::string & date, size_t separatorPosition);
	void _valueFromStr(std::string const & sourceLine, float & value, size_t separatorPosition);

	class InvalidFormatException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Invalid format");
		}
	};

	class ReadingErrorException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Reading error");
		}
	};

	class InvalidDateException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Invalid date");
		}
	};

	class InvalidValueException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Invalid value");
		}
	};

	class RepeatedDateException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Repeated date");
		}
	};

};

#endif
