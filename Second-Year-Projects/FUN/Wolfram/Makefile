##
## EPITECH PROJECT, 2022
## B-FUN-400-PAR-4-1-wolfram-antoine.gavira-bottari
## File description:
## Makefile
##

BINARY_NAME	=	wolfram

_PATH	:=	$(shell stack path --local-install-root)

all:
	stack build
	cp $(_PATH)/bin/$(BINARY_NAME)-exe ./$(BINARY_NAME)

clean:
	stack clean

fclean: clean
	$(RM) $(BINARY_NAME)

re: fclean all

.PHONY: all clean fclean re