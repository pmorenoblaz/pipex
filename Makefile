SRCS	= 	main.c ft_lstadd_back.c ft_lstlast.c ft_split.c ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strjoin.c ft_memcpy.c ft_first_command.c

OBJS	= $(SRCS:.c=.o)

NAME	= pipex

CFLAGS	= -Wall -Werror -Wextra 

GCC	= gcc

RM	= rm -f

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:		
	$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re 
