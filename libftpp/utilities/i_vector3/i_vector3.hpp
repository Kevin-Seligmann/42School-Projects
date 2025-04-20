#pragma once

#include <cstdlib>
#include <cmath>

template<typename T>
struct IVector3
{
	T x;
	T y;
	T z;

	IVector3();
	IVector3(const T & x, const T & y, const T & z);
	IVector3(const IVector3 & rhs);
	IVector3(IVector3 && rhs);
	~IVector3();

	float length() const;
	float dot(const IVector3 & rhs) const;
	IVector3<T> cross(const IVector3& rhs) const;
	IVector3 normalize() const;

	IVector3 & operator=(IVector3 && rhs);
	IVector3 & operator=(const IVector3 & rhs);

	bool operator==(const IVector3 & rhs) const;
	bool operator!=(const IVector3 & rhs) const;
	IVector3 operator/(const IVector3 & rhs) const;
	IVector3 operator*(const IVector3 & rhs) const;
	IVector3 operator-(const IVector3 & rhs) const;
	IVector3 operator+(const IVector3 & rhs) const;
	IVector3 & operator++();
	IVector3 & operator--();
	IVector3 operator++(int);
	IVector3 operator--(int);
};

template<typename T>
IVector3<T>::IVector3():x{},y{},z{}{}

template<typename T>
IVector3<T>::~IVector3(){}

template<typename T>
IVector3<T>::IVector3(const T & x, const T & y, const T & z):x{x},y{y},z{z}{}

template<typename T>
IVector3<T>::IVector3(const IVector3 & rhs):x{rhs.x},y{rhs.y},z{rhs.z}{}

template<typename T>
IVector3<T>::IVector3(IVector3 && rhs):x{std::move(rhs.x)},y{std::move(rhs.y)},z{std::move(rhs.z)}{}

template<typename T>
float IVector3<T>::length() const
{return sqrt(x * x + y * y + z * z);}

template<typename T>
float IVector3<T>::dot(const IVector3 & rhs) const
{return x * rhs.x + y * rhs.y + z * rhs.z;}

template<typename T>
IVector3<T> IVector3<T>::cross(const IVector3& rhs) const
{return IVector3
(
	y * rhs.z - z * rhs.y,
	z * rhs.x - x * rhs.z,
	x * rhs.y - y * rhs.x
);}

template<typename T>
IVector3<T> IVector3<T>::normalize() const
{float len = length(); return IVector3(x / len, y / len, z / len);}

template<typename T>
IVector3<T> & IVector3<T>::operator=(IVector3 && rhs)
{
	x = std::move(rhs.x);
	y = std::move(rhs.y);
	z = std::move(rhs.z);
	return *this;
}

template<typename T>
IVector3<T> & IVector3<T>::operator=(const IVector3 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

template<typename T>
bool IVector3<T>::operator==(const IVector3 & rhs) const
{return x == rhs.x && y == rhs.y && z == rhs.z;}

template<typename T>
bool IVector3<T>::operator!=(const IVector3 & rhs) const
{return x != rhs.x || y != rhs.y || z != rhs.z;}

template<typename T>
IVector3<T> IVector3<T>::operator/(const IVector3 & rhs) const
{return IVector3(x / rhs.x, y / rhs.y, z / rhs.z);}

template<typename T>
IVector3<T> IVector3<T>::operator*(const IVector3 & rhs) const
{return IVector3(x * rhs.x, y * rhs.y, z * rhs.z);}

template<typename T>
IVector3<T> IVector3<T>::operator-(const IVector3 & rhs) const
{return IVector3(x - rhs.x, y - rhs.y, z - rhs.z);}

template<typename T>
IVector3<T> IVector3<T>::operator+(const IVector3 & rhs) const
{return IVector3(x + rhs.x, y + rhs.y, z + rhs.z);}

template<typename T>
IVector3<T> & IVector3<T>::operator++()
{
	x ++;
	y ++;
	z ++;
	return *this;
}

template<typename T>
IVector3<T> & IVector3<T>::operator--()
{
	x --;
	y --;
	z --;
	return *this;
}

template<typename T>
IVector3<T> IVector3<T>::operator++(int)
{
	auto v = IVector3(x, y);
	x++;
	y++;
	z++;
	return v;
}

template<typename T>
IVector3<T> IVector3<T>::operator--(int)
{
	auto v = IVector3(x, y);
	x--;
	y--;
	z--;
	return v;
}
