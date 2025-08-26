/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revamp_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:30:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/26 14:25:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	double_chevron_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i = close_quote(str, i, str[i]);
		if ((str[i] == '<' || str[i] == '>') && str[i + 1] && str[i + 1] == ' ' && str[i + 2] && str[i + 2] == str[i])
			return (str[i]);
		i++;
	}
	return (0);
}

char	*revamp_str(char *str, int *status)
{
	char	c;
	str = ft_strtrim(str, " ");
	c = double_chevron_error(str);
	if (c != 0)
	{
		free(str);
		ft_printf("minishell: syntax error near unexpected token `%c'\n", c);
		*status = 2;
		return (NULL);
	}
	str = delete_useless_spaces(str, "<>|");
	return (str);
}
