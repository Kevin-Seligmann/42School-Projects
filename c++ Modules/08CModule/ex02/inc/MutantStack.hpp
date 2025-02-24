#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>	
{
public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack<T>();
	MutantStack<T>(MutantStack const & src);
	~MutantStack<T>(void);
	MutantStack<T> & operator=(MutantStack<T> const & rhs);

	MutantStack<T>::iterator begin();
	MutantStack<T>::iterator end();
};

template<typename T>
MutantStack<T>::MutantStack(void)
{}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const & src)
:std::stack<T>()
{
	this->c = src.c;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
	this->c = rhs.c;
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{
	return this->c.end();
};

#endif
