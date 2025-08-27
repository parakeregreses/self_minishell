/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:39:09 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 16:57:38 by jlaine-b         ###   ########.fr       */
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

void	free_and_print_exit(char ***envp, char *line, int *status)
{
	free(line);
	free_tab((void **) *envp);
	free(envp);
	free(status);
	ft_printf("exit\n");
}

void	launch_command(char *line, char ***envp, int *status)
{
	if (!empty_argument(line))
		command(line, envp, status);
	if (line[0] != '\0' && !empty_argument(line))
		add_history(line);
	free (line);
}

int	launching(char ***envp, int *status)
{
	char	*line;
	int		i;

	while (1)
	{
		i = 0;
		line = find_line();
		if (!line)
		{
			free_and_print_exit(envp, NULL, status);
			break ;
		}
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		launch_command(line, envp, status);
	}
	return (0);
}
