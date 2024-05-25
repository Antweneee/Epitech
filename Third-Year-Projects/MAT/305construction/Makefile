##
## EPITECH PROJECT, 2022
## 305construction
## File description:
## Makefile
##

CXX	=	g++

CXXFLAGS	 +=	 -std=c++17
CXXFLAGS	 +=	 -I./include
CXXFLAGS	 +=	 -W -Wextra -Werror

RM	 ?=	 rm -rf

SRCS    =	main.cpp	 \
	./src/Construction.cpp  \
	./src/Error.cpp \
	./src/Task.cpp	\

SRC_TEST	=	./src/Construction.cpp  \
	./src/Error.cpp \
	test/Tests.cpp

OBJS    =	${SRCS:.cpp=.o}

TESTS_OBJS    :=    ${SRC_TEST:.cpp=.o}

NAME    =	305construction

TEST_BIN_NAME   =	unit_tests

all:    ${NAME}

${NAME}:	 ${OBJS}
	${CXX} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	${RM} ${TESTS_OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${TESTS_OBJS}
	${RM} ${TEST_BIN_NAME}
	${RM} *.gc*

re:	fclean all

tests_run: fclean ${TESTS_OBJS}
	${CXX} -o ${TEST_BIN_NAME} ${TESTS_OBJS} -lcriterion --coverage
	./${TEST_BIN_NAME}
	${RM} ${TESTS_OBJS}
	${RM} ${TEST_BIN_NAME}

debug: CXXFLAGS += -g3
debug: re

.PHONY: all clean fclean re tests_run debug