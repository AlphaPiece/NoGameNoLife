# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 12:53:24 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/04/08 10:09:36 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tic_tac_toe
CC = gcc 

SRCS = srcs/init.c srcs/util.c srcs/mode.c srcs/tactic.c
INCS = -I incs -I libs/libft/incs
LIBS = libs/libft/libft.a

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(SRCS) $(INCS) $(LIBS)

fclean:
	@rm -rf $(NAME)

re: fclean all
