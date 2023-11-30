# Pipex Compilation Settings
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Pipex Files
SRCS		= src/pipex.c src/utils.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I ./libft -I ./src
LIBFT		= libft/libft.a
LIBS		= -L./libft -lft

# Pipex Name
NAME		= pipex

# Compile libft first, then pipex
all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Object Files
%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning Up
clean:
			$(MAKE) -C ./libft clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C ./libft fclean
			$(RM) $(NAME)

# Re-compiling
re:			fclean all

# Bonus Rules
bonus:		all

.PHONY:		all clean fclean re bonus
