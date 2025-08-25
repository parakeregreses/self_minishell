SRCS = 												\
			minishell_base/command.c				\
			minishell_base/cat_current_dir.c		\
			minishell_base/main.c					\
			minishell_base/launching.c				\
			blocisation/blocisation.c				\
			blocisation/first_verifications.c		\
			blocisation/alloc_tab.c					\
			blocisation/fill_tab_blocs.c			\
			blocisation/blocisation_utils.c			\
			blocisation/select_quoted_str.c			\
			blocisation/append_tabs_and_free_arg.c	\
			blocisation/remove_whitespaces.c		\
			blocisation/revamp_str.c				\
			blocisation/second_verifications.c		\
			blocisation/triple_char.c				\
			blocisation/third_verifications.c		\
			blocisation/delete_empty_lines.c		\
			tokenisation/token_bloc.c				\
			tokenisation/full_tokenisation.c		\
			tokenisation/str_without_quotes.c		\
			tokenisation/tab_without_quotes.c		\
			tokenisation/expand_dollar.c			\
			extraction/find_in_out_file1.c			\
			extraction/find_in_out_file2.c			\
			extraction/here_doc.c					\
			extraction/is_infile.c					\
			extraction/extract_infos.c				\
			extraction/extract_info.c				\
			extraction/find_outfile.c				\
			extraction/find_cmdarg.c				\
			execution/pipex_init.c					\
			execution/pipex.c						\
			execution/execution.c					\
			execution/find_fd.c						\
			execution/pipex2.c						\
			execution/exec_builtin.c				\
			parsing/ft_iscmd.c						\
			parsing/cmd_is_directory.c				\
			parsing/file_type.c						\
			parsing/parse_commands.c				\
			parsing/is_builtin.c					\
			parsing/ft_findpathforeachcommand.c		\
			built_in/cd.c							\
			built_in/echo.c							\
			built_in/env.c							\
			built_in/export_utils.c					\
			built_in/export.c						\
			built_in/pwd.c							\
			built_in/unset.c						\
			built_in/exit.c							\
			built_in/exit_util.c					\
			env/env_variables.c						\
			env/ft_free_envp.c						\
			delete/delete_tempfiles.c				\
			delete/full_delete_minishell.c			\
			delete/free_tab_3d.c					\
			expand/expand.c							\
			expand/close_dollar.c					\
			expand/delete_quote.c					\
			expand/delete_quote2.c					\
			expand/fill_line.c						\
			expand/size_line.c						\
			expand/dollar.c							\
			expand/handle_dollars.c					\
			expand/handle_dollars2.c				\
			expand/handle_dollars_helper.c			\
			utils/delete_useless_spaces.c			\
			utils/delete_useless_spaces2.c			\
			utils/check_closed_quotes.c				\
			utils/ft_increase.c						\
			signal/signals.c						\

OBJS = $(SRCS:.c=.o)

INCLUDE = includes

NAME = minishell

LIBRARY = libft/libft.a\

LIBDIR = -C ./libft

MAKELIB = make $(LIBDIR)

CC = cc

FLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

LFLAGS = -lreadline

all : $(NAME)

bonus : $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(LIBRARY)
	$(CC) $(FLAGS) $(OBJS) $(LFLAGS) $(LIBRARY) -o $(NAME)

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
