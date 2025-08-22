/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/22 17:36:42 by jlaine-b         ###   ########.fr       */
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

typedef struct s_outfile
{
	char	*filename;
	int		append;
	int		fdout;
}				t_outfile;

typedef struct s_exec
{
	t_infile	infile;
	t_outfile	outfile;
	char		**cmdarg;
	char		*cmdpath;
	char		***envp;
}				t_exec;

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
t_arg		*extract_quote(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**append_tabs_and_free(char **tab1, char **tab2);
char		**blocisation(char *str, int *ex_code);
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
char		***full_tokenisation(char **b, int n);
t_exec		*extract_infos(char ***processes, int n, int *ex_code, char ***envp);
t_exec		extract_info(char **tokens, int *ex_code, char ***envp);
t_infile	find_infile(char **tokens, int *ex_code, char ***envp);
char		*str_without_quotes(char *str);
t_outfile	find_outfile(char **tokens, int *ex_code, char ***envp);
char		**find_cmdarg(char **tokens, int *ex_code, char ***envp);

/*EXECUTION*/

void		pipex(t_exec *infos, int n, char ***envp, int *status);
void		pipex2(int n, t_exec *infos, int pipe1[2], int pipe2[2], int saved_stdout, int saved_stdin, int *status);
void		execution(t_exec info, int piperead[2], int pipewrite[2], int i, char ***envp, int saved_stdin, int saved_stdout, int *status);
int			find_outfile_pipe(t_outfile outfile, int pipe[2], int i, int n);
int			find_fdin(t_infile infile, int pipe1[2], int i);

/*PARSING*/
char		*ft_iscmd(char *cmd, int *ex_code, char **envp);
int			parse_commands(t_exec *infos, int n, char ***envp, int *ex_code);

/*DELETE*/
void		delete_tempfiles(t_exec *infos, int n);
int			full_delete_minishell(t_exec *infos, int n);
void		free_tab_3d(char ***tab3);

char		**tab_without_quotes(char **tab);
int			third_verifications(char *str);
int			file_type(char *cmdi, char *simple_cmd);
int			judith(char *str, char ***envp, int *ex_code);
int			is_builtin(char *cmd);
void		exec_builtin(t_exec info, char ***envp, int *status);
//void		exec_builtin_exit(t_exec info, char ***envp, int *status);
char		**expand_dollar(char **tab, int *status, char **envp);
char		*ft_findpathforeachcommand(char **paths, char *cmd);
char		*expand_and_unquote(char *str, int ex_code, char **envp);

void		get_signal(void);

#endif
