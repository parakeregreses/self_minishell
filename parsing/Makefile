SRCS = \
main.c\
parsing.c\
print_tab_arg.c\
ft_split_arg.c\
first_verifications.c\
alloc_tab.c\
fill_tab.c\
parsing_utils.c\
select_quoted_str.c\
separate_pipe.c\
join_quote_to_line.c\
is_infile.c\
parse_bloc.c\
define_fdin.c\
reglue_quoted.c\
put_quoted_together.c\


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