/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_quoted_together.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:46:31 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/20 22:04:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*put_quoted_together(t_arg *arg)
{
	int 	i;
	int		n;
	char	*str2;

	i = 0;
	n = tab_size_arg(arg);
	while (i < n - 1)
	{
		if ((arg[i]).quote == TRUE && (arg[i + 1]).quote == TRUE)
		{
			str2 = ft_strdup((arg[i + 1]).str);
			(arg[i]).str = ft_strjoinfree((arg[i]).str, str2);
			arg = delete_line_in_tab_arg(arg, i + 1);
			n = tab_size_arg(arg);
		}
		else
			i++;
	}
	return (arg);
}