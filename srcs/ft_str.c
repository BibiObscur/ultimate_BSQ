/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:42:17 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 13:23:41 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_put.h"

char			*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int				ft_strlen(char *s)
{
	int			i;
	uint64_t	hack;

	i = 0;
	while (1)
	{
		hack = *((uint64_t *)(s + i));
		if (!(hack & 0xFF))
			return (i);
		if (!(hack & 0xFF00))
			return (i + 1);
		if (!(hack & 0xFF0000))
			return (i + 2);
		if (!(hack & 0xFF000000))
			return (i + 3);
		if (!(hack & 0xFF00000000))
			return (i + 4);
		if (!(hack & 0xFF0000000000))
			return (i + 5);
		if (!(hack & 0xFF000000000000))
			return (i + 6);
		if (!(hack & 0xFF00000000000000))
			return (i + 7);
		i += 8;
	}
}

char			*ft_strcpy(char *dest, char *src)
{
	char		*d;

	d = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (d);
}

char			*ft_strdup(char *str)
{
	return (ft_strcpy(malloc(ft_strlen(str) + 1), str));
}

int				ft_strequ(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return ((*s2 == 0));
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
