/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:39:09 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 17:35:10 by jlaine-b         ###   ########.fr       */
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

void	free_and_print_exit(char ***envp, char *line, int *ex_code)
{
	free(line);
	free_tab((void **) *envp);
	free(envp);
	free(ex_code);
	printf("exit\n");
}

void cmd_exit(char **args, char ***envp, int *status)
{

}

void	launching2(char *line, char ***envp, int *status)
{
	if (!empty_argument(line))
		judith(line, envp, ex_code);
	if (line[0] != '\0' && !empty_argument(line))
		add_history(line);
	free (line);
}

int	launching(char ***envp, int *ex_code)
{
	char	*line;
	int		i;

	while (1)
	{
		i = 0;
		line = find_line();
		if (!line)
		{
			free_and_print_exit(envp, NULL, ex_code);
			break ;
		}
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		//if (ft_strncmp(line + i, "exit", 4) == 0)
		//{
		//	free_and_print_exit(envp, line, status);
		//	break ;
		//}
		launching2(line, envp, status);
	}
	return (0);
}
