SRCS = \
main.c\
parsing/parsing_minishell.c\
parsing/ft_split_arg.c\
parsing/first_verifications.c\
parsing/alloc_tab.c\
parsing/fill_tab.c\
parsing/parsing_utils.c\
parsing/select_quoted_str.c\
parsing/separate_pipe.c\
parsing/join_quote_to_line.c\
parsing/put_quoted_together.c\
parsing/trim_arg.c\
parsing/delete_empty_lines.c\
parsing/append_tabs_and_free_arg.c\
is_infile.c\
reglue_quoted.c\
parse_bloc.c\
define_fdin.c\
print_tab_arg.c\
is_x_char_in_str_spaces.c\

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