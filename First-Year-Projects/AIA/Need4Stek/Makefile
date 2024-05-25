##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/exec_commands.c \
		src/end.c	\
		src/gestion.c \
		src/loop.c	\
		src/main.c \
		src/my_str_to_word_array.c	\

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

CC	=	gcc -g

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean re all
