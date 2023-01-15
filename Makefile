NAME		= ft_nm

SRCS		= main.c 

OBJS		= $(SRCS:.c =.o)

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -pedantic

.c.o:
		$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o} -I

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:			all clean fclean re