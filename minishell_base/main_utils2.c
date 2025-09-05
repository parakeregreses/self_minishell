/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:28:25 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 20:28:34 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		*envp = cmd_export(envp, args, status, 1);
	free_tab((void **)args);
	return (*envp);
}
