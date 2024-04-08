SERVER		=	ft_server.c
CLIENT		=	ft_client.c

INCL_LIBFT	=	include/libft/
INCL_PRINTF	=	include/printf/

# ------------------LIBFT source-----------------------

LIBFT		=	make -C $(INCL_LIBFT)
LIB_LIBFT	=	$(INCL_LIBFT)libft.a

CLEAN_LIBFT	=	make fclean -C include/libft/ 

# ------------------PRINTF source--------------------------

PRINTF		=	make -C $(INCL_PRINTF)
LIB_PRINTF	=	$(INCL_PRINTF)libftprintf.a

CLEAN_PRINTF=	make fclean -C include/printf/ 

# ---------------sources and objects----------------------

SERVER_SRC	=	$(SERVER)
CLIENT_SRC	=	$(CLIENT)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(SERVER_OBJS) $(CLIENT_OBJS)

# ----------------- Constants strings ---------------------

CC			=	cc 
CFLAGS		=	-Wall -Wextra -Werror
HEADER		=	minitalk.h

RM			=	rm -f

SERVER_NAME	=	server
CLIENT_NAME	=	client

NAME_SERVER = 	server
NAME_CLIENT	=	client

# -------------------------RULES----------------------------

all:	compile $(NAME) 

$(NAME):	ft_server ft_client

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

compile: 	
	$(PRINTF)
	$(LIBFT)

ft_server:	$(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB_PRINTF) -o $(SERVER_NAME)

ft_client:	$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB_PRINTF) -o $(CLIENT_NAME)

clean:		
	$(RM) $(OBJS)
	make clean -C include/libft/
	make clean -C include/printf/

fclean:	clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(CLEAN_LIBFT)
	$(CLEAN_PRINTF)

re:	fclean all

.PHONY:	all clean fclean re start_include

