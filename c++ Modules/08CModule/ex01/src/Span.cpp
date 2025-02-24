#include "Span.hpp"

Span::Span():N(0){}

Span::Span(unsigned int size):N(size){}

Span::Span(Span const & src):N(src.N)
{
	_v = src._v;
}

Span::~Span(){}

unsigned int Span::getSize(void) const
{
	return N;
}

std::vector<int> const & Span::getVector(void) const
{
	return _v;
}

Span & Span::operator=(Span const & rhs)
{
	N = rhs.N;
	_v = rhs._v;
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() == N)
	{
		throw OutOfSpace();
	}
	_v.push_back(n);
}

#include <iostream>
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t size = std::distance(begin, end);
	if (_v.size() + size > N)
	{
		throw OutOfSpace();
	}
	_v.insert(_v.end(), begin, end);
}

unsigned int Span::shortestSpan(void)
{
	int	num;

	if (_v.size() < 2)
	{
		throw SpanTooShort();
	}
	std::sort(_v.begin(), _v.end());
	num = _v.at(1) - _v.at(0);
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end() - 1; it ++)
	{
		num = std::min(num, std::abs(*(it + 1) - *it));
	}
	return num;
}

unsigned int Span::longestSpan(void)
{
	if (_v.size() < 2)
	{
		throw SpanTooShort();
	}
	return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}

