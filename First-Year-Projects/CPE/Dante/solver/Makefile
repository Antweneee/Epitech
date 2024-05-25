##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC		= 	main.c\

LDFLAGS	=	-L ../lib/my/ -lmy

CFLAGS =	-Wall -Wextra

CPPFLAGS	=	-I ../include

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
