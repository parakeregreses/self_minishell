/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:04 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/13 15:11:25 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_unset(char **envp, char *var_rm)
{
	int		i;
	int		j;
	int		varlen;
	int		env_number;
	char	**temp_envp;

	i = 0;
	j = 0;
	env_number = 0;
	varlen = ft_strlen(var_rm);
	while (envp[env_number])
		env_number++;
	temp_envp = malloc(sizeof(char *) * (env_number + 1));
	if (!temp_envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(var_rm, envp[i], varlen) == 0 && envp[i][varlen] == '=')
			temp_envp[j++] = ft_strdup(envp[i]);
		i++;
	}
	temp_envp[j] = NULL;
	return (temp_envp);
}
