##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD02-illyas.chihi
## File description:
## Makefile
##

CC	=	ghc

SRC	=	main.hs	\

NAME	=	pushswap_checker

all:	$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC) $(OBJ)

clean:
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)
		$(RM) *.hi

re:	fclean all

.PHONY:	all clean fclean re