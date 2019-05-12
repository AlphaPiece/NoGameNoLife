# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 09:27:33 by zwang             #+#    #+#              #
#    Updated: 2019/02/09 12:52:29 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra

DIRECTOR = execute.c
ASSISTANT = preparation.c information.c option.c view.c exam.c
STAGE = cmd_queue.c box_stacks.c
ACTOR = push.c reverse_rotate.c rotate.c swap.c
MAIN = checker.c

DIRECTOR_DIR = ../film_crew/director/
ACTOR_DIR = ../film_crew/actor/
ASSISTANT_DIR = ../film_crew/assistant/
STAGE_DIR = ../film_crew/stage/
OBJS_DIR = ./objs/

PUSH_SWAP_INCS = ../../incs/
LIBFT_INCS = ../../libs/libft/incs/

INCS = -I $(PUSH_SWAP_INCS) -I $(LIBFT_INCS)
SRCS = $(addprefix $(ACTOR_DIR), $(ACTOR)) \
		$(addprefix $(STAGE_DIR), $(STAGE)) \
		$(addprefix $(ASSISTANT_DIR), $(ASSISTANT)) \
		$(addprefix $(DIRECTOR_DIR), $(DIRECTOR)) \
		$(MAIN)
LIBS = ../../libs/libft/libft.a
OBJS = $(addprefix $(OBJS_DIR), *.o)

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

all: $(NAME)

$(NAME):
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@$(CC) -g $(CFLAGS) -c $(SRCS) $(INCS)
	@mkdir -p $(OBJS_DIR)
	@mv *.o $(OBJS_DIR)
	@$(CC) -g -o $(NAME) $(OBJS) $(LIBS)
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

c:
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@$(CC) -g $(CFLAGS) -c $(SRCS) $(INCS)
	@mkdir -p $(OBJS_DIR)
	@mv *.o $(OBJS_DIR)
	@$(CC) -g -o $(NAME) $(OBJS) $(LIBS)
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

clean:
	@rm -rf *.o
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) object files deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) deleted\n"

re: fclean all

.PHONY: all clean fclean re
