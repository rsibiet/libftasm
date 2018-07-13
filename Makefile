# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 12:44:44 by rsibiet           #+#    #+#              #
#    Updated: 2017/05/04 13:32:44 by ksoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests

FTC = tests.c

FTO = $(FTC:%.c=%.o)

EXEC = libfts.a
.PHONY: all re clean fclean

all: $(EXEC) $(NAME)

$(EXEC):
		@echo "\033[34;1m_____________ Loading libfts _____________\033[0m\n"
		@make -C ./libfts

$(NAME): $(FTO)
	@echo ""
	@echo "\033[32m• $(NAME) created!\033[0m"
	@echo "\n"
	@gcc -Wall -Wextra -Werror -o $(NAME) $(FTO) -L./libft/ -lft

%.o: %.c
	@tput civis
	@gcc -Wall -Wextra -Werror -I./libfts/ -o $@ -c $<
	@tput cnorm

clean:
	@rm -rf $(FTO)
	@echo "\033[33m• $(NAME) object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31m$(NAME) deleted!\033[0m"

re: fclean all
