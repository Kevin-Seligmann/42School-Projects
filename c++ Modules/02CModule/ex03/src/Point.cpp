/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:37 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:38 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
	:_x(0)
	,_y(0){
//	std::cout << "Point default contructor" << std::endl;
}

Point::~Point(void){
//	std::cout << "Point default destructor" << std::endl;
}

Point::Point(float const x, float const y)
	:_x(x)
	,_y(y){
//	std::cout << "Point (float, float) constructor" << std::endl;
}

Point::Point(Point const & other)
	:_x(other._x)
	,_y(other._y){
//	std::cout << "Point copy constructor" << std::endl;
}

Point & Point::operator=(Point const & rhs){
//	std::cout << "Point assignment operator" << std::endl;
//	std::cout << "Members of this class are constant, no changes have been made" << std::endl;
	(void) rhs;

	return *this;
}

Fixed const & Point::y() const{
	return this->_y;
}

Fixed const & Point::x() const{
	return this->_x;
}
