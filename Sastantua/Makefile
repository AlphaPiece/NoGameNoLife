# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 12:53:24 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/04/10 10:16:11 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sastantua
CC = gcc

SRCS = srcs/sastantua.c srcs/main.c
INCS = -I libs/libft/incs
LIBS = libs/libft/libft.a

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRCS) $(LIBS) $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
