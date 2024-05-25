NAME 			= 	imageCompressor

BINARY_NAME 			= 	imageCompressor

_PATH 	:=	$(shell stack path --local-install-root)

all:
	stack build
	cp $(_PATH)/bin/$(NAME)-exe ./$(BINARY_NAME)

clean:
	stack clean

fclean: clean
	rm -f $(BINARY_NAME)

re: fclean all

.PHONY: all clean fclean re