##
## EPITECH PROJECT, 2022
## B-MAT-500-PAR-5-1-302separation-antoine.gavira-bottari
## File description:
## Makefile
##

CXX	=	g++

CXXFLAGS	+=	-std=c++17
CXXFLAGS	+=	-I./include
CXXFLAGS	+=	-W -Wextra -Werror

RM	?=	rm -rf

SRCS	=	Main.cpp	\
	./src/Separation.cpp	\
	./src/Error.cpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	302separation

UNAME	=	unit_tests

all:	${NAME}

${NAME}:	${OBJS}
	${CXX} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	${RM} *.gc*

fclean:	clean
	${RM} ${NAME}

re:	fclean all

tests_run:
	${CXX} ${CXXFLAGS} ${SRC_TEST} -lcriterion --coverage -o ${UNAME}
	./${UNAME}

.PHONY:	all clean fclean re tests_run
