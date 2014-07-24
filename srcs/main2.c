/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/24 11:56:28 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 13:12:46 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_str.h"
#include "ft_put.h"

int		main(int ac, char **av)
{
	int file;
	char *line;
	int  ret;

	if (ac > 1)
	{
		file = open(av[1], O_RDONLY);
		line = NULL;
		while ((ret = get_nextline(file, &line)) && line)
		{
//			if (ret < 0)
//				er
			ft_putstr(line, 1);
			ft_putstr("\n-----------\n", 1);
			free(line);
			line = NULL;
		}
		close(file);
	}
	return (0);
}
