##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

OBJ_SRC	=	main.c	\

OBJ	=	$(OBJ_SRC:.c=.o)

CPPFLAGS	=	-I include/

CFLAGS	=	-Wall -Wextra

NAME	=	./../my_objdump

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

debug:	CFLAGS += -g3
debug:	re

.PHONY: all clean fclean re debug
