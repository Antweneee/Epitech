##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	=	src/main.c	\
			src/set_scene.c	\
			src/process.c	\
			src/game.c	\
			src/check.c	\
			src/bot.c	\

LDFLAGS	=	-L ./lib/ -lmy

CFLAGS =	-Wall -Werror -Wextra

CPPFLAGS	=	-I./include

LIB	=	libmy.a

CC	=	gcc -g

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(LIB) $(NAME)

$(LIB)	:
	make -C ./lib/my/

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY:	clean fclean re all
