SRCS = \
delete_line_in_tab.c\
main.c\
extract_str_in_str.c\
find_segment.c\
append_tabs_and_free.c\
parsing.c\

OBJS = $(SRCS:.c=.o)

INCLUDE = includes

NAME = minishell

LIBRARY = libft/libft.a\

LIBDIR = -C ./libft

MAKELIB = make $(LIBDIR)

CC = cc

FLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

all : $(NAME)

bonus : $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(LIBRARY)
	$(CC) $(FLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

$(LIBRARY) :
	$(MAKELIB)

clean : 
	rm -rf $(OBJS)
	make clean $(LIBDIR)

fclean : clean
	rm -rf $(NAME)
	make fclean $(LIBDIR)

re : fclean all

.PHONY: all clean fclean re