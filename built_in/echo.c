/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:21 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/23 17:19:32 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	no_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' || str[i + 1] != 'n')
		return (0);
	i += 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

static char	*no_backslash(char *str)
{
	if (str && str[0] == '\\' && str[1])
		return (str + 1);
	return (str);
}

int	cmd_echo(char **args, int *status)
{
	int		i;
	bool	newline;

	i = 1;
	newline = 1;
	while (args[i] && no_newline(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		write(1, no_backslash(args[i]), ft_strlen(args[i]));
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	return (*status = 0);
}
