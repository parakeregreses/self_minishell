/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:39:09 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/13 17:46:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	empty_argument(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	*find_line(void)
{
	char	*prompt;
	char	*line;

	prompt = cat_current_dir();
	line = readline(prompt);
	free(prompt);
	return (line);
}

int	launching(char **envp)
{
	char	*line;
	int		i;

	while (1)
	{
		i = 0;
		line = find_line();
		if (!line)
		{
			free_tab((void **) envp);
			printf("exit\n");
			break ;
		}
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (ft_strncmp(line + i, "exit", 4) == 0)
		{
			free(line);
			free_tab((void **) envp);
			printf("exit\n");
			break ;
		}
		else
			judith(line, envp);
		if (line[0] != '\0' && !empty_argument(line))
			add_history(line);
		free (line);
	}
	free_tab((void **) envp);
	return (0);
}
