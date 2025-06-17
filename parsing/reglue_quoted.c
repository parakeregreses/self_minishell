/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reglue_quoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:13:23 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/17 12:54:35 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*fill_str(char *str, t_arg *tab, int len)
{
	int		n;
	int		i;
	int		j;
	char	*src;
	char	*set;

	set = malloc(sizeof(char) * 2);
	set[1] = 0;
	n = tab_size_arg(tab);
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((tab[i]).quote == 1)
		{
			set[0] = (tab[i]).str[0];
			src = ft_strtrim((tab[i]).str, set);
			ft_memcpy(str + j, src, ft_strlen(src));
			j = j + ft_strlen(src);
			free(src);
		}
		else
		{
			ft_memcpy(str + j, (tab[i]).str, ft_strlen((tab[i]).str));
			j = j + ft_strlen((tab[i]).str);
		}
		i++;
	}
	str[len] = 0;
	free(set);
	return (str);
}

static int	len_str(t_arg *tab)
{
	int		len;
	int		n;
	int		i;

	n = tab_size_arg(tab);
	i = 0;
	len = 0;
	while (i < n)
	{
		if ((tab[i]).quote == 1)
			len = len + strlen((tab[i++]).str) - 2;
		else
			len = len + strlen((tab[i++]).str);
	}
	return (len);
}

char	*reglue_quoted(t_arg *tab)
{
	char	*str;
	int		len;

	len = len_str(tab);
	ft_printf("len = %d\n", len);
	str = malloc(sizeof(char) * len + 1);
	str = fill_str(str, tab, len);
	return (str);
}