##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
## File description:
## Makefile
##

SRC	=	main.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror

NAME	=	my_cat

CC	=	g++

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re:	fclean all

debug: CFLAGS += -g3
debug: re

.PHONI:	clean fclean re all