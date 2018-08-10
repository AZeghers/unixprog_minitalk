##
## Makefile for  in /home/zegher_a/Modules/Sys_Unix/PSU_2015_minitalk
## 
## Made by alexis zeghers
## Login   <zegher_a@epitech.net>
## 
## Started on  Wed Feb 10 13:13:05 2016 alexis zeghers
## Last update Sun Feb 21 15:44:12 2016 alexis zeghers
##

CC	=	gcc

CNAME	=	client/client

SNAME	=	server/server

CSRCS	=	client/client.c \
		server/server2.c

SSRCS	=	server/server.c \
		server/server2.c \
		server/power.c

COBJS	=	$(CSRCS:.c=.o)

SOBJS	=	$(SSRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

all	:	client server

client	:	$(COBJS)
		$(CC) -o $(CNAME) $(CSRCS)

server	:	$(SOBJS)
		$(CC) -o $(SNAME) $(SSRCS)

clean	:
		rm -f $(SOBJS) $(COBJS)

fclean	:	clean
		rm -f ./client/client ./server/server

re	:	fclean all

.PHONY	:	all clean fclean re
