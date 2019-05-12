# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 16:36:58 by zwang             #+#    #+#              #
#    Updated: 2019/02/09 12:52:12 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

DIRECTOR = design.c execute.c merge_sort.c simple_sort.c selection_sort.c
ASSISTANT = preparation.c information.c option.c view.c exam.c selection.c
STAGE = cmd_queue.c box_stacks.c
ACTOR = push.c reverse_rotate.c rotate.c swap.c act.c
MAIN = push_swap.c

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

p:
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
