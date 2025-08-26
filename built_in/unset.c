/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:04 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/26 18:33:37 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remove_var_from_envp(char **envp, char **temp, char *var, int varlen)
{
	int	i;
	int	j;

	(void) varlen;
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(var, envp[i], ft_strlen(envp[i])) == 0))
		{
			temp[j] = ft_strdup(envp[i]);
			if (!temp[j])
			{
				while (j > 0)
					free(temp[--j]);
				free(temp);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	temp[j] = NULL;
	return (temp);
}

char	**cmd_unset2(char ***envp, int *status, char **temp_envp)
{
	if (!temp_envp)
	{
		*status = 1;
		return (*envp);
	}
	free_tab((void **) *envp);
	*envp = temp_envp;
	*status = 0;
	return (temp_envp);
}

char	**cmd_unset(char ***envp, char *var_rm, int *status)
{
	int		varlen;
	int		env_number;
	char	**temp_envp;

	varlen = 0;
	env_number = 0;
	varlen = 0;
	if (!var_rm)
	{
		*status = 0;
		return (*envp);
	}
	varlen = 0;
	while (var_rm[varlen])
		varlen++;
	while ((*envp)[env_number])
		env_number++;
	temp_envp = (char **)malloc(sizeof(char *) * (env_number + 1));
	if (!temp_envp)
	{
		*status = 1;
		return (*envp);
	}
	temp_envp = remove_var_from_envp(*envp, temp_envp, var_rm, varlen);
	return (cmd_unset2(envp, status, temp_envp));
}

//int	main(void)
//{
//	char ***envp;
//	char **test;
//	int	*i;

//	envp = malloc(sizeof(char **));
//	i = malloc(sizeof(int));
//	test = ft_split("export TEST TEST1 TEST2", ' ');
//	*envp = ft_split("bla bla1 bla2", ' ');
//	//cmd_export(envp, test, i, 1);
//	//print_tab_char(*envp);
//	//printf("\n");
//	//free_tab((void **)envp);
//	cmd_unset(envp, "bla", i);
//	print_tab_char(*envp);
//	free_tab((void **)*envp);
//}
