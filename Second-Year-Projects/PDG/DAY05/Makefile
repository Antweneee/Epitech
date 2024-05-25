##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

SRC	=	ex00.c	\
		ex01.c	\
		ex02.c	\
		ex03.c	\
		ex04.c	\
		ex05.c	\
		ex06.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu17 -Wall -Wextra

RM	=	rm -f

NAME	=	libstring.a

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *gcda
	$(RM) *gcno

re: fclean all

.PHONY: all clean fclean re