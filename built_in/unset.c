/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:04 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/27 16:47:59 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//char	**remove_vars_from_envp(char **envp, char **temp, char *var)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (envp[i])
//	{
//		if (!(ft_strncmp(var, envp[i], ft_strlen(envp[i])) == 0))
//		{
//			temp[j] = ft_strdup(envp[i]);
//			if (!temp[j])
//			{
//				while (j > 0)
//					free(temp[--j]);
//				free(temp);
//				return (NULL);
//			}
//			j++;
//		}
//		i++;
//	}
//	temp[j] = NULL;
//	return (temp);
//}

int	is_var_to_remove(char *envp_var, char **vars)
{
	int	i;
	int	len;

	i = 0;
	while (vars[i])
	{
		len = ft_strlen(vars[i]);
		if (ft_strncmp(vars[i], envp_var, len) == 0 &&
				(envp_var[len] == '=' || envp_var[len] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

char	**remove_vars_from_envp(char **envp, char **temp, char **vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!is_var_to_remove(envp[i], vars))
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

char	**cmd_unset(char ***envp, char **var_rm, int *status)
{
	int		env_number;
	char	**temp_envp;

	env_number = 0;
	if (!var_rm || !var_rm[0])
	{
		*status = 0;
		return (*envp);
	}
	while ((*envp)[env_number])
		env_number++;
	temp_envp = (char **)malloc(sizeof(char *) * (env_number + 1));
	if (!temp_envp)
	{
		*status = 1;
		return (*envp);
	}
	temp_envp = remove_vars_from_envp(*envp, temp_envp, var_rm);
	temp_envp = cmd_unset2(envp, status, temp_envp);
	return (temp_envp);
}

//int	main(void)
//{
//	char ***envp;
//	char **test;
//	int	*i;
//	char **vars;

//	envp = malloc(sizeof(char **));
//	i = malloc(sizeof(int));
//	test = ft_split("export TEST TEST1 TEST2", ' ');
//	vars = ft_split("bla ", ' ');
//	*envp = ft_split("bla bla1 bla2", ' ');
//	//cmd_export(envp, test, i, 1);
//	//print_tab_char(*envp);
//	//printf("\n");
//	//free_tab((void **)envp);
//	cmd_unset(envp, vars, i);
//	print_tab_char(*envp);
//	free_tab((void **)*envp);
//}
