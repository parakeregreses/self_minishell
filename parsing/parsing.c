/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 17:08:41 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*parsing_minishell(char *str);

t_arg	*select_quoted_str(char *str)
{
	t_arg	*tab1;
	t_arg	*tab2;
	int		n;
	char	separator;

	tab1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
	{
		separator = which_separator(str, '\'', '\"');
		tab1 = extract_str_in_str(str, find_segment(str, separator));
	}
	n = tab_size_arg(tab1);
	while (ft_charinstr((tab1[n - 1]).str, '\'') == TRUE || ft_charinstr((tab1[n - 1]).str, '\"') == TRUE)
	{
		tab2 = select_quoted_str((tab1[n - 1]).str);
		tab1 = append_tabs_and_free_arg(delete_line_in_tab_arg(tab1, n - 1), tab2);
		n = tab_size_arg(tab1);
	}
	return (tab1);
}

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
		i++;
	}
	(new_tab[i - n - 1]).str = NULL;
	return (new_tab);
}

t_arg	*separate_pipe(t_arg *arg)
{
	int		n;
	int		i;
	t_arg	*tab1;
	t_arg	*tab2;
	t_arg	*tab3;

	n = tab_size_arg(arg);
	tab1 = ft_split_arg((arg[0]).str, '|');
	arg = append_tabs_and_free_arg(tab1, delete_line_in_tab_arg(arg, 0));
	i = 0;
	print_tab_arg(arg);
	i = i + 2;
	while (i < n)
	{
		tab1 = cut_tab_tail_arg(arg, i);
		tab2 = ft_split_arg((arg[i]).str, '|');
		tab3 = cut_tab_head_arg(arg, i);
		free_tab_arg(arg);
		arg = append_tabs_and_free_arg(tab1, tab2);
		arg = append_tabs_and_free_arg(arg, tab3);
		// print_tab_char_arg(arg);
		i = i + 2;
	}
	return (arg);
}

t_arg	*parsing_minishell(char *str)
{
	t_arg *arg;

	arg = select_quoted_str(str);
	print_tab_arg(arg);
	ft_printf("on a separe les quotes\n");
	arg = separate_pipe(arg);
	return (arg);
}
