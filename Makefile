# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/03/12 12:49:45 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO = echo -e
endif
ifeq ($(UNAME_S),Darwin)
	ECHO = echo
endif

LC = ar rcs
CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -g

SRC = srcs/ft_printf.c srcs/pf_cputchar.c srcs/pf_decimal.c srcs/pf_decimal2.c \
srcs/pf_string.c srcs/pf_address.c

OBJ = $(SRC:.c=.o)

LOBJ = libft/srcs/*/*.o
LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $< -o $@
	@$(ECHO) "[$(GREEN)✓$(WHITE)]"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(ECHO) -n '\_______,-<=-=> ./$(NAME): '
	@$(LC) $(NAME) $(OBJ) $(LOBJ)
	@$(ECHO) "$(INVERT)[$(GREEN)✓$(WHITE)$(INVERT)]$(WHITE)"

ft_test:
	@$(CC) test/main.c $(NAME) $(LIBFT)
	@$(ECHO) "$(INVERT)[$(GREEN)test$(WHITE)$(INVERT)]$(WHITE)"
del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(RED)deleted$(WHITE): ./$(NAME)"

re: fclean all

.PHONY: all fclean clean re
