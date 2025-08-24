/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   env_variables.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/09 15:05:42 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/22 16:41:29 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_env(char **envp, char *env_variable)
{
	int		i;
	size_t	j;
	size_t	length;

	i = 0;
	length = 0;
	while (env_variable[length] && env_variable[length] != '=')
		length++;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (ft_strncmp(envp[i], env_variable, length) == 0 && j == length)
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_create_env(char **envp, char *new_env_variable)
{
	int		i;
	int		count;
	char	**new_envp;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	new_envp = (char **)malloc((count + 2) * sizeof(char *));
	if (new_envp == NULL)
		return (NULL);
	while (i < count)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (new_envp[i] == NULL)
			return (ft_free_envp(i, new_envp));
		i++;
	}
	new_envp[i] = ft_strdup(new_env_variable);
	if (new_envp[i] == NULL)
		return (ft_free_envp(i, new_envp));
	new_envp[++i] = NULL;
	return (new_envp);
}

char	**ft_replace_env_if_found(char **envp, char *env_variable)
{
	int	check;

	check = ft_find_env(envp, env_variable);
	if (check != -1)
	{
		free(envp[check]);
		envp[check] = ft_strdup(env_variable);
		return (envp);
	}
	else
		return (ft_create_env(envp, env_variable));
}

char	**ft_copy_env(char **envp)
{
	int		i;
	int		count;
	char	**env_cpy;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	env_cpy = (char **)malloc((count + 1) * sizeof(char *));
	if (env_cpy == NULL)
		return (NULL);
	while (i < count)
	{
		env_cpy[i] = ft_strdup(envp[i]);
		if (env_cpy[i] == NULL)
		{
			while (--i >= 0)
				free(env_cpy[i]);
			free(env_cpy);
			return (NULL);
		}
		i++;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}

char	**ft_add_in_env(char **envp, char *new_env_variable)
{
	char	**new_envp;
	char	**final;

	if (new_env_variable == NULL || new_env_variable[0] == '\0')
		return (envp);
	new_envp = ft_copy_env(envp);
	if (new_envp == NULL)
		return (NULL);
	final = ft_replace_env_if_found(new_envp, new_env_variable);
	if (final == NULL)
	{
		free_tab((void **) new_envp);
		return (NULL);
	}
	return (final);
}
