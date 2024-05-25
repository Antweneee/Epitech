##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile csfml
##

SRC	=	src/main.c	\
		src/my_use.c	\
		src/set.c	\
		src/menu.c	\
		src/destroy.c	\
		src/draw.c	\
		src/scene.c	\
		src/chain_list.c	\
		src/movement.c	\
		src/check.c	\
		src/game.c	\
		src/path.c	\
		src/animation.c	\
		src/sound.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-Wall -Wextra -I include/

NAME	=	my_defender

CC	=	gcc -g

RM = rm -f

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all	:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONI:	clean fclean re all
