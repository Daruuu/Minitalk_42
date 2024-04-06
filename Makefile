
SERVER		=	ft_server.c
CLIENT		=	ft_client.c

PRINTF		=	make -C include/printf/ make
LIB_PRINTF	=	include/printf/libftprintf.a
CLEAN_LIB	=	make -C include/printf/ fclean

# ---------------sources and objects----------------------

SERVER_SRC	=	$(SERVER)
CLIENT_SRC	=	$(CLIENT)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(SERVER_OBJS) $(CLIENT_OBJS)

# ----------------- Constants strings ---------------------

CC			=	cc 
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f
HEADER		=	minitalk.h

SERVER_NAME	=	server
CLIENT_NAME	=	client

NAME 		= 	server

# -------------------------RULES----------------------------

$(NAME):	ft_server ft_client

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) start_include 

start_include:
	@$(PRINTF)
	@$(LIB_PRINTF)

ft_server:	$(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB_PRINTF) -o $(SERVER_NAME)

ft_client:	$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB_PRINTF) -o $(CLIENT_NAME)

clean:		
	$(RM) $(OBJS)
	$(CLEAN_LIB)

fclean:	clean
	$(RM) $(NAME)
	$(CLEAN_LIB)

re:	fclean all

.PHONY:	all clean fclean re start_include
