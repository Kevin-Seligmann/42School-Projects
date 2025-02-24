#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <algorithm>

class Span
{
public:
	Span();
	Span(unsigned int size);
	Span(Span const & src);
	~Span();
	Span & operator=(Span const & rhs);

	unsigned int getSize(void) const;
	std::vector<int> const & getVector(void) const;

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	class OutOfSpace : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("The Span doesn't have enough space");
		}
	};

	class SpanTooShort : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("The Span is too short to find a span");
		}
	};

private:
	std::vector<int> _v;
	unsigned int N;
};

#endif
