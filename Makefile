NAME		=	minishell

HEADER		=	minishell.h

SRCS		= 	for_sanya.c \
				ft_echo.c \
				ft_split.c \
				listfun.c \
				utils.c

OBJS		=	$(SRCS:.c=.o)

FLAGS		=	-Wall -Wextra -Werror -g 
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HEADER)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS)
				$(GCC) $(OBJS) -o $(NAME)

clean:				
				rm -f $(OBJS)
			
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re