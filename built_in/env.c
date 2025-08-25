/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   env.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/21 16:37:40 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/21 18:09:00 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name, char **envp)
{
	int		i;
	size_t	len;

	i = 0;
	if (!name || !envp)
		return (NULL);
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	cmd_env(char **envp, int *status)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '='))
			printf("%s\n", envp[i]);
		i++;
	}
	*status = 0;
}

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
