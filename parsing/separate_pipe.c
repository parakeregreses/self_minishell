/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:35:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/20 22:13:54 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cut tab tail, line n included. Returns tab head
t_arg	*cut_tab_tail_arg(t_arg *tab, int n)
{
	int		i;
	int		size;
	t_arg	*new_tab;

	size = tab_size_arg(tab);
	if (n > size)
		return (NULL);
	i = 0;
	new_tab = malloc(sizeof(t_arg) * n);
	while (i < (n - 1))
	{
		(new_tab[i]).str = ft_strdup((tab[i]).str);
		(new_tab[i]).quote = (tab[i]).quote;
		i++;
	}
	(new_tab[i]).str = NULL;
	return (new_tab);
}

// cut tab head, line n included. Returns tab tail
t_arg	*cut_tab_head_arg(t_arg *tab, int n)
{
	int		i;
	int		size;
	t_arg	*new_tab;

	size = tab_size_arg(tab);
	if (n >= size)
		return (NULL);
	i = n + 1;
	new_tab = malloc(sizeof(t_arg) * (size - i + 1));
	while (i < size)
	{
		(new_tab[i - n - 1]).str = ft_strdup((tab[i]).str);
		(new_tab[i - n - 1]).quote = (tab[i]).quote;
		i++;
	}
	(new_tab[i - n - 1]).str = NULL;
	return (new_tab);
}

t_arg	*ft_quoteiszero(t_arg *tab)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
		(tab[i++]).quote = 0;
	return (tab);
}

int	is_pipe_left(int i, t_arg *arg)
{
	while ((arg[i]).str != NULL)
	{
		if ((arg[i]).quote == FALSE && ft_charinstr((arg[i]).str, '|') == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_arg	*ft_recollage(t_arg *arg, int *iad, t_arg *tab1, t_arg *tab2, t_arg *tab3, int pipe_ends_line, int pipe_starts_line)
{
	// int	pipe_ends_line;
	// int	pipe_starts_line;
	int	n;
	int i;

	i = *iad;
	n = tab_size_arg(arg);
	// pipe_ends_line = does_char_end_line((arg[i]).str, '|');
	// pipe_starts_line = does_char_start_line((arg[i]).str, '|');
	if (pipe_ends_line == FALSE && (i != n) && (arg[i + 1]).quote == 1)
	{
		tab2 = join_quote_to_last_line(tab2, (arg[i + 1]).str);
		tab3 = delete_line_in_tab_arg(tab3, 0);
	}
	if (pipe_starts_line == FALSE && (i != 0) && (arg[i - 1]).quote == 1)
	{
		i--;
		ft_printf("recollage ligne precedente : %s\n", (arg[i]).str);
		tab2 = join_quote_to_first_line(tab2, (arg[i]).str);
		tab1 = delete_line_in_tab_arg(tab1, i);
	}
	free_tab_arg(arg);
	arg = append_tabs_and_free_arg(tab1, tab2);
	arg = append_tabs_and_free_arg(arg, tab3);
	return (arg);
}

t_arg	*separate_pipe(t_arg *arg)
{
	int		n;
	int		i;
	t_arg	*tab1;
	t_arg	*tab2;
	t_arg	*tab3;
	int	pipe_ends_line;
	int	pipe_starts_line;

	n = tab_size_arg(arg);
	i = 0;
	while (i < n) //is_pipe_left(i, arg) == TRUE)
	{
		tab1 = cut_tab_tail_arg(arg, i + 1);
		tab3 = cut_tab_head_arg(arg, i);
		if ((arg[i]).quote == FALSE)
		{
			pipe_ends_line = does_char_end_line((arg[i]).str, '|');
			pipe_starts_line = does_char_start_line((arg[i]).str, '|');
			tab2 = ft_split_arg((arg[i]).str, '|');
			tab2 = ft_quoteiszero(tab2);
			arg = ft_recollage(arg, &i, tab1, tab2, tab3, pipe_ends_line, pipe_starts_line);
		}
		else
		{
			tab2 = malloc(sizeof(t_arg) * 2);
			tab2[0].str = ft_strdup((arg[i]).str);
			tab2[0].quote = TRUE;
			tab2[1].str = NULL;
			arg = ft_recollage(arg, &i, tab1, tab2, tab3, pipe_ends_line, TRUE);
			// free_tab_arg(arg);
			// arg = append_tabs_and_free_arg(tab1, tab2);
			// arg = append_tabs_and_free_arg(arg, tab3);
		}
		n = tab_size_arg(arg);
		i++;
		ft_printf("i = %d\ntab =\n", i);
		print_tab_arg(arg);
	}
		// arg = ft_recollage(arg, i, tab1, tab2, tab3);
			// pipe_ends_line = does_char_end_line((arg[i]).str, '|');
			// pipe_starts_line = does_char_start_line((arg[i]).str, '|');
			// if (pipe_ends_line == FALSE && (arg[i + 1]).quote == 1)
			// {
			// 	tab2 = join_quote_to_last_line(tab2, (arg[i + 1]).str);
			// 	tab3 = delete_line_in_tab_arg(tab3, 0);
			// }
			// if (pipe_starts_line == FALSE && (i != 0) && (arg[i - 1]).quote == 1)
			// {
			// 	// i--;
			// 	tab2 = join_quote_to_first_line(tab2, (arg[i]).str);
			// 	tab1 = delete_line_in_tab_arg(tab1, i);
			// }// else if (i != 0)
		// {
		// 	tab1 = cut_tab_tail_arg(arg, i);
		// 	tab2 = malloc(sizeof(t_arg) * 2);
		// 	tab2[0].str = ft_strdup((arg[i]).str);
		// 	tab2[1].str = NULL;
		// 	// tab2 = ft_split_arg((arg[i]).str, '|');
		// 	// tab2 = ft_quoteiszero(tab2);
		// 	tab3 = cut_tab_head_arg(arg, i);
		// 	arg = ft_recollage(arg, i - 1, tab1, tab2, tab3);
			// ft_printf("else i = %d\n", i);
			// pipe_ends_line = does_char_end_line((arg[i - 1]).str, '|');
			// if (pipe_ends_line == FALSE)
			// {
			// 	tab1 = cut_tab_tail_arg(arg, i);
			// 	tab2 = join_quote_to_last_line(tab2, (arg[i]).str);
			// 	tab3 = delete_line_in_tab_arg(tab3, 0);
			// 	// free_tab_arg(arg);
			// 	ft_printf("appends\n");
			// 	arg = append_tabs_and_free_arg(tab1, tab2);
			// 	ft_printf("appends2\n");
			// 	arg = append_tabs_and_free_arg(arg, tab3);
			// 	n = tab_size_arg(arg);
			// }
			// ft_printf("else : i = %d, arg[i] = %s\n", i, (arg[i]).str);
		// }
		// if ((arg[i]).quote == FALSE && ft_charinstr((arg[i]).str, '|') == FALSE)
		// 	i++;
		// if ((arg[i]).quote == TRUE)
		// 	i++;
		// else if ((arg[i]).quote == FALSE && i != n)
		// {
		// 	if ((arg[i + 1]).quote == 1)
		// 	{
		// 		tab2 = join_quote_to_last_line(tab2, (arg[i + 1]).str);
		// 		tab3 = delete_line_in_tab_arg(tab3, 0);
		// 	}
		// 	tab1 = arg;
		// 	free_tab_arg(arg);
		// 	arg = append_tabs_and_free_arg(tab1, tab2);
		// 	arg = append_tabs_and_free_arg(arg, tab3);
		// 	n = tab_size_arg(arg);
		// }
		// i++;
	return (arg);
}
