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

void	ft_print_export(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
	{
		printf("declare -x %.*s=\"%s\"\n", i, env, env + i + 1);
	}
	else
	{
		printf("declare -x %s\n", env);
	}
}

int	ft_replace_export_if_found(char **envp, char *env_variable)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strcmp(envp[i], env_variable) == 0)
			return (1);
		i++;
	}
	return (0);
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

char	**ft_add_in_export(char **envp, char *new_env_variable)
{
	int		i;
	int		j;
	char	**new_export;

	i = 0;
	if (!new_env_variable || !new_env_variable[0])
		return (envp);
	if (ft_replace_export_if_found(envp, new_env_variable))
		return (envp);
	while (envp && envp[i])
		i++;
	new_export = malloc(sizeof(char *) * (i + 2));
	if (!new_export)
		return (envp);
	j = 0;
	while (j < i)
	{
		new_export[j] = ft_strdup(envp[j]);
		j++;
	}
	new_export[j] = ft_strdup(new_env_variable);
	new_export[j + 1] = NULL;
	return (new_export);
}

char	**ft_export(char ***envp, char *new_env_variable)
{
	char	**new_env;

	if (env_var_checker(*envp, new_env_variable) == 1)
		return (NULL);
	new_env = ft_add_in_export(*envp, new_env_variable);
	free_tab((void **)*envp);
	*envp = new_env;
	return (new_env);
}
