_RED='\033[31m'
_GREEN='\033[32m'
_END='\033[0m'

NAME	=	306radiator

TEST_BIN_NAME = unit_tests

RM	=	rm -rf

all: ${NAME}

${NAME}:
	@cp ./sources/program.py ${NAME}
	@chmod +x ${NAME}
	@echo "${NAME}: ["${_GREEN}"OK"${_END}"]"

clean:
	@${RM} __pycache__/
	@${RM} ./sources/__pycache__/
	@${RM} ./tests/__pycache__/
	@${RM} ./build/
	@${RM} ./dist/
	@echo "clean folder: ["${_GREEN}"OK"${_END}"]"

fclean:	clean
	@${RM} ${NAME}
	@${RM} ${NAME}.exe
	@${RM} main.spec
	@${RM} a.out
	@${RM} *.gc*
	@${RM} ${TEST_BIN_NAME}
	@echo "clean binaries: ["${_GREEN}"OK"${_END}"]"

re:	fclean all

tests_run:	fclean
	@cp ./tests/unit_tests.py ${TEST_BIN_NAME}
	@chmod +x ${TEST_BIN_NAME}
	@./${TEST_BIN_NAME}
	@echo "unit_tests: ["${_GREEN}"OK"${_END}"]"

.PHONY:	all clean fclean re tests_run