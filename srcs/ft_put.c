/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 12:55:44 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/21 13:02:08 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_put.h"

void	ft_putchar(char c, int filedes)
{
	write(filedes, &c, 1);
}

void	ft_putstr(char *str, int filedes)
{
	if (*str)
	{
		ft_putchar(*str, filedes);
		ft_putstr(str + 1, filedes);
	}
}

void	ft_putnbr(int nb, int filedes)
{
	if (nb > 0)
	{
		if (nb / 10 >= 1)
			ft_putnbr(nb / 10, filedes);
		ft_putchar(nb % 10 + '0', filedes);
	}
	else if (nb < 0)
	{
		ft_putchar('-', filedes);
		ft_putnbr(-nb, filedes);
	}
	else
		ft_putchar('0', filedes);
}
