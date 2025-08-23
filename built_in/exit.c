/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:52:56 by liulm             #+#    #+#             */
/*   Updated: 2025/08/23 17:09:34 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric(const char *str)
{
	int	i = 0;

	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int count_args(char **args)
{
	int	count = 0;

	while (args && args[count])
		count++;
	return count;
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

void	cmd_exit(char **args, char ***envp, int *status, int ok, t_exec *infos, int n)
{
	int	count = count_args(args);
	long	exit_val;
	char	*line;

	(void)ok;
	(void)*infos;
	(void)n;
	printf("exit\n");
	if (count == 1)
	{
		free_tab((void **)*envp);
		*status = 0;
		if (ok)
			exit(*status);
	}
	if (!is_numeric(args[1]))
	{
		line = ft_strjoin(args[1], ": numeric argument required\n");
		write(2, "minishell: exit: ", 17);
		write(2, line, ft_strlen(line));
		free(line);
		free_tab((void **)*envp);
		*status = 2;
		if (ok)
			exit(*status);
	}
	if (count > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		*status = 1;
		return ;
	}
	exit_val = ft_atol(args[1]);
	*status = exit_val % 256;
	free_tab((void **)*envp);
	//free(status);
	if (ok)
		exit(*status);
}
