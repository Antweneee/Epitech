##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

SRC	=	z.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu17 -Wall -Wextra

RM	=	rm -f

NAME	=	z

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re