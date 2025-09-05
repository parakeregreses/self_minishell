/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/09/05 20:29:00 by liulm            ###   ########.fr       */
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
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

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
	int		fdin;
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

extern int	g_finished;

/* ======================== MINISHELL ========================== */

int			launching(char ***envp, int *status);
char		*cat_current_dir(void);

/* ========================= SIGNALS =========================== */

void		disable_sigquit(int i);
void		disable_sigint(void);
void		signal_handler_heredoc(int signal);
void		get_signal(int SA, int here_doc);

/* ====================== VERIFICATIONS ======================== */

int			first_verifications(char *str);
char		*delete_useless_spaces(char	*str, char *set);
char		*delete_useless_spaces_fill(char *str, char *new_str, char *set);
char		*revamp_str(char *str, int *status);
int			second_verifications(t_arg *tab);
int			triple_char(t_arg *tab, int n, char c);
int			double_char(t_arg *tab, int n, char c);
int			check_closed_quotes(char *arg);
char		*remove_whitespaces(char *str);
int			third_verifications(char *str);

/* =================== ENVIRONMENT VARIABLES =================== */

char		**cmd_unset(char ***envp, char **var_rm, int *status);
char		**cmd_export(char ***envp, char **new_env_variable,
				int *status, int ok);
char		**ft_copy_env(char **envp);
char		**ft_free_envp(int i, char **envp);
char		**export_alphabetical_order(char **envp);
char		**ft_add_in_env(char **envp, char *new_env_variable);
char		**ft_create_env(char **envp, char *new_env_variable);
char		**ft_replace_env_if_found(char **envp, char *env_variable);
void		ft_print_export(char *env);
void		cmd_env(char **envp, int *status);
void		swap_str(char **a, char **b);
void		swap_variables(char **result, int count);
int			env_var_checker(char *env_variable);
char		*ft_getenv(const char *name, char **envp);
int			no_envar(char **temp_envp);
char		**update_path(char ***envp, int *status);
char		**update_shlvl(char ***envp, int *status);

/* ============================ CD ============================ */

int			cmd_cd(char **arg, char ***envp, int *status);
int			directory_deleted(char ***envp, char *old_pwd, int *status);

/* =========================== ECHO =========================== */

char		*str_without_quotes(char *str);
int			cmd_echo(char **args, int *status);

/* =========================== PWD ============================ */

int			copy_old_pwd(char *old_pwd);
void		cmd_pwd(int *status);

/* ======================== TAB UTILS ========================= */

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
char		**append_tabs_and_free(char **tab1, char **tab2);
t_arg		*free_tab_arg(t_arg *tab);
int			tab_size_arg(t_arg *tab);
t_arg		*delete_line_in_tab_arg(t_arg *old_tab, int i);
t_arg		*append_tabs_and_free_arg(t_arg *tab1, t_arg *tab2);
t_arg		*alloc_tab(int len, t_segment s);
t_arg		*fill_tab_blocs(t_arg *tab, char *str, t_segment s, int len);
t_arg		*select_quoted_str(char *str);
char		**tab_without_quotes(char **tab);
char		**delete_empty_lines(char **tab);

/* ======================= BLOCISATION ======================== */

t_arg		*extract_quote(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**blocisation(char *str, int *status, char ***envp);
char		which_separator(char *s, char c1, char c2);

/* ====================== EXTERN FILES ======================= */

int			is_file_rok(char *file1);
int			is_file_xok(char *file1, int *status);
char		*here_doc(char *lim);
int			find_outfile_pipe(t_utils u, int pipe[2]);
int			find_fdin(t_infile infile, int pipe1[2], int i);

/* ====================== TOKENISATION ======================= */

char		**token_bloc(char *str, char *set);
char		***full_tokenisation(char **b, int n);

/* ======================== EXTRACTION ======================== */

t_exec		*extract_infos(char ***processes, int n, int *status, char ***envp);
t_exec		extract_info(char **tokens, int *status, char ***envp);
t_exec		find_in_out_file(char **tokens, int *ex_code,
				char ***envp, t_exec info);
char		*str_without_quotes(char *str);
t_outfile	find_outfile(char *token, int *status, char ***envp,
				t_outfile outfile);
char		**find_cmdarg(char **tokens, int *status, char ***envp);

/* ========================= EXECUTION ========================= */

t_utils		initutils(t_exec *infos, int n, char ***envp, int *status);
t_2d		initstd(void);
t_pipes		initpipes(void);
void		pipex(t_exec *infos, int n, char ***envp, int *status);
void		pipex2(t_utils u, t_pipes p, t_2d std, pid_t pid);
void		pipex3(t_pipes p, t_2d std);
int			execution(t_utils u, int piperead[2], int pipewrite[2], t_2d std);
void		exec_builtin(t_utils u, int pipe1[2], int pipe2[2], t_2d std);
void		close_pipes(int pipe1[2], int pipe2[2]);
void		retrieve_std(int saved_stdin, int saved_stdout);
void		builtin(t_utils u, int piperead[2], int pipewrite[2], t_2d std);
void		double_close(int fd1, int fd2);
int			is_builtin(char *cmd);
char		**expand_dollar(char **tab, int *status, char **envp);
char		*ft_findpathforeachcommand(char **paths, char *cmd, int *status);

/* ============================ EXIT ============================ */

void		cmd_exit(t_utils u, int pipe1[2], int pipe2[2], t_2d std);
void		cmd_exit2(int count, int *status, char **args, t_utils u);
void		numeric_argument_required(char **args);
long		ft_atol(const char *nptr);
int			count_args(char **args);
int			is_numeric(const char *str);

/* =========================== PARSING =========================== */

char		*ft_iscmd(char *cmd, int *status, char **envp);
int			directory(char *cmd, int *status);
int			parse_commands(t_exec *infos, int n, char ***envp, int *status);
char		*cmd_not_found(char *cmd);
int			not_directory(char *cmdi, char *simple_cmd);
int			not_directory_nomsg(char *cmd);
int			command(char *str, char ***envp, int *status);

/* =========================== DELETE =========================== */
void		delete_tempfiles(t_exec *infos, int n);
int			full_delete_minishell(t_exec *infos, int n);
void		free_tab_3d(char ***tab3);

/* =========================== EXPAND =========================== */

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
char		*replace_dollar_mark(char *str, int var);
char		*replace_dollar_var(char *str, char **envp);
char		*dollar_signs(char *str, int var, char **envp);
void		dollar_helper(char *res, char *str, char *var);
int			get_final_length(char *str, char **envp, int i, int len);
int			var_name_len(char *str);
char		*check_env_value(char *str, char **envp);

#endif
