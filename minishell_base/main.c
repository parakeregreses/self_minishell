/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/02 16:37:48 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/13 15:38:39 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"


char	*shlvlline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "SHLVL=", 6) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}
char	**update_SHLVL(char ***envp, int *status)
{
	char	*str;
	int		shell_level;

	str = shlvlline(*envp);
	if (str == NULL)
		return (cmd_export(envp, "SHLVgit L=1", status, 1));
	shell_level = atoi(str + 6);
	free(str);
	str = ft_strjoinfree(ft_strdup("SHLVL="), ft_itoa(shell_level + 1));
	return (cmd_export(envp, str, status, 1));
}

int	main(int argc, char **argv, char **envp)
{
	char	***our_envp;
	int		*status;

	(void)argv;
	if (argc == 1)
	{
		get_signal(SA_RESTART, 0);
		our_envp = malloc(sizeof(char ***) * 1);
		*our_envp = ft_copy_env(envp);
		status = malloc(sizeof(int));
		*status = 0;
		*our_envp = update_SHLVL(our_envp, status);
		launching(our_envp, status);
	}
	else
	{
		ft_printf("Usage: ./minishell");
		return (1);
	}
	return (0);
}
