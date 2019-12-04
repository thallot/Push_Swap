# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thallot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 14:51:59 by thallot           #+#    #+#              #
#    Updated: 2019/07/29 16:19:36 by thallot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################
_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

############## FLAGS ##################

NAME = push_swap
NAME_2 = checker
CC = gcc
CFLAGS = -Werror -Wall -Wextra
HEADER = include

############## FILES ##################

SRC=  src/checker.c \
			src/sort.c \
			src/util_sort.c \
			src/util.c \
			src/op.c \
			src/opbis.c \
			src/lst.c \
			src/lstbis.c \
			src/free.c \
			src/opti.c \
			src/qsort.c \
			src/quicksort.c \
			src/utilbis.c \
			src/sorting.c \
			src/split.c

PUSH = src/main_push.c
CHECK = src/main_checker.c

############## PATH ##################

OBJECTS	= $(SRC:.c=.o)
OBJ_P = $(PUSH:.c=.o)
OBJ_C = $(CHECK:.c=.o)

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJ_P) $(OBJ_C) lib push check include/push_swap.h

push: $(OBJECTS) $(OBJ_P) $(OBJ_C) lib include/push_swap.h
	@$(CC) $(CFLAGS) $(OBJECTS) $(PUSH) libft/libft.a -o $(NAME)
	@echo "$(_GREEN)[OK] $(_BLUE)Creation de $(_WHITE)push_swap"

check: $(OBJECTS) $(OBJ_P) $(OBJ_C) lib include/push_swap.h
	@$(CC) $(CFLAGS) $(OBJECTS) $(CHECK) libft/libft.a -o $(NAME_2)
	@echo "$(_GREEN)[OK] $(_BLUE)Creation de $(_WHITE)checker"

lib:
	@make -C libft

%.o: src/%.c
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(OBJ_P)
	@rm -rf $(OBJ_C)

fclean: clean
	@rm -rf $(NAME) $(NAME_2)
	@make fclean -C libft
	@echo "$(_GREEN)[OK]$(_RED) Supression de $(_WHITE)$(NAME) $(_RED)et $(_WHITE)$(NAME_2)"

re: fclean all
	@echo "$(_GREEN)[OK]$(_BLUE) Succes $(_WHITE)"
