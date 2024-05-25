##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

MAKE	=	make

LIB	=	libmy.a

RM	=	rm -f

all:
	$(MAKE) -C lib/my/
	$(MAKE) -C solver/
	$(MAKE) -C generator/

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C lib/my/
	$(MAKE) clean -C solver/
	$(MAKE) clean -C generator/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/my/
	$(MAKE) fclean -C solver/
	$(MAKE) fclean -C generator/

re:	fclean all

.PHONY:	all clean fclean re
