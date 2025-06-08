/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:11 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/08 12:33:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef struct s_segment
{
	int		start;
	int		end;
}			t_segment;

enum e_booleen
{
        FALSE=0,
        TRUE=1
};

int			tab_size(char **tab);
char		**delete_line_in_tab(char **tab, int i);
char		**extract_str_in_str(char *str, t_segment s);
t_segment	find_segment(char *str, char c);
char		**append_tabs_and_free(char **tab1, char **tab2);
char		**parsing_minishell(char *str);
char		which_separator(char *s, char c1, char c2);
char		**cut_tab_tail(char **tab, int n);
char		**cut_tab_head(char **tab, int n);
#endif