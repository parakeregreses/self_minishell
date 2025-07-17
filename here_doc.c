/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:20:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/17 22:41:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tempfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:36:29 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/05/09 20:53:53 by jlaineb          ###   ########.fr       */
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

int	here_doc(char *lim)
{
	char	*line;
	int		fd_tempfile;
	char	*lim_return;
	char	*filename;

	ft_printf("lim = %s\n", lim);
	filename = ft_tempfilename(); // il faudra gerer la suppression de ces fichiers temporaires si plusieurs sont ouverts !!!
	fd_tempfile = open(filename, O_RDWR | O_CREAT, 00777);
	if (fd_tempfile == -1)
		return (-1);
	lim_return = ft_strjoin(lim, "\n");
	line = get_next_line(1);
	while (ft_strcmp(line, lim_return) != 0)
	{
		write(fd_tempfile, line, ft_strlen(line));
		free(line);
		line = get_next_line(1);
	}
	free(lim_return);
	free(line);
	close(fd_tempfile);
	return (fd_tempfile);
}