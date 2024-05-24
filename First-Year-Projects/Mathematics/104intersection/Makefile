##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	=	src/main.c	\

LDFLAGS	=	-L ./lib/ -lmy

CPPFLAGS	=	-Wall -I include/

LIB	=	libmy.a

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	104intersection

all:	$(LIB) $(NAME)

$(LIB)	:
	make -C lib/my/

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -lm

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) src/*~
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY:	clean fclean re all
