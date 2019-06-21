# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/21 08:46:59 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NPWD = $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LC := gcc-ar
endif
ifeq ($(UNAME_S),Darwin)
	LC := ar
endif

LC += rcs

CC := gcc -flto -Ofast -pipe
CC_DEBUG := gcc -g3 -D DEBUG -fsanitize=address
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes -I $(CURDIR)/../libft/includes/

SRCS := $(abspath $(wildcard srcs/*.c))
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

all: $(NAME)

$(OBJS): %.o: %.c
	@echo -n ' $@: '
	@$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@
	@echo "[$(GREEN)✓$(WHITE)]"

$(NAME): $(OBJS)
	@echo "$(INVERT)"
	@echo -n ' <=-=> | $(NPWD): '
	@$(LC) $(NAME) $(OBJS)
	@echo "$(INVERT)[$(GREEN)✓$(WHITE)$(INVERT)]$(WHITE)"
	@echo

del:
	$(DEL) $(OBJS)
	$(DEL) $(NAME)

pre: del $(NAME)
	@echo "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJS)

fclean: clean
	@$(DEL) $(NAME)
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean all norme del pre debug debug_all norme
