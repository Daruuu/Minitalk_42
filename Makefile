SERVER = 
CLIENT =

CC = 		cc 
CFLAGS = 	-Wall -Wextra -Werror

RM = 		rm -f

HEADER = 	minitalk.h

SRCS = 



OBJS = 		$(SRCS:.c=.o)

%.o:%.c = 	$(HEADER) Makefile
			$(CC CFLAGS) -c $< -o $@

all = 		$(NAME)

$(NAME):	$(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
