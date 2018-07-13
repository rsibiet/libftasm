# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 16:52:07 by rsibiet           #+#    #+#              #
#    Updated: 2017/05/22 10:59:06 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

FTC = ft_bzero.s \
	  ft_isalpha.s \
	  ft_isdigit.s \
	  ft_isalnum.s \
	  ft_isascii.s \
	  ft_isprint.s \
	  ft_tolower.s \
	  ft_toupper.s \
	  ft_strcat.s \
	  ft_strlen.s \
	  ft_puts.s \
	  ft_memset.s \
	  ft_memcpy.s \
	  ft_strdup.s \
	  ft_cat.s \
	  ft_memalloc.s \
	  ft_strnlen.s \
	  ft_strncat.s \
	  ft_strchr.s \
	  ft_abs.s \
	  ft_putchar.s

FTO = $(subst .s,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@ar rc $(NAME) $(FTO)
	@ranlib $(NAME)
	@echo ""
	@echo ""
	@echo "\033[32m• $(NAME) created!\033[0m"
	@echo ""
	@echo ""
	@echo "\033[0m---------------------------------------------------------------"

%.o: %.s
	@nasm -f macho64 $<
	@echo "\033[42m   \033[0m\c"

clean:
	@rm -rf $(FTO)
	@rm -rf ./main.o
	@rm -rf ./main_cat.o
	@echo "\033[33m• Libfts object deleted!\033[0m"
	@echo ""

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./main
	@rm -rf ./main_cat
	@echo "\033[31;1m• \033[31mLibfts deleted!\033[0m"
	@echo ""

re: fclean all

run_tests: re
	@gcc -I./ -c main.c
	@gcc -Wall -Wextra -Werror -o main main.o ./libfts.a
	@echo "\033[32m• main created!\033[0m"
	@echo ""
	@echo "\033[33m----- RUN TESTS -----\033[0m"
	@echo ""
	@./main

run_cat: re
	@gcc -I./ -c main_cat.c
	@gcc -W -Wall -Wextra -Werror -o main_cat main_cat.o ./libfts.a
	@echo "\033[32m• main_cat created!\033[0m"
	@echo ""
	@echo "\033[33m-----  RUN CAT  -----\033[0m"
	@echo ""
	@./main_cat
