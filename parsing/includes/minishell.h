/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/18 10:31:51 by jlaine-b         ###   ########.fr       */
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

typedef struct s_arg
{
	char	*str;
	int		quote;
}			t_arg;

typedef struct s_exec
{
	int		fdin;
	int		fdout;
	char	**cmd;
}				t_exec;

typedef struct s_coord2d
{
	int	x;
	int	y;
}				t_coord2d;

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
t_arg		*extract_quote(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**append_tabs_and_free(char **tab1, char **tab2);
t_arg		*parsing_minishell(char *str);
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
t_arg		*fill_tab(t_arg *tab, char *str, t_segment s, int len);
t_arg		*select_quoted_str(char *str);
t_arg		*separate_pipe(t_arg *arg);
t_arg		*join_quote_to_last_line(t_arg *tab, char *quote);
t_arg		*join_quote_to_first_line(t_arg *tab, char *quote);
int			is_infile(char *file1);
t_exec		parse_bloc(char *str);
int			define_fdin(t_coord2d pos, t_arg *tab);
int			parse_fdin(t_arg *str);
char		*reglue_quoted(t_arg *tab);

#endif