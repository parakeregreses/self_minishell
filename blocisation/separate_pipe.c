/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:35:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/07 12:09:57 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*ft_recollage(t_tri_arg tri, t_arg *tab2, int *iad, t_2d pipe_pos)
{
	int	n;
	int	i;

	i = *iad;
	n = tab_size_arg(tri.arg);
	if (pipe_pos.x == FALSE && (i != (n - 1)) && (tri.arg[i + 1]).quote == 1)
	{
		tab2 = join_quote_to_last_line(tab2, (tri.arg[i + 1]).str);
		tri.tab3 = delete_line_in_tab_arg(tri.tab3, 0);
	}
	if (pipe_pos.y == FALSE && (i != 0) && (tri.arg[i - 1]).quote == 1)
	{
		i--;
		tab2 = join_quote_to_first_line(tab2, (tri.arg[i]).str);
		tri.tab1 = delete_line_in_tab_arg(tri.tab1, i);
	}
	free_tab_arg(tri.arg);
	tri.arg = append_tabs_and_free_arg(tri.tab1, tab2);
	tri.arg = append_tabs_and_free_arg(tri.arg, tri.tab3);
	return (tri.arg);
}

t_arg	*no_quote(t_tri_arg triple, int i, char *pipestr)
{
	t_2d	pipe_pos;
	t_arg	*tab2;
	int		n;
	char	*line;

	pipe_pos.x = does_char_end_line((triple.arg[i]).str, '|');
	pipe_pos.y = does_char_start_line((triple.arg[i]).str, '|');
	tab2 = ft_split_arg((triple.arg[i]).str, '|');
	if (pipe_pos.x == 1)
	{
		n = tab_size_arg(tab2);
		if (n > 0)
		{
			line = (tab2[n - 1]).str;
			(tab2[n - 1]).str = ft_strjoin(line, pipestr);
			free(line);
		}
	}
	tab2 = ft_quoteiszero(tab2);
	triple.arg = ft_recollage(triple, tab2, &i, pipe_pos);
	return (triple.arg);
}

t_arg	*quoted(t_tri_arg triple, int i)
{
	t_arg	*tab2;
	t_2d	pipe_pos;

	pipe_pos.x = 0;
	pipe_pos.y = 1;
	tab2 = malloc(sizeof(t_arg) * 2);
	tab2[0].str = ft_strdup((triple.arg[i]).str);
	tab2[0].quote = TRUE;
	tab2[1].str = NULL;
	tab2[1].quote = 0;
	triple.arg = ft_recollage(triple, tab2, &i, pipe_pos);
	return (triple.arg);
}

// in unquoted lines, split according to the pipe characters.
// will then reput the quoted segment next to the correct blocs.
t_arg	*separate_pipe(t_arg *arg)
{
	int				n;
	int				i;
	t_tri_arg		triple;
	char			*pipestr;

	pipestr = ft_strdup("|");
	n = tab_size_arg(arg);
	i = 0;
	while (i < n)
	{
		triple.tab1 = cut_tab_tail_arg(arg, i + 1);
		triple.tab3 = cut_tab_head_arg(arg, i);
		triple.arg = arg;
		if ((arg[i]).quote == FALSE)
			arg = no_quote(triple, i, pipestr);
		else
			arg = quoted(triple, i);
		n = tab_size_arg(arg);
		i++;
	}
	free(pipestr);
	return (arg);
}
