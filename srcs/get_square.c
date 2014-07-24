/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 22:19:26 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 16:28:58 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq_def.h"
#include "ft_str.h"

#include "ft_put.h"

int			init_tab(int **tab, int length)
{
	int i;

	if (!(*tab = malloc(sizeof(int) * length)))
		return (0);
	i = -1;
	while (++i < length)
		(*tab)[i] = 0;
	return (1);
}

int			find_square(int *tab, int *i, int size, int val)
{
	int count;

	count = 0;
	if (size > *i + val)
		size = *i + val;
	while (*i < size)
	{
		if (tab[*i] < val)
			return (0);
		count++;
		*i = *i + 1;
	}
	return (count == val);
}

void		to_square(int x, int y, int size, t_square *square)
{
	square->pos.x = x;
	square->pos.y = y;
	square->size = size;
}

int			go(int **tab, char *line, int y, t_map *map)
{
	int i;

	if (map->column_nb == -1)
		map->column_nb = ft_strlen(line);
	i = -1;
	while (line[++i])
	{
		if (line[i] != map->empty && line[i] != map->block)
			return (0);
		else
			(*tab)[i] = (line[i] == map->empty) ? (*tab)[i] + 1 : 0;
	}
	i = -1;
	while (++i < map->column_nb)
	{
		if ((*tab)[i] > map->square->size)
		{
			if (find_square((*tab), &i, map->column_nb, map->square->size + 1))
				to_square(i, y, map->square->size + 1, map->square);
		}
	}
	return (1);
}

t_square	*get_square(int file, t_map *map)
{
	int			*tab;
	char		*line;
	int			y;
	int			ret;

	y = 0;
	map->square = malloc(sizeof(t_square));
	to_square(0, 0, 0, map->square);
	line = NULL;
	while ((ret = get_nextline(file, &line)) && line)
	{
		if (ret < 0)
			return (NULL);
		if (!tab)
			if (!init_tab(&tab, ft_strlen(line)))
				return (NULL);
		if (!go(&tab, line, y, map))
			return (NULL);
		if (ft_strlen(line) != map->column_nb || ft_strlen(line) == 0)
			return (NULL);
		free(line);
		y++;
	}
	if (y != map->line_nb || map->column_nb == 0)
		return (NULL);
	free(tab);
	return (map->square);
}
