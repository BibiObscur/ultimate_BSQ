/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 16:44:20 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 16:01:22 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_def.h"
#include "ft_put.h"

void	run_bsq(int is_file, char *filename)
{
	t_map *map;

	map = read_file(is_file, filename);
	if (map)
	{
		ft_putstr("x = ", 1);
		ft_putnbr(map->square->pos.x, 1);
		ft_putstr("   y = ", 1);
		ft_putnbr(map->square->pos.y, 1);
		ft_putstr("   size = ", 1);
		ft_putnbr(map->square->size, 1);
		//display_map(is_file, filename, map);
	}
	else
		ft_putstr("map error", 2);
}

int		main(int ac, char **av)
{
	int i;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
			run_bsq(1, av[i]);
	}
	else
		run_bsq(0, 0);
	return (0);
}
