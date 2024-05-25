##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-antoine.gavira-bottari
## File description:
## Makefile
##

SRC	=	src/main.cpp		\
	src/Parser.cpp			\

OBJ	=	${SRC:.cpp=.o}

CXX	=	g++

CXXFLAGS	+=	-I include/
CXXFLAGS	+=	-Wall -Wextra -pedantic

NAME	=	nanotekspice

RM	?=	rm -f

all:	${NAME}

${NAME}:	${OBJ}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}
	${RM} .*gc*

fclean:	clean
	${RM} ${NAME}

re:	fclean all

debug: CXXFLAGS += -g3
debug: re

.PHONY:	all clean fclean re