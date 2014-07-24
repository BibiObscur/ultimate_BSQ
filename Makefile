# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larrive <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/15 10:51:27 by larrive           #+#    #+#              #
#    Updated: 2014/07/24 16:00:58 by bperreon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCDIR = ./srcs
INCLUDEDIR = ./includes
SRC = read_file.c ft_put.c ft_str.c io_line.c get_square.c main.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror -I $(INCLUDEDIR)
CC = gcc $(FLAG)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Ofast -o $(NAME) $(OBJ)

%.o: $(SRCDIR)/%.c
	$(CC) -Ofast -o $@ -c $<

clean:
	-rm $(OBJ)

fclean: clean
	-rm $(NAME)

re: fclean all
