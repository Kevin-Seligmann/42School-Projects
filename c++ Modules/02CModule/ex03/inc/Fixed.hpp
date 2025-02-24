/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:29 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:30 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed(void);
	Fixed(const int RawInt);
	Fixed(const float RawFloat);
	~Fixed(void);
	Fixed(Fixed const & other);

	Fixed & operator=(Fixed const & rhs);

	bool operator<(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;
	
	Fixed operator++(int);
	Fixed & operator++(void);
	Fixed operator--(int);
	Fixed & operator--(void);

	static Fixed & min(Fixed & lhs, Fixed & rhs);
	static Fixed & max(Fixed & lhs, Fixed & rhs);
	static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
	static Fixed const & max(Fixed const & lhs, Fixed const & rhs);

	int getRawBits(void) const;
	void setRawBits(int RawBits);
	float toFloat(void) const;
	int toInt(void) const;

private:
	static int const _frac = 8;
	int _rawBits;

};

std::ostream& operator<<(std::ostream& os, Fixed const & num);

#endif
