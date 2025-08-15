/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/15 21:07:04 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <sys/stat.h>
# include "minishell2.h"

typedef struct s_arg
{
	char	*str;
	int		quote;
}			t_arg;

typedef struct s_triple_t_arg
{
	t_arg	*arg;
	t_arg	*tab1;
	t_arg	*tab3;
}			t_tri_arg;

typedef struct s_infile
{
	char	*filename;
	char	*tempfilename;
	int		here_doc;
}				t_infile;

typedef struct s_exec
{
	t_infile	infile;
	int			fdout;
	char		**cmdarg;
	char		*cmdpath;
	char		***envp;
}				t_exec;

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
t_arg		*extract_quote(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**append_tabs_and_free(char **tab1, char **tab2);
char		**blocisation(char *str);
char		which_separator(char *s, char c1, char c2);
t_arg		*cut_tab_tail_arg(t_arg	*tab, int n);
t_arg		*cut_tab_head_arg(t_arg *tab, int n);
t_arg		*free_tab_arg(t_arg *tab);
int			tab_size_arg(t_arg *tab);
t_arg		*delete_line_in_tab_arg(t_arg *old_tab, int i);
t_arg		*append_tabs_and_free_arg(t_arg *tab1, t_arg *tab2);
void		print_tab_arg(t_arg *text);
t_arg		*ft_split_arg(char const *s, char c);
int			first_verifications(char *str);
t_arg		*alloc_tab(int len, t_segment s);
t_arg		*fill_tab_blocs(t_arg *tab, char *str, t_segment s, int len);
t_arg		*select_quoted_str(char *str);
t_arg		*separate_pipe(t_arg *arg);
t_arg		*join_quote_to_last_line(t_arg *tab, char *quote);
t_arg		*join_quote_to_first_line(t_arg *tab, char *quote);
int			is_infile(char *file1);
t_arg		*delete_empty_lines(t_arg *arg);
char		*here_doc(char *lim);
char		*delete_useless_spaces(char	*str, char *set);
char		*delete_useless_spaces_fill(char *str, char *new_str, char *set);
char		**token_bloc(char *str, char *set);
char		*remove_whitespaces(char *str);
char		*revamp_str(char *str);
int			second_verifications(t_arg *tab);
int			triple_char(t_arg *tab, int n, char c);
int			check_closed_quotes(char *arg);
char		***full_tokenisation(char **blocs, int n, int *status, char ***envp);
t_exec		*extract_infos(char ***processes, int n);
t_exec		extract_info(char **tokens);
t_infile	find_infile(char **tokens);
char		*str_without_quotes(char *str);
int			find_fdout(char **tokens);
char		**find_cmdarg(char **tokens);
void		pipex(t_exec *infos, int n, char ***envp, int *status);
void		execution(t_exec info, int piperead[2], int pipewrite[2], int i, char ***envp, int saved_stdin, int saved_stdout);
char		*ft_iscmd(char *cmd, char **envp);
int			parse_commands(t_exec *infos, int n, char ***envp);
void		delete_tempfiles(t_exec *infos, int n);
int			full_delete_minishell(char **b, char ***p, t_exec *infos, int n);
int			find_fdin(t_infile infile, int pipe1[2], int i);
char		**tab_without_quotes(char **tab);
int			third_verifications(char *str);
int			file_type(char *cmdi, char *simple_cmd);
int			judith(char *str, char ***envp, int *status);
int			is_builtin(char *cmd);
void		exec_builtin(t_exec info, char ***envp);
void		exec_builtin_exit(t_exec info, char ***envp);
char		**expand_dollar(char **tab, int *status, char **envp);

void		get_signal(void);

#endif