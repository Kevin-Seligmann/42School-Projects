/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:10 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:11 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed(void);
	Fixed(const int rawInt);
	Fixed(const float rawFloat);
	Fixed(Fixed const & other);	
	~Fixed(void);
	Fixed & operator=(Fixed const & rhs);
	
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

