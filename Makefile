# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/11/18 15:42:09 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(notdir $(CURDIR)).a
NPWD = $(CURDIR)/$(NAME)

ECHO := echo
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e
	AR := llvm-ar -rcs
endif
ifeq ($(UNAME_S),Darwin)
	AR := ar -rcs
endif

CC := clang

CFLAGS := -march=native -mtune=native -Ofast -pipe -flto -fpic
CFLAGS_DEBUG := -glldb -D DEBUG

CC_WARNINGS_FLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes -I $(CURDIR)/../libft/includes/

SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]
SUCCESS_NO_CLR = [✓]

.PHONY: multi all
multi:
ifneq (,$(filter $(MAKECMDGOALS),debug debug_all))
	@$(MAKE) -j 3 -Otarget --no-print-directory CFLAGS="$(CFLAGS_DEBUG)" all
else
	@$(MAKE) -j 3 -Otarget --no-print-directory all
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(MAKE) -q STATUS --no-print-directory

$(OBJS): %.o: %.c
	@$(CC) -c $(CFLAGS) $(CC_WARNINGS_FLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) " | $@: $(SUCCESS)"

STATUS:
	@$(info / compiled: $(NPWD): $(SUCCESS_NO_CLR))
	@$(info \ flags: $(CFLAGS))

debug_all: pre
debug: multi

clean:
	@$(DEL) $(OBJS)
fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)deleted$(WHITE): $(NPWD)"

pre: fclean multi
re: fclean multi

norme:
	@$(ECHO) "$(INVERT)norminette$(WHITE) for $(NPWD):"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean norme del pre debug debug_all norme STATUS
