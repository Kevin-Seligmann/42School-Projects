#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <string>

template<typename T>
class Array
{
public:
	Array<T>(void);
	Array<T>(unsigned int const & n);
	Array<T>(Array<T> const & src);
	~Array<T>(void);
	Array<T> & operator=(Array<T> const & rhs);
	T & operator[](unsigned int const & ind);
	unsigned int size() const;

	class OutOfBoundsException : public std::exception 
	{
		public:
			virtual const char * what() const throw()
			{
				return ("Index out of bounds");
			}
	};

private:
	unsigned int _size;
	T * _array;
};

template<typename T>
Array<T>::Array(void)
:_size(0),
_array(new T[0])
{}

template<typename T>
Array<T>::Array(unsigned int const & n)
:_size(n),
_array(new T[n])
{}

template<typename T>
Array<T>::Array(Array<T> const & src)
:_size(src._size),
_array(new T[src._size])
{
	for (unsigned int i = 0; i < _size; i ++)
	{
		_array[i] = src._array[i];
	}
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] _array;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
	delete[] _array;
	_size = rhs._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i ++)
	{
		_array[i] = rhs._array[i];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int const & ind)
{
	if (ind >= _size)
	{
		throw Array<T>::OutOfBoundsException();
	}
	return _array[ind];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}


#endif
