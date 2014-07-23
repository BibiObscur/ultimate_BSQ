/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 22:19:26 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/23 22:42:29 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq_def.h"
#include "ft_str.h"

#define BUFF_SIZE 8192

int		get_linesize(char *buff)
{
	int i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (i);
	return (0);
}

int		go(char *buff, int **line, int *i, t_map *map)
{
	if (!(*line))
	{
		if ((map->column_nb = get_linesize(buff)) == 0)
			return (0);
		*line = malloc(sizeof(int) * map->column_nb);
	}
}

t_square	*get_square(int file, t_map *map)
{
	int			*line;
	int			i;
	int			ret;
	char		buff[BUFF_SIZE];

	while ((ret = read(file, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[ret] = 0;
		if (!go(buff, &line, &i, map))
			return (NULL);
	}
	if (i != map->line_nb || map->column_nb == 0)
		return (NULL);
	return (map->square);
}
