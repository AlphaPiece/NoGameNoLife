# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 12:53:24 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/04/07 12:55:54 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048
CC = gcc 

SRCS = srcs/init.c srcs/util.c srcs/oper.c
INCS = incs

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRCS) -I $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
