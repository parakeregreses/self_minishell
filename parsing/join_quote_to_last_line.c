/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quote_to_last_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:17:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 11:22:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*join_quote_to_last_line(t_arg *tab, char *str1)
{
	char	*str2;
	int		n;

	n = tab_size_arg(tab);
	str2 = ft_strjoin((tab[n]).str, str1);
	free((tab[n]).str);
	(tab[n]).str = str2;
}