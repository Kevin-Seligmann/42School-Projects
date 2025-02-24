/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:23 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:24 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors, destructors, copy, assignment
Fixed::Fixed(void)
	:_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int RawInt)
	:_rawBits(RawInt << _frac)
{
	std::cout << "Constructor called with integer " << RawInt << std::endl;
}

Fixed::Fixed(const float RawFloat)
	:_rawBits(round(RawFloat * (1 << _frac)))
{
	std::cout << "Constructor called with float " << RawFloat << std::endl;
}

Fixed::Fixed(Fixed const & other)
	:_rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	_rawBits = rhs._rawBits;
	std::cout << "Assignment operator called raw bits: " << _rawBits << std::endl;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
	
// Getter/setter
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int RawBits)
{
	std::cout << "setRawBits called" << std::endl;
	_rawBits = RawBits;
}

// Other members
int Fixed::toInt(void) const
{
	return _rawBits >> _frac;
}

float Fixed::toFloat(void) const
{
	return ((float) _rawBits) / (1 << _frac);
}

// Insertion overload
std::ostream& operator<<(std::ostream& os, Fixed const & num)
{
	os << num.toFloat();
	return os;
}

// Logical operators
bool Fixed::operator<(Fixed const & rhs) const
{
	return _rawBits < rhs._rawBits;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	return _rawBits > rhs._rawBits;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return _rawBits <= rhs._rawBits;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return _rawBits >= rhs._rawBits;
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return _rawBits == rhs._rawBits;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return _rawBits != rhs._rawBits;
}

// Binary operators
Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed aux;

	aux._rawBits = _rawBits + rhs._rawBits;
	return aux;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed aux;

	aux._rawBits = _rawBits - rhs._rawBits;
	return aux;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed aux;

	aux._rawBits = ((long long) _rawBits * (long long) rhs._rawBits) >> _frac;
	return aux;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed aux;

	aux._rawBits = (((long long) _rawBits << _frac) / (long long)  rhs._rawBits);
	return aux;
}

// Unary operators
Fixed Fixed::operator++(int)
{
	Fixed aux(*this);

	_rawBits ++;
	return aux;
}

Fixed & Fixed::operator++(void)
{
	_rawBits ++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);

	_rawBits --;
	return aux;
}

Fixed & Fixed::operator--(void)
{
	_rawBits --;
	return *this;
}

// Min and max
Fixed & Fixed::min(Fixed & lhs, Fixed & rhs)
{
	return lhs > rhs ? rhs : lhs;
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs)
{
	return lhs < rhs ? rhs : lhs;
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	return lhs > rhs ? rhs : lhs;
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	return lhs < rhs ? rhs : lhs;
}
