/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperreon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:44:44 by bperreon          #+#    #+#             */
/*   Updated: 2014/07/24 12:02:39 by bperreon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char c);
int		ft_get_nb(char *str);
char	*ft_join(char *s1, char *s2);

int		get_nextline(int fd, char **line);

#endif
