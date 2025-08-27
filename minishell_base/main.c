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
			return (ft_strdup(envp[i]));
		i++;
	}
	return (NULL);
}

static char	*ft_findpathline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	**update_path(char ***envp, int *status)
{
	char	**args;

	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("export");
	args[2] = NULL;
	args[1] = ft_strdup("PATH=/home/jlaine-b/bin:/usr/local/sbin:\
	/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	if (ft_findpathline(*envp) == NULL)
		*envp = cmd_export(envp, args, status, 1);
	free_tab((void **)args);
	return (*envp);
}

char	**shlvl_1(char **args, char ***envp, int *status)
{
	args[1] = ft_strdup("SHLVL=1");
	*envp = cmd_export(envp, args, status, 1);
	free_tab((void **) args);
	return (*envp);
}

char	**update_shlvl(char ***envp, int *status)
{
	char	*str;
	int		shell_level;
	char	**args;

	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("export");
	args[2] = NULL;
	str = shlvlline(*envp);
	if (str == NULL)
		return (shlvl_1(args, envp, status));
	shell_level = atoi(str + 6);
	if ((shell_level) < 0)
		shell_level = -1;
	if ((shell_level) > 999)
	{
		ft_printf("minishell: warning: shell level\
(%d) too high, resetting to 1\n", shell_level);
		shell_level = 0;
	}
	free(str);
	args[1] = ft_strjoinfree(ft_strdup("SHLVL="), ft_itoa(shell_level + 1));
	*envp = cmd_export(envp, args, status, 1);
	free_tab((void **) args);
	return (*envp);
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
		*our_envp = update_shlvl(our_envp, status);
		*our_envp = update_path(our_envp, status);
		launching(our_envp, status);
	}
	else
	{
		ft_printf("Usage: ./minishell");
		return (1);
	}
	return (0);
}
