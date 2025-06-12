/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/12 14:16:22 by jlaine-b         ###   ########.fr       */
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
	return (tab);
}
