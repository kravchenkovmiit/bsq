# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktimika <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 11:35:57 by ktimika           #+#    #+#              #
#    Updated: 2019/07/24 14:55:04 by ktimika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = ./srcs/analize_map.c ./srcs/bsq.c ./srcs/create_num_map.c\
	  ./srcs/ft_atoi.c ./srcs/get_params.c ./srcs/get_string_from_file.c\
	  ./srcs/get_string_from_input.c ./srcs/max_finder.c ./srcs/print_treasure.c\
	  ./srcs/valid_par.c

OBJ = analize_map.o bsq.o create_num_map.o ft_atoi.o get_params.o\
	  get_string_from_file.o get_string_from_input.o max_finder.o\
	  print_treasure.o valid_par.o

HEADER = ./srcs/bsq.h

all : $(NAME)

$(NAME) : 
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEADER)
	@gcc $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
