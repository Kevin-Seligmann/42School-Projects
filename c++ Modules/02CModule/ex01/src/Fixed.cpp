/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:13 by kseligma         ###   ########.fr       */
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
	:_rawBits(roundf(RawFloat * (1 << _frac)))
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
