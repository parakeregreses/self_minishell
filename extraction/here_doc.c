/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:20:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 23:34:11 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	unlink(tempfilename);
	free(line);
	free(lim_return);
	close(fd);
	printf("sigint\n");
	return (ft_strdup("sigint"));
}

char	*sigquit(char *tempfilename, char *line, char *lim_return, int fd)
{
	unlink(tempfilename);
	free(line);
	free(lim_return);
	close(fd);
	return (NULL);
}

char	*here_doc(char *lim)
{
	char	*line;
	char	*tempfilename;
	char	*lim_return;
	int		fd;

	tempfilename = ft_tempfilename();
	fd = open(tempfilename, O_RDWR | O_CREAT, 00777);
	if (fd == -1)
		return (NULL);
	lim_return = ft_strjoin(lim, "\n");
	line = get_next_line(0);
	g_finished = 0;
	while (ft_strcmp(line, lim_return) != 0)
	{
		if (g_finished == SIGQUIT)
			return (sigquit(tempfilename, line, lim_return, fd));
		if (g_finished == SIGINT)
			return (sigint(tempfilename, line, lim_return, fd));
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(lim_return);
	free(line);
	close(fd);
	return (tempfilename);
}
