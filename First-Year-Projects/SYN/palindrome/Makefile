##
## EPITECH PROJECT, 2021
## B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/errors.c	\
		src/palindrom.c	\
		src/print.c	\
		src/compute.c	\
		src/parseur.c	\
		src/init.c	\
		src/bases.c	\
		src/use.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS 	=	-I include/

CFLAGS =	-Wall -Wextra -pedantic

RM 	= 	rm -f

NAME	=	palindrome

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug