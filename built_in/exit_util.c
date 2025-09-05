/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:44:50 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 20:28:19 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	directory_deleted(char ***envp, char *old_pwd, int *status)
{
	char	tmp[PATH_MAX];

	if (!getcwd(tmp, PATH_MAX))
	{
		old_pwd = ft_getenv("OLDPWD", *envp);
		if (!old_pwd || chdir(old_pwd) != 0)
		{
			perror("cd");
			old_pwd = ft_getenv("HOME", *envp);
			if (!old_pwd || chdir(old_pwd) != 0)
			{
				perror("cd");
				*status = 1;
				return (0);
			}
			return (1);
		}
		if (copy_old_pwd(old_pwd))
			return (0);
		if (update_env(envp, old_pwd))
			return (0);
		*status = 0;
		return (1);
	}
	return (0);
}

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

void	numeric_argument_required(char **args)
{
	char	*line;

	line = ft_strjoin(args[1], ": numeric argument required\n");
	write(2, "minishell: exit: ", 17);
	write(2, line, ft_strlen(line));
	free(line);
}
