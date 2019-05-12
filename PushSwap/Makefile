# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 18:49:31 by zwang             #+#    #+#              #
#    Updated: 2019/02/09 12:51:43 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m


all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):
	@make -C srcs/push_swap/ p
	@mv srcs/push_swap/push_swap .

$(CHECKER):
	@make -C srcs/checker/ c
	@mv srcs/checker/checker .

clean:
	@make -C srcs/push_swap/ clean
	@make -C srcs/checker/ clean

fclean: clean
	@rm -rf $(PUSH_SWAP)
	@printf "\033[1;31m[x] $(RESET)\x1B[31m$(PUSH_SWAP) deleted\n"
	@rm -rf $(CHECKER)
	@printf "\033[1;31m[x] $(RESET)\x1B[31m$(CHECKER) deleted\n"

re: fclean all

.PHONY: all clean fclean re
