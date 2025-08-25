/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/25 18:26:47 by liulm            ###   ########.fr       */
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
# include <termios.h>
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

typedef struct s_utils
{
	t_exec	*infos;
	int		n;
	int		*status;
	char	***envp;
	int		i;
}			t_utils;

typedef struct s_pipes
{
	int	pipe1[2];
	int	pipe2[2];
}		t_pipes;

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
t_arg		*extract_quote(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**append_tabs_and_free(char **tab1, char **tab2);
char		**blocisation(char *str, int *status);
char		which_separator(char *s, char c1, char c2);
t_arg		*free_tab_arg(t_arg *tab);
int			tab_size_arg(t_arg *tab);
t_arg		*delete_line_in_tab_arg(t_arg *old_tab, int i);
t_arg		*append_tabs_and_free_arg(t_arg *tab1, t_arg *tab2);
void		print_tab_arg(t_arg *text);
int			first_verifications(char *str);
t_arg		*alloc_tab(int len, t_segment s);
t_arg		*fill_tab_blocs(t_arg *tab, char *str, t_segment s, int len);
t_arg		*select_quoted_str(char *str);
t_arg		*join_quote_to_last_line(t_arg *tab, char *quote);
t_arg		*join_quote_to_first_line(t_arg *tab, char *quote);
int			is_infile(char *file1);
char		**delete_empty_lines(char **tab);
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

/*EXTRACTION*/

t_exec		*extract_infos(char ***processes, int n, int *status, char ***envp);
t_exec		extract_info(char **tokens, int *status, char ***envp);
t_exec		find_in_out_file(char **tokens, int *ex_code,
				char ***envp, t_exec info);
char		*str_without_quotes(char *str);
t_outfile	find_outfile(char *token, int *status, char ***envp,
				t_outfile outfile);
char		**find_cmdarg(char **tokens, int *status, char ***envp);

/*EXECUTION*/

t_utils		initutils(t_exec *infos, int n, char ***envp, int *status);
t_2d		initstd(void);
t_pipes		initpipes(void);
void		pipex(t_exec *infos, int n, char ***envp, int *status);
void		pipex2(t_utils u, t_pipes p, t_2d std);
void		execution(t_utils u, int piperead[2], int pipewrite[2], t_2d std);
int			find_outfile_pipe(t_utils u, int pipe[2]);
int			find_fdin(t_infile infile, int pipe1[2], int i);
void		cmd_exit(t_utils u, int pipe1[2], int pipe2[2], t_2d std);
void		free_close_exit_final(t_utils u, int pipe1[2],
				int pipe2[2], t_2d std);
void		exec_builtin(t_utils u, int pipe1[2], int pipe2[2], t_2d std);
void		close_pipes(int pipe1[2], int pipe2[2]);
void		retrieve_std(int saved_stdin, int saved_stdout);

/*PARSING*/
char		*ft_iscmd(char *cmd, int *status, char **envp);
int			directory(char *cmd, int *status);
int			parse_commands(t_exec *infos, int n, char ***envp, int *status);

/*DELETE*/
void		delete_tempfiles(t_exec *infos, int n);
int			full_delete_minishell(t_exec *infos, int n);
void		free_tab_3d(char ***tab3);

char		**tab_without_quotes(char **tab);
int			third_verifications(char *str);
int			file_type(char *cmdi, char *simple_cmd);
int			command(char *str, char ***envp, int *status);
int			is_builtin(char *cmd);
char		**expand_dollar(char **tab, int *status, char **envp);
char		*ft_findpathforeachcommand(char **paths, char *cmd, int *status);

/*EXPAND*/
char		*expand(char *str, int status, char **envp);
t_arg		*fill_tab_expand(t_arg *tab, char *str, int n);
t_arg		*expand_tab(t_arg *tab, int status, char **envp);
int			close_dollar(char *str, int i);
char		*delete_quote(t_arg *tab);
int			ft_len_delete_quote(t_arg *tab);
void		ft_increase(int *i, int *len);
t_arg		fill_line2_dollar(t_arg tab, char *str, int j);
t_arg		fill_line1(t_arg tab, char *str, int j);
int			size_line(char *str);
int			copy_var_value(char *dst, char *var_name, char **envp);

void		get_signal(int SA, int here_doc);

#endif
