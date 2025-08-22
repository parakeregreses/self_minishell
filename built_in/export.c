/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/21 16:37:42 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/26 17:33:22 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	need_to_replace_var(char **envp, char *env_variable)
{
	int		i;
	size_t	len;
	size_t	j;

	len = 0;
	while (env_variable[len] && env_variable[len] != '=')
		len++;
	i = 0;
	while (envp && envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (ft_strncmp(envp[i], env_variable, len) == 0 && j == len)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_replace_export_if_found(char **export_list, char *env_variable)
{
	int		i;
	size_t	len;
	size_t	j;

	len = 0;
	while (env_variable[len] && env_variable[len] != '=')
		len++;
	i = 0;
	while (export_list && export_list[i])
	{
		j = 0;
		while (export_list[i][j] && export_list[i][j] != '=')
			j++;
		if (ft_strncmp(export_list[i], env_variable, len) == 0 && j == len)
		{
			if (ft_strchr(env_variable, '='))
			{
				free(export_list[i]);
				export_list[i] = ft_strdup(env_variable);
			}
			return (export_list);
		}
		i++;
	}
	return (ft_create_env(export_list, env_variable));
}

char	**export_alphabetical_order(char **envp)
{
	int		count;
	int		i;
	char	**result;

	count = 0;
	while (envp && envp[count])
		count++;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = ft_strdup(envp[i]);
		i++;
	}
	result[i] = NULL;
	swap_variables(result, count);
	return (result);
}

//char	**ft_add_in_export(char **envp, char *new_env_variable)
//{
//	int		i;
//	int		j;
//	char	**new_export;

//	i = 0;
//	if (!new_env_variable || !new_env_variable[0])
//		return (envp);
//	if (need_to_replace_var(envp, new_env_variable))
//	{
//		new_export = ft_replace_export_if_found(envp, new_env_variable);
//		return (new_export);
//	}
//	while (envp && envp[i])
//		i++;
//	new_export = malloc(sizeof(char *) * (i + 2));
//	if (!new_export)
//		return (envp);
//	j = 0;
//	while (j < i)
//	{
//		new_export[j] = ft_strdup(envp[j]);
//		j++;
//	}
//	new_export[j] = ft_strdup(new_env_variable);
//	new_export[j + 1] = NULL;
//	return (new_export);
//}

char	**ft_add_in_export(char **envp, char *new_env_variable)
{
	char	**new_export;

	if (!new_env_variable || !new_env_variable[0])
		return (envp);
	new_export = ft_replace_export_if_found(envp, new_env_variable);
	return (new_export);
}

char	**cmd_export(char ***envp, char *new_env_variable, int *status)
{
	char	**new_env;

	if (env_var_checker(*envp, new_env_variable) == 1)
	{
		*status = 1;
		return (NULL);
	}
	new_env = ft_add_in_export(*envp, new_env_variable);
	if (new_env != *envp)
	{
		//*status = 1;
		free_tab((void **)*envp);
		*envp = new_env;
	}
	*status = 0;
	return (*envp);
}
