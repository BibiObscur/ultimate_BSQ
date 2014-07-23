/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:42:17 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/23 17:03:55 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_put.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char			*ft_strcat(char *dest, char *src)
{
	char *s1;

	s1 = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	s1 = ft_strcpy(s1, dest);
	s1 = ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

int				ft_get_nb(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb += str[i] - '0';
		nb *= 10;
		i++;
	}
	return (nb / 10);
}
