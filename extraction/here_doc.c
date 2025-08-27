/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:20:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 16:55:45 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"

char	*here_doc2(char *lim, char *tempfilename, char *lim_return, int fd);

char	*ft_tempfilename(void)
{
	char	*tempfilename;
	char	*un;

	tempfilename = ft_strdup("tempfile");
	while (access(tempfilename, F_OK) == 0)
	{
		un = ft_strdup("1");
		tempfilename = ft_strjoinfree(tempfilename, un);
	}
	return (tempfilename);
}

char	*sigint(char *tempfilename, char *line, char *lim_return, int fd)
{
	get_signal(SA_RESTART, 0);
	unlink(tempfilename);
	free(tempfilename);
	free(line);
	free(lim_return);
	close(fd);
	return (ft_strdup("sigint"));
}

char	*here_doc(char *lim)
{
	char	*tempfilename;
	char	*lim_return;
	int		fd;

	tempfilename = ft_tempfilename();
	fd = open(tempfilename, O_RDWR | O_CREAT, 00777);
	if (fd == -1)
		return (NULL);
	lim_return = ft_strjoin(lim, "\n");
	g_finished = 0;
	return (here_doc2(lim, tempfilename, lim_return, fd));
}

char	*here_doc2(char *lim, char *tempfilename, char *lim_return, int fd)
{
	int		i;
	char	*line;

	i = 0;
	get_signal(0, 1);
	line = get_next_line(0);
	while (g_finished == 0 && ft_strcmp(line, lim_return) != 0 && line != NULL)
	{
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
		i++;
	}
	if (g_finished == SIGINT)
		return (sigint(tempfilename, line, lim_return, fd));
	get_signal(SA_RESTART, 0);
	if (line == NULL)
		ft_printf("minishell :warning: here-document at line %d \
delimited by end-of-file (wanted `%s')\n", i, lim);
	free(lim_return);
	free(line);
	close(fd);
	return (tempfilename);
}
