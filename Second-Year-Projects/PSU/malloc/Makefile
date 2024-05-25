##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	src/malloc.c	\

OBJ = $(SRC:.c=.o)

CPPFLAGS = -fpic -I./include

NAME = libmy_malloc.so

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -fpic -shared -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug
