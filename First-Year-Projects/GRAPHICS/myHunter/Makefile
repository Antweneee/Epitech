##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile csfml
##

SRC	=	src/main.c	\
		src/sprite.c	\
		src/my_use.c	\
		src/my_put.c	\
		src/gestion.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-Wall -I include/

NAME	=	my_hunter

CC	=	gcc -g

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all	:	$(NAME)

clean	:
	rm -f $(OBJ)
	rm -f *~
	rm -f src/*~

fclean	:	clean
	rm -f $(NAME)

re:	fclean all

.PHONI:	clean fclean re all
