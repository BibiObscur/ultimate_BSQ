/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 22:00:47 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/23 22:18:44 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_DEF_H
# define BSQ_DEF_H

typedef struct	s_square
{
	int			size;
	int			x;
	int			y;
}				t_square;

typedef struct	s_map
{
	int			column_nb;
	int			line_nb;
	char		empty;
	char		block;
	char		full;
	t_square	*square;
}				t_map;

t_map			*read_file(int is_file, char *filename);
t_square		*get_square(int file, t_map *map);

#endif
