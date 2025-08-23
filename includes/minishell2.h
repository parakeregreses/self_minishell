/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   minishell.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/02 16:35:36 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/21 18:32:35 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef MINISHELL2_H
# define MINISHELL2_H

# include "libft.h"
# include <unistd.h>
# include <stddef.h>
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096 /* max length of a path */
# endif

# define TRUE 1
# define FALSE 0

extern bool	g_finished;
// typedef struct s_mini
// {

// }		t_mini;

/* ======================== MINISHELL ========================== */

int		launching(char ***envp, int *status);
char	*cat_current_dir(void);

/* =================== ENVIRONMENT VARIABLES =================== */

char	**cmd_unset(char ***envp, char *var_rm, int *status);
char	**cmd_export(char ***envp, char *new_env_variable, int *status);
char	**ft_copy_env(char **envp);
char	**ft_free_envp(int i, char **envp);
char	**export_alphabetical_order(char **envp);
char	**ft_add_in_env(char **envp, char *new_env_variable);
char	**ft_create_env(char **envp, char *new_env_variable);
char	**ft_replace_env_if_found(char **envp, char *env_variable);
void	ft_print_export(char *env);
void	cmd_env(char **envp, int *status);
void	swap_str(char **a, char **b);
void	swap_variables(char **result, int count);
int		env_var_checker(char **envp, char *env_variable);
void	free_envp(char **envp);
char	*replace_dollar_mark(char *str, int var);
char	*replace_dollar_var(char *str, char **envp);
char	*dollar_signs(char *str, int var, char **envp);
int		get_final_length(char *str, char **envp);
int		var_name_len(char *str);
char	*check_env_value(char *str, char **envp);

/* ============================ CD ============================ */

int		cmd_cd(char **arg, char ***envp, int *status);

/* =========================== ECHO =========================== */

char	*str_without_quotes(char *str);
int		cmd_echo(char **args, int *status);

/* =========================== PWD ============================ */

void	cmd_pwd(char **envp, int *status);

/* =========================== EXIT ============================ */

// void	cmd_exit(char **args, char ***envp, int *status, int ok, t_exec *infos, int n);

/* ============================================================ */

#endif
