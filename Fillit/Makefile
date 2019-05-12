# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 15:54:57 by zwang             #+#    #+#              #
#    Updated: 2019/02/20 22:57:57 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_DIR = srcs/
OBJS_DIR = objs/

INCS = -I incs/ -I libs/libft/incs/
SRCS = $(wildcard $(SRCS_DIR)*.c)
LIBS = libs/libft/libft.a
OBJS = $(patsubst srcs/%.c, %.o, $(SRCS))


all: $(NAME)

$(NAME):
	@$(CC) -g $(CFLAGS) -c $(SRCS) $(INCS)
	@$(CC) -g -o $(NAME) $(OBJS) $(LIBS)
	@mkdir -p $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

do:
	./fillit tests/valid.fillit
	./fillit tests/invalid.fillit

.PHONY: all clean fclean re
