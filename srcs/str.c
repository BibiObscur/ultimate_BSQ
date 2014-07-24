/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontaro <fmontaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 18:48:59 by fmontaro          #+#    #+#             */
/*   Updated: 2014/07/22 18:30:07 by fmontaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

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

/*
 *int				ft_strlen(char *s)
 *{
 *    int			i;
 *
 *    i = 0;
 *    while (s[i])
 *        ++i;
 *    return (i);
 *}
 */

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
