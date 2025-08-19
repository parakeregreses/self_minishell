/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:41:42 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/19 19:57:44 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_dollar(char *str, int i)
{
	if (str[i] && ft_isnum(str[i]))
	{
		while (str[i] && ft_isnum(str[i]))
			i++;
	}
	else
	{
		while (str[i] && !ft_ischarinset(str[i], "\'\" "))
			i++;
	}
	return (i);
}

int	size_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '$')
		return (close_dollar(str, 0));
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i = close_quote(str + i, i, str[i]);
			i++;
			if (str[i] == 0)
				return (i);
		}
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (i);
}

t_arg	fill_line(t_arg tab, char *str, int *i)
{
	int	n;
	int	j;
	int	k;

	k = 0;
	j = *i;
	n = size_line(str + *i);
	*i = *i + n;
	tab.str = malloc(sizeof(char) * (n + 1));
	if (str[j] == '$')
	{
		tab.quote = 1;
		tab.str[k++] = str[j++];
		if (str[j] && ft_isnum(str[j]))
		{
			while (str[j] && ft_isnum(str[j]))
				tab.str[k++] = str[j++];
			tab.str[k] = 0;
			return (tab);
		}
		else
		{
			while (str[j] && !ft_ischarinset(str[j], "\'\" "))
				tab.str[k++] = str[j++];
			tab.str[k] = 0;
			return (tab);
		}
	}
	tab.quote = 0;
	while (str[j])
	{
		if (str[j] == '\'')
		{
			tab.str[k++] = str[j++];
			while (str[j] && str[j] != '\'')
				tab.str[k++] = str[j++];
			tab.str[k++] = str[j++];
		}
		if (str[j] == '$')
		{
			tab.str[k] = 0;
			return (tab);
		}
		tab.str[k++] = str[j++];
	}
	tab.str[k] = 0;
	return (tab);
}

static t_arg	*fill_tab(t_arg *tab, char *str, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != n)
	{
		tab[i] = fill_line(tab[i], str, &j);
		ft_printf("str[i] = %c\n", str[j]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

static int	n_lines(char *str)
{
	int	n;
	int	i;

	n = 0;
	if (str[0] != '$')
		n = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\'')
		{
			i = close_quote(str + i, i, str[i]);
			i++;
			if (str[i] == 0)
				return (n);
		}
		if (str[i] == '$')
		{
			n++;
			i++;
			i = close_dollar(str, i);
			if (str[i] == 0)
				return (n);
			n++;
		}
		i++;
	}
	return (n);
}

t_arg	*expand_and_unquote(char *str)
{
	int		n;
	t_arg	*tab;

	n = n_lines(str);
	ft_printf("n = %d\n", n);
	tab = malloc(sizeof(t_arg) * (n + 1));
	tab = fill_tab(tab, str, n);
	return (tab);
}

int	main(void)
{
	t_arg *tab = expand_and_unquote("$hello $les\"amis\"'$lol'");
	print_tab_arg(tab);
	free_tab_arg(tab);
}