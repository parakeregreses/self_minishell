/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:52:56 by liulm             #+#    #+#             */
/*   Updated: 2025/08/28 20:14:27 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args && args[count])
		count++;
	return (count);
}

long	ft_atol(const char *nptr)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	numeric_argument_required(char **args, t_utils u)
{
	char	*line;

	line = ft_strjoin(args[1], ": numeric argument required\n");
	write(2, "minishell: exit: ", 17);
	write(2, line, ft_strlen(line));
	free(line);
	free_tab((void **)(*u.envp));
	*(u.status) = 255;
	exit(*(u.status));
}

void	cmd_exit(t_utils u, int pipe1[2], int pipe2[2], t_2d std)
{
	char	**args;
	int		count;
	long	exit_val;

	args = u.infos[u.i].cmdarg;
	count = count_args(args);
	ft_printf("exit\n");
	if (count == 1)
	{
		*(u.status) = 0;
		free_close_exit_final(u, pipe1, pipe2, std);
	}
	if (!is_numeric(args[1]))
		numeric_argument_required(args, u);
	if (count > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		*(u.status) = 1;
		return ;
	}
	exit_val = ft_atol(args[1]);
	*(u.status) = exit_val % 256;
	free_tab((void **)(*u.envp));
	exit(*(u.status));
}
