/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:08:04 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/15 17:08:02 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//char	**cmd_unset(char **envp, char *var_rm)
//{
//	int		i;
//	int		j;
//	int		varlen;
//	int		env_number;
//	char	**temp_envp;

//	i = 0;
//	j = 0;
//	env_number = 0;
//	varlen = ft_strlen(var_rm);
//	while (envp[env_number])
//		env_number++;
//	temp_envp = malloc(sizeof(char *) * (env_number + 1));
//	if (!temp_envp)
//		return (NULL);
//	while (envp[i])
//	{
//		if (ft_strncmp(var_rm, envp[i], varlen) == 0 && envp[i][varlen] == '=')
//			temp_envp[j++] = ft_strdup(envp[i]);
//		i++;
//	}
//	temp_envp[j] = NULL;
//	return (temp_envp);
//}

char	**remove_var_from_envp(char **envp, char **temp, char *var, int varlen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(var, envp[i], varlen) == 0 && envp[i][varlen] == '='))
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

char	**cmd_unset(char ***envp, char *var_rm)
{
	int		varlen;
	int		env_number;
	char	**temp_envp;

	print_tab_char(*envp);
	printf("\n\n\n\n");
	varlen = 0;
	env_number = 0;
	varlen = 0;
	if (!var_rm)
		return (NULL);
	varlen = 0;
	while (var_rm[varlen])
		varlen++;
	while ((*envp)[env_number])
		env_number++;
	temp_envp = (char **)malloc(sizeof(char *) * env_number);
	if (!temp_envp)
		return (NULL);
	temp_envp = remove_var_from_envp(*envp, temp_envp, var_rm, varlen);
	print_tab_char(temp_envp);
	return (temp_envp);
}

//int	main(int argc, char **argv, char **envp)
//{
//	int	i;
//	char **temp;

//	(void)argc;
//	(void)argv;
//	temp = ft_copy_env(envp);
//	i = 0;
//	temp =  ft_export(&temp, "TEST=0");
//	print_tab_char(temp);
//	printf("\n\n\n\n\n");
//	temp = cmd_unset(&temp, "TEST");
//	print_tab_char(temp);
//}
