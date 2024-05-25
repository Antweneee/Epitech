##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

NM_SRC	=	main.c	\
		engine.c	\
		getchar.c	\

OBJ	=	$(NM_SRC:.c=.o)

CPPFLAGS	=	-I include/

CFLAGS	=	-Wall -Wextra

NAME	=	./../my_nm

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
