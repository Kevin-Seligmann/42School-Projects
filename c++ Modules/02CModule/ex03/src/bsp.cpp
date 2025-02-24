/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:33 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 14:43:34 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <math.h>

float getSide(Point const a, Point const b, Point const c)
{
	return ( ((b.x() - a.x()) * (c.y() - a.y())) - ((b.y() - a.y()) * (c.x() - a.x())) ).toFloat();
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	cSide;
	float	aSide;
	float	bSide;
	float	pSideA;
	float	pSideB;
	float	pSideC;

	aSide = getSide(b, c, a);
	if (aSide == 0)
		return (false);
	pSideA = getSide(b, c, point);
	if ((pSideA > 0 && aSide < 0) || (pSideA < 0 && aSide > 0) || (pSideA == 0))
		return (false);

	bSide = getSide(a, c, b);
	pSideB = getSide(a, c, point);
	if ((pSideB > 0 && bSide < 0) || (pSideB < 0 && bSide > 0) || (pSideB == 0))
		return (false);
	
	cSide = getSide(a, b, c);
	pSideC = getSide(a, b, point);
	if ((pSideC > 0 && cSide < 0) || (pSideC < 0 && cSide > 0) || (pSideC == 0))
		return (false);

	return (true);
}