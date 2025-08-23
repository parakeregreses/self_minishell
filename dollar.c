/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:41:42 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 17:32:10 by jlaine-b         ###   ########.fr       */
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
	int	q;

	i = 0;
	q = 0;
	if (str[0] == '$')
		return (close_dollar(str, 1));
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
		{
			i = close_quote(str, i, str[i]);
			if (str[i] == 0)
				return (i);
		}
		if (str[i] && str[i] == '"')
			q = ft_bool(q);
		if (str[i] && str[i] == '$')
		{
			if (!str[i + 1])
				return (i + 1);
			if (!(q == 1 && str[i + 1] && ft_ischarinset(str[i + 1], "\" $")))
				return (i);
			else
				i++;
		}
		if (!str[i])
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
	int	q;

	k = 0;
	j = *i;
	q = 0;
	n = size_line(str + *i);
	*i = *i + n;
	tab.str = malloc(sizeof(char) * (n + 1));
	if (str[j] && str[j] == '$' && str[j + 1])
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
			while (str[j] && !ft_ischarinset(str[j], "\'\" $"))
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
			if (str[j])
				tab.str[k++] = str[j++];
		}
		if (str[j] && str[j] == '"')
			q = ft_bool(q);
		if (str[j] && str[j] == '$')
		{
			if (!str[j + 1])
			{
				tab.str[k++] = str[j];
				tab.str[k] = 0;
				return (tab);
			}
			if (!(q == 1 && str[j + 1] && ft_ischarinset(str[j + 1], "\" $")))
			{
				tab.str[k] = 0;
				return (tab);
			}
			else
				tab.str[k++] = str[j++];
		}
		if (str[j])
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
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

static int	n_lines(char *str)
{
	int		n;
	int		i;
	bool	q;

	n = 0;
	q = 0;
	if (str[0] != '$')
		n = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] && str[i] == '\'')
		{
			i = close_quote(str, i, str[i]);
			if (str[i] == 0)
				return (n);
		}
		if (str[i] && str[i] == '"')
			q = ft_bool(q);
		if (str[i] && str[i] == '$')
		{
			if (!str[i + 1])
				return (n);
			if (!(q == 1 && str[i + 1] && ft_ischarinset(str[i + 1], "\" $")))
			{
				n++;
				i++;
				i = close_dollar(str, i);
				if (str[i] == 0)
					return (n);
				n++;
			}
			else
				i++;
		}
		if (!str[i])
			return (n);
		i++;
	}
	return (n);
}

t_arg	*expand_tab(t_arg *tab, int status, char **envp)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
	{
		if (tab[i].quote == 1)
			tab[i].str = dollar_signs(tab[i].str, status, envp);
		i++;
	}
	return (tab);
}

int	str_without_quotes_len(char *str, char *c)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (str[j])
	{
		if (*c != 0)
		{
			while (str[j] && str[j] != *c)
			{
				len ++;
				j++;
			}
			if (str[j] == 0)
				return (len);
			j++;
			*c = 0;
		}
		while (str[j] && *c == 0)
		{
			while (str[j] && !ft_ischarinset(str[j], "'\""))
			{
				len++;
				j++;
			}
			if (!str[j])
				return (len);
			*c = str[j];
		}
		if (!str[j])
			return (len);
		j++;
	}
	return (len);
}

static int	ft_len(t_arg *tab)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	c = 0;
	while ((tab[i]).str != NULL)
	{
		if ((tab[i]).quote == 1)
			len = len + ft_strlen((tab[i]).str);
		else
			len = len + str_without_quotes_len((tab[i]).str, &c);
		i++;
	}
	return (len);
}

int	fill_str_without_quotes(char **str, int i, char *str2, char *c)
{
	int	j;

	j = 0;
	while (str2[j])
	{
		if (*c != 0)
		{
			while (str2[j] && str2[j] != *c)
				str[0][i++] = str2[j++];
			if (!str2[j])
			{
				str[0][i] = 0;
				return (i);
			}
			j++;
			*c = 0;
		}
		while (str2[j] && *c == 0)
		{
			while (str2[j] && !ft_ischarinset(str2[j], "'\""))
				str[0][i++] = str2[j++];
			if (!str2[j])
			{
				str[0][i] = 0;
				return (i);
			}
			*c = str2[j];
		}
		if (!str2[j])
		{
			str[0][i] = 0;
			return (i);
		}
		j++;
	}
	str[0][i] = 0;
	return (i);
}

static char	*fill_str(t_arg *tab, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*c;

	i = 0;
	j = 0;
	c = malloc(sizeof(char));
	*c = 0;
	while ((tab[i]).str != NULL)
	{
		if ((tab[i]).quote == 1)
		{
			k = 0;
			while ((tab[i]).str[k])
				str[j++] = (tab[i]).str[k++];
		}
		else
			j = fill_str_without_quotes(&str, j, (tab[i]).str, c);
		str[j] = 0;
		i++;
	}
	free(c);
	return (str);
}

char	*delete_quote(t_arg *tab)
{
	int		len;
	char	*str;

	len = ft_len(tab);
	str = malloc(sizeof(char) * (len + 1));
	str = fill_str(tab, str);
	free_tab_arg(tab);
	return (str);
}

char	*expand_and_unquote(char *str, int status, char **envp)
{
	int		n;
	t_arg	*tab;

	if (ft_strcmp(str, "$") == 0)
		return (ft_strdup(str));
	n = n_lines(str);
	tab = malloc(sizeof(t_arg) * (n + 1));
	tab = fill_tab(tab, str, n);
	tab = expand_tab(tab, status, envp);
	return (delete_quote(tab));
}
