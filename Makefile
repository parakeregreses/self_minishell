SRCS = \
main.c\
blocs/blocs.c\
blocs/ft_split_arg.c\
blocs/first_verifications.c\
blocs/alloc_tab.c\
blocs/fill_tab_blocs.c\
blocs/blocs_utils.c\
blocs/select_quoted_str.c\
blocs/separate_pipe.c\
blocs/join_quote_to_line.c\
blocs/put_quoted_together.c\
blocs/trim_arg.c\
blocs/delete_empty_lines.c\
blocs/append_tabs_and_free_arg.c\
tokenisation/delete_useless_spaces.c\
tokenisation/delete_useless_spaces2.c\
tokenisation/token_bloc.c\
is_infile.c\
reglue_quoted.c\
parse_bloc.c\
define_fdin.c\
print_tab_arg.c\
is_x_char_in_str_spaces.c\
is_here_doc.c\
find_fdin.c\
here_doc.c\
blocs/remove_whitespaces.c\
blocs/revamp_str.c\
blocs/second_verifications.c\
triple_char.c\
blocs/check_quotes.c\

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