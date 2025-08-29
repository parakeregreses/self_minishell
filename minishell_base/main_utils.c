/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:07:46 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 15:00:05 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (ft_findpathline(*envp) != NULL)
		return (*envp);
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("export");
	args[2] = NULL;
	args[1] = ft_strdup("PATH=/home/jlaine-b/bin:/usr/local/sbin:"\
"/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	if (ft_findpathline(*envp) == NULL)
		*envp = cmd_export(envp, args, status);
	free_tab((void **)args);
	return (*envp);
}

char	**shlvl_1(char **args, char ***envp, int *status)
{
	args[1] = ft_strdup("SHLVL=1");
	*envp = cmd_export(envp, args, status);
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
	*envp = cmd_export(envp, args, status);
	free_tab((void **) args);
	return (*envp);
}
