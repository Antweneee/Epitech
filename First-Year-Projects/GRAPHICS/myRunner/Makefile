##
## EPITECH PROJECT, 2020
## makefile 
## File description:
## makefile csfml
##

SRC	=	src/gestion.c	\
		src/action.c	\
		src/main.c	\
		src/set.c	\
		src/my_use.c	\
		src/sound.c	\
		src/parallax.c	\
		src/fill_struct.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS        =       -Wall -I include/

NAME	=	my_runner

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
