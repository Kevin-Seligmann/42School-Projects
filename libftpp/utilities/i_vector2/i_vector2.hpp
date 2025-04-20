#pragma once

#include <cstdlib>
#include <cmath>

template<typename T>
struct IVector2
{
	T x;
	T y;

	IVector2();
	IVector2(const T & x, const T & y);
	IVector2(const IVector2 & rhs);
	IVector2(IVector2 && rhs);
	~IVector2();

	float length() const;
	float dot(const IVector2 & rhs) const;
	float cross(const IVector2& rhs) const;
	IVector2 normalize() const;

	IVector2 & operator=(IVector2 && rhs);
	IVector2 & operator=(const IVector2 & rhs);

	bool operator==(const IVector2 & rhs) const;
	bool operator!=(const IVector2 & rhs) const;
	IVector2 operator/(const IVector2 & rhs) const;
	IVector2 operator*(const IVector2 & rhs) const;
	IVector2 operator-(const IVector2 & rhs) const;
	IVector2 operator+(const IVector2 & rhs) const;
	IVector2 & operator++();
	IVector2 & operator--();
	IVector2 operator++(int);
	IVector2 operator--(int);
};

template<typename T>
IVector2<T>::IVector2():x{},y{}{}

template<typename T>
IVector2<T>::~IVector2(){}

template<typename T>
IVector2<T>::IVector2(const T & x, const T & y):x{x},y{y}{}

template<typename T>
IVector2<T>::IVector2(const IVector2 & rhs):x{rhs.x},y{rhs.y}{}

template<typename T>
IVector2<T>::IVector2(IVector2 && rhs):x{std::move(rhs.x)},y{std::move(rhs.y)}{}

template<typename T>
float IVector2<T>::length() const
{return sqrt(x * x + y * y);}

template<typename T>
float IVector2<T>::dot(const IVector2 & rhs) const
{return x * rhs.x + y * rhs.y;}

template<typename T>
float IVector2<T>::cross(const IVector2& rhs) const
{return x * rhs.y - y * rhs.x;}

template<typename T>
IVector2<T> IVector2<T>::normalize() const
{float len = length(); return IVector2(x / len, y / len);}

template<typename T>
IVector2<T> & IVector2<T>::operator=(IVector2 && rhs)
{
	x = std::move(rhs.x);
	y = std::move(rhs.y);
	return *this;
}

template<typename T>
IVector2<T> & IVector2<T>::operator=(const IVector2 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

template<typename T>
bool IVector2<T>::operator==(const IVector2 & rhs) const
{return x == rhs.x && y == rhs.y;}

template<typename T>
bool IVector2<T>::operator!=(const IVector2 & rhs) const
{return x != rhs.x || y != rhs.y;}

template<typename T>
IVector2<T> IVector2<T>::operator/(const IVector2 & rhs) const
{return IVector2(x / rhs.x, y / rhs.y);}

template<typename T>
IVector2<T> IVector2<T>::operator*(const IVector2 & rhs) const
{return IVector2(x * rhs.x, y * rhs.y);}

template<typename T>
IVector2<T> IVector2<T>::operator-(const IVector2 & rhs) const
{return IVector2(x - rhs.x, y - rhs.y);}

template<typename T>
IVector2<T> IVector2<T>::operator+(const IVector2 & rhs) const
{return IVector2(x + rhs.x, y + rhs.y);}

template<typename T>
IVector2<T> & IVector2<T>::operator++()
{
	x ++;
	y ++;
	return *this;
}

template<typename T>
IVector2<T> & IVector2<T>::operator--()
{
	x --;
	y --;
	return *this;
}

template<typename T>
IVector2<T> IVector2<T>::operator++(int)
{
	auto v = IVector2(x, y);
	x++;
	y++;
	return v;
}

template<typename T>
IVector2<T> IVector2<T>::operator--(int)
{
	auto v = IVector2(x, y);
	x--;
	y--;
	return v;
}
