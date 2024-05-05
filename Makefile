# Paths
MAKE = make --no-print-directory
INCL_LIBFT   = include/libft/
INCL_PRINTF  = include/libft/printf/

# Source files
SERVER       = server.c
CLIENT       = client.c

# Object files
SERVER_OBJS  = $(SERVER:.c=.o)
CLIENT_OBJS  = $(CLIENT:.c=.o)
OBJS         = $(SERVER_OBJS) $(CLIENT_OBJS)

# Names
SERVER_NAME  = server
CLIENT_NAME  = client

# Compilation
CC           = cc
CFLAGS       = -Wall -Wextra -Werror
PRINTF_LIB   = $(INCL_PRINTF)libftprintf.a
LIBFT_LIB    = $(INCL_LIBFT)libft.a

# Commands
RM           = rm -f

# Rules
all: compile $(SERVER_NAME) $(CLIENT_NAME)

compile:
	@$(MAKE) -C $(INCL_LIBFT)
	@$(MAKE) -C $(INCL_PRINTF)

$(SERVER_NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $@

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(INCL_LIBFT)
	@$(MAKE) clean -C $(INCL_PRINTF)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@$(MAKE) fclean -C $(INCL_LIBFT)
	@$(MAKE) fclean -C $(INCL_PRINTF)

re: fclean all

.PHONY: all compile clean fclean re
