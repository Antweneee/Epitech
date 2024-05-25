##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	=	src/main.c	\
		src/my_ls.c	\
		src/other_case.c	\

LDFLAGS	=	-L ./lib/ -lmy

CPPFLAGS	=	-Wall -I include/

LIB	=	libmy.a

CC	=	gcc -g

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(LIB) $(NAME)

$(LIB)	:
	make -C ./lib/my/

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) src/*~
	$(RM) include/*~
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY:	clean fclean re all
