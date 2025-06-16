/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quote_to_last_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:17:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:11:59 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*join_quote_to_last_line(t_arg *tab, char *quote)
{
	char	*str2;
	int		n;

	n = tab_size_arg(tab);
	str2 = ft_strjoin((tab[n - 1]).str, quote);
	free((tab[n - 1]).str);
	(tab[n - 1]).str = str2;
	(tab[n - 1]).quote = 1;
	return (tab);
}

t_arg	*join_quote_to_first_line(t_arg *tab, char *quote)
{
	char	*str2;

	str2 = ft_strjoin(quote, (tab[0]).str);
	free((tab[0]).str);
	(tab[0]).str = str2;
	(tab[0]).quote = 1;
	return (tab);
}