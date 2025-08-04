SRCS = \
main.c\
blocisation/blocisation.c\
blocisation/ft_split_arg.c\
blocisation/first_verifications.c\
blocisation/alloc_tab.c\
blocisation/fill_tab_blocs.c\
blocisation/blocisation_utils.c\
blocisation/select_quoted_str.c\
blocisation/separate_pipe.c\
blocisation/join_quote_to_line.c\
blocisation/put_quoted_together.c\
blocisation/trim_arg.c\
blocisation/delete_empty_lines.c\
blocisation/append_tabs_and_free_arg.c\
blocisation/remove_whitespaces.c\
blocisation/revamp_str.c\
blocisation/second_verifications.c\
blocisation/check_quotes.c\
tokenisation/delete_useless_spaces.c\
tokenisation/delete_useless_spaces2.c\
tokenisation/token_bloc.c\
tokenisation/full_tokenisation.c\
extraction/find_fdin.c\
extraction/here_doc.c\
extraction/is_infile.c\
print_tab_arg.c\
triple_char.c\
extraction/parsing_processes.c\
extraction/extract_infos.c\
extraction/str_without_quotes.c\
extraction/find_fdout.c\
extraction/find_cmdarg.c\
pipex.c\
execution.c\
ft_iscmd.c\
parse_commands.c\

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