##
## EPITECH PROJECT, 2022
## B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc -luuid

SRCDIR	=	src

SERVERSRC	=	$(SRCDIR)/server/server_main.c	\
	$(SRCDIR)/server/init.c	\
	$(SRCDIR)/server/run.c	\
	$(SRCDIR)/server/check.c	\
	$(SRCDIR)/server/s_struct_related.c	\
	$(SRCDIR)/server/s_struct_related2.c	\
	$(SRCDIR)/commands/server/create.c	\
	$(SRCDIR)/commands/server/help.c	\
	$(SRCDIR)/commands/server/info.c	\
	$(SRCDIR)/commands/server/list.c	\
	$(SRCDIR)/commands/server/login.c	\
	$(SRCDIR)/commands/server/message.c	\
	$(SRCDIR)/commands/server/subscribe.c	\
	$(SRCDIR)/commands/server/unsubscribe.c	\
	$(SRCDIR)/commands/server/subscribed.c	\
	$(SRCDIR)/commands/server/use.c	\
	$(SRCDIR)/commands/server/user.c	\
	$(SRCDIR)/server/link_command.c	\
	$(SRCDIR)/server/io_file_func.c	\
	$(SRCDIR)/parseur.c	\
	$(SRCDIR)/parseur_args.c	\
	$(SRCDIR)/commands/server/help2.c	\
	$(SRCDIR)/commands/server/help3.c	\


CLIENTSRC	=	$(SRCDIR)/client/client_main.c	\
	$(SRCDIR)/client/run.c	\
	$(SRCDIR)/client/read_write_module.c	\
	$(SRCDIR)/client/c_struct_related.c	\
	$(SRCDIR)/commands/client/create.c	\
	$(SRCDIR)/commands/client/help.c	\
	$(SRCDIR)/commands/client/info.c	\
	$(SRCDIR)/commands/client/list.c	\
	$(SRCDIR)/commands/client/login.c	\
	$(SRCDIR)/commands/client/message.c	\
	$(SRCDIR)/commands/client/subscribe.c	\
	$(SRCDIR)/commands/client/unsubscribe.c	\
	$(SRCDIR)/commands/client/subscribed.c	\
	$(SRCDIR)/commands/client/use.c	\
	$(SRCDIR)/commands/client/user.c	\
	$(SRCDIR)/parseur_args.c	\
	$(SRCDIR)/parseur.c	\

SERVEROBJ	=	$(SERVERSRC:.c=.o)

CLIENTOBJ	=	$(CLIENTSRC:.c=.o)

CPPFLAGS	=	-I include/

CFLAGS	=	-Wall -Wextra

SERVER	=	myteams_server

CLIENT	=	myteams_cli

all: server client

$(SERVER):	$(SERVEROBJ)
	$(CC) -L libs/myteams/ -lmyteams -o $(SERVER) $(SERVEROBJ)

$(CLIENT):	$(CLIENTOBJ)
	$(CC) -L libs/myteams/ -lmyteams -o $(CLIENT) $(CLIENTOBJ)

server:	$(SERVER)

client:	$(CLIENT)

clean:
	$(RM) $(SERVEROBJ) $(CLIENTOBJ)

fclean:	clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug