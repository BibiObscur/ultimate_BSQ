/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontaro <fmontaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 18:37:28 by fmontaro          #+#    #+#             */
/*   Updated: 2014/07/24 12:12:02 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_str.h"

static int			get_line(char **line, char **str, char *zero);
static int			final_line(char **line, char *str, char *base);

static char			*rea_str(char *dst, char *buf, char **base)
{
	char			*tmp;
	int				len;

	len = ft_strlen(dst);
	tmp = malloc(len + ft_strlen(buf) + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, dst);
	ft_strcpy(tmp + len, buf);
	free(*base);
	*base = tmp;
	return (tmp);
}

int					get_nextline(int fd, char **line)
{
	char			buf[16384 + 1];
	static char		*str;
	static char		*str_base;
	char			*zero;
	int				ret;

	if (!str)
	{
		str = malloc(1);
		str_base = str;
		*str = 0;
	}
	zero = ft_strchr(str, '\n');
	while (!zero && (ret = read(fd, buf, 16384)))
	{
		if (ret < 0)
			return (ret);
		buf[ret] = 0;
		if ((str = rea_str(str, buf, &str_base)) == NULL)
			return (-1);
		zero = ft_strchr(str, '\n');
	}
	if (zero)
		return (get_line(line, &str, zero));
	return (final_line(line, str, str_base));
}

static int			get_line(char **line, char **str, char *zero)
{
	*zero = 0;
	*line = ft_strdup(*str);
	*str = zero + 1;
	return (1);
}

static int			final_line(char **line, char *str, char *base)
{
	if (*str)
	{
		*line = ft_strdup(str);
		*str = 0;
		return (1);
	}
	else
	{
		if (base)
			free(base);
		return (0);
	}
}
