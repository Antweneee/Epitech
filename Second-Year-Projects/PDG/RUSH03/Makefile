##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
## File description:
## Makefile
##

CC		=	g++

SRC		=	backend/main.cpp		\
			ncurse/main_ncurses.cpp		\
			sfml/main_sfml.cpp		\
			sfml/sfml.cpp	\
			sfml/Display.cpp	\
			backend/Network/Network.cpp		\
			backend/CPU/cpu_info.cpp		\
			backend/SYS/sys_info.cpp		\

OBJ		=	$(SRC:.cpp=.o)

LDFLAGS	=	-I./includes

CFLAGS		= -Wall -Wextra -g3

LDFLAGS = -lncurses

GFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

NAME		= MyGKrellm

all:	$(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(GFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re