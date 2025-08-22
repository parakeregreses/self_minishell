/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:21 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/22 16:14:36 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static bool	no_newline(char *str)
//{
//	int	i;

//	i = 2;
//	if (!str || str[0] != '-' || str[1] != 'n')
//		return (0);
//	while (str[i])
//	{
//		if (str[i] != 'n')
//			return (0);
//		i++;
//	}
//	return (1);
//}

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
	// ft_printf("\nargs = \n");
	// print_tab_char(args);
	// ft_printf("\n");
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

// int main()
// {
// 	char **args;

// 	args = malloc(sizeof(char *) * 3);
// 	args[0] = "echo";
// 	args[1] = "\"aspas\'\"";
// 	args[2] = NULL;
// 	cmd_echo(args);
// 	return (0);
// }

/* PRIS EN CHARGE:
• -n -nnnnn marchent (intended)
• -n-n --n sont considérés comme string (intended)
• -n après un premier string écrit sera considéré comme string
-nnnn aussi (intended)*/
