/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 16:44:20 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/23 17:17:02 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq_def.h"
#include "ft_put.h"
#include "ft_list.h"

void	delete_map(t_map **map)
{
	free_list((*map)->obs);
	free(*map);
}

void	run_obs(int filedes)
{
	t_map		*map;

	map = read_map(filedes);
	if (map)
	{
		display_map(map, get_max_square(map));
		delete_map(&map);
	}
	else
		ft_putstr("map error\n", 2);
}

int		main(int ac, char **av)
{
	int i;
	int filedes;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			filedes = open(av[i], O_RDONLY);
			run_obs(filedes);
			close(filedes);
		}
	}
	else
		run_obs(0);
	return (0);
}
