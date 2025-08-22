/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:43:00 by liulm             #+#    #+#             */
/*   Updated: 2025/08/22 17:27:12 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envp(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_variables(char **result, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (count - 1))
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(result[j], result[j + 1]) > 0)
				swap_str(&result[j], &result[j + 1]);
			j++;
		}
		i++;
	}
}

int	no_envar(char **temp_envp)
{
	int	i;

	i = 0;
	temp_envp = export_alphabetical_order(temp_envp);
	while (temp_envp[i])
		ft_print_export(temp_envp[i++]);
	free_tab((void **)temp_envp);
	return (0);
}

int	env_var_checker(char **envp, char *envvar)
{
	int		i;
	char	**temp_envp;

	temp_envp = envp;
	if (!envvar)
		return (no_envar(temp_envp));
	if (ft_isdigit(envvar[0]) || (!ft_isalpha(envvar[0]) && envvar[0] != '_'))
	{
		printf("export: '%s': not a valid identifier\n", envvar);
		return (1);
	}
	i = 0;
	while (envvar[i] && envvar[i] != '=')
	{
		if (!ft_isalnum(envvar[i]) && envvar[i] != '_')
		{
			printf("export: '%s': not a valid identifier\n", envvar);
			return (1);
		}
		i++;
	}
	return (0);
}
