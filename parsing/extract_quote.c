/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/10 17:16:38 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//returns a tab with line 0 = before str, line 1 = str, line2 = after str
t_arg	*extract_quote(char *str, t_segment s)
{
	t_arg	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tab = alloc_tab(len, s);
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(tab, str, s, len);
	// while (i < s.start)
	// {
	// 	(tab[0]).str[i] = str[i];
	// 	i++;
	// }
	// (tab[0]).str[i++] = 0;
	// (tab[0]).quote = 0;
	// ft_printf("firstline\n");
	// while (i < s.end)
	// {
	// 	(tab[1]).str[i - s.start - 1] = str[i];
	// 	i++;
	// }
	// (tab[1]).str[i - s.start - 1] = 0;
	// (tab[1]).quote = 1;
	// i++;
	// ft_printf("secondline\n");
	// while (i < len)
	// {
	// 	(tab[2]).str[i - s.end - 1] = str[i];
	// 	i++;
	// }
	// (tab[2]).str[i - s.end - 1] = 0;
	// (tab[2]).quote = 0;
	// ft_printf("quote extracted\n");
	return (tab);
}
