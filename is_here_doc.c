/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:15:37 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/18 12:45:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	double_chevron(t_arg *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == FALSE
			&& is_x_char_in_str((tab[i]).str, '<', 2) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_hd	is_here_doc(char *str, t_arg *tab, int n)
{
	t_hd	here_doc;
	int		i;

	i = 0;
	here_doc.hd = double_chevron(tab, n);
	if (here_doc.hd == FALSE)
	{
		here_doc.lim = NULL;
		return (here_doc);
	}

	here_doc.lim = str;

	return (here_doc);
}
