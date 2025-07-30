/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_empty_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:18:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/06 17:32:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_whitespaces(char *str)
{
	int	i;

	if (str == NULL)
		return (TRUE);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_iswhitespace(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_arg	*delete_empty_lines(t_arg *arg)
{
	int	i;

	if (arg == NULL)
		return (NULL);
	i = 0;
	while ((arg[i]).str != NULL)
	{
		if (is_only_whitespaces((arg[i]).str) == TRUE)
			arg = delete_line_in_tab_arg(arg, i);
		else
			i++;
	}
	return (arg);
}
