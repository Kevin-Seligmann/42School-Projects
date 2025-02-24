/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:35 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/16 15:06:10 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	validateInput(int argc, char **argv)
{
	double	aux;
	char	*end;

	if (argc != 9)
	{
		std::cout << "./bsp Ax Ay Bx By Cx Cy Zx Zy" << std::endl;
		return (-1);
	}
	for (int i = 1; i < argc; i++)
	{
		aux = strtold(argv[i], &end);
		if (*end != 0 || end == argv[i])
		{
			std::cerr << "Invalid input: " << argv[i] << std::endl;
			return (-1);
		}
		if (aux < -std::numeric_limits<float>::max() || aux > std::numeric_limits<float>::max())
		{
			std::cerr << "Invalid input: Out of bounds: " << argv[i] << std::endl;
			return (-1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	bool	isInside;

	if (validateInput(argc, argv) == -1)
		return (1);

	isInside = bsp( \
		Point(atof(argv[1]), atof(argv[2])), \
		Point(atof(argv[3]), atof(argv[4])), \
		Point(atof(argv[5]), atof(argv[6])), \
		Point(atof(argv[7]), atof(argv[8])));
	
	if (isInside)
		std::cout << "Z is inside ABC" << std::endl;
	else
		std::cout << "Z is not inside ABC" << std::endl;

	return (0);
}