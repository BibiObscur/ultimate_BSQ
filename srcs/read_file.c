/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 22:03:37 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/23 22:36:25 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq_def.h"
#include "ft_str.h"

#include "ft_put.h"

t_map		*set_map_char(t_map *map, char *header)
{
	int i;

	i = 0;
	while (header[i] != '\n')
		i++;
	map->full = header[--i];
	map->block = header[--i];
	map->empty = header[--i];
	header[i] = 0;
	map->line_nb = ft_get_nb(header + (i = 0));
	while (header[i] >= '0' && header[i] <= '9')
		i++;
	if (header[i] != '\0')
		return (NULL);
	free(header);
	return (map);
}

t_map	*get_char(int filedes)
{
	t_map	*map;
	char	buff[2];
	char	*header;

	map = (t_map *)malloc(sizeof(t_map));
	header = (char *)malloc(sizeof(char) * 1);
	*header = 0;
	while (read(filedes, buff, 1) >= 0 && *buff != '\n')
	{
		buff[1] = 0;
		header = ft_strcat(header, buff);
	}
	header = ft_strcat(header, buff);
	return (set_map_char(map, header));
}

t_map	*read_file(int is_file, char *filename)
{
	t_map		*map;
	int			file;

	if (is_file)
		file = open(filename, O_RDONLY);
	else
		file = 0;
	map = get_char(file);
	if (!map || map->line_nb == 0)
		return (NULL);
	map->square = get_square(file, map);
	if (!(map->square))
		return (NULL);
	return (map);
}
