/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:35:16 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 15:35:18 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCT_H

# define FUNCT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		initial_char(char num);
void	ft_putnbr(int num);
void	ftmod(int a, int b);
void	fttimes(int a, int b);
void	ftdiv(int a, int b);
void	plus(int a, int b);
void	minus(int a, int b);
void	operation(void (*f[5])(int a, int b), int a, int b, char **argv);

#endif
