/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 22:19:26 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 10:38:28 by bperreon         ###   ########.fr       */
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

void	init_tab(int **line, int length)
{
	int i;

	i = -1;
	while (++i < length)
		(*line)[i] = 0;
}

int		go(char *buff, int **line, t_pos *pos, t_map *map)
{
	if (!(*line))
	{
		if ((map->column_nb = get_linesize(buff)) == 0)
			return (0);
		*line = malloc(sizeof(int) * map->column_nb);
		init_tab(line, map->column_nb);
	}
	while (pos->x < map->column_nb)
	{
		if (buff[pos->x] == map->block)
			(*line)[pos->x] == 0;
		else
			(*line)[pos->x]++;
		pos->x++;
	}
	map->square = read_line(*line, map->square, pos);
	pos->y++;
}

t_square	*get_square(int file, t_map *map)
{
	int			*line;
	t_pos		pos;
	int			ret;
	char		buff[BUFF_SIZE];

	pos.x = 0;
	pos.y = 0;
	while ((ret = read(file, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[ret] = 0;
		if (!go(buff, &line, &pos, map))
			return (NULL);
	}
	if (pos.y != map->line_nb || map->column_nb == 0)
		return (NULL);
	return (map->square);
}
