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
