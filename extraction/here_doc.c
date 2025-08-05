/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:20:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 13:06:17 by jlaine-b         ###   ########.fr       */
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

t_file	here_doc(char *lim)
{
	char	*line;
	t_file	tempfile;
	char	*lim_return;

	ft_printf("lim = %s\n", lim);
	tempfile.filename = ft_tempfilename();
	tempfile.fd = open(tempfile.filename, O_RDWR | O_CREAT, 00777);
	if (tempfile.fd == -1)
		return (tempfile);
	lim_return = ft_strjoin(lim, "\n");
	line = get_next_line(0);
	while (ft_strcmp(line, lim_return) != 0)
	{
		write(tempfile.fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(lim_return);
	free(line);
	close(tempfile.fd);
	tempfile.fd = open(tempfile.filename, O_RDONLY);
	close(tempfile.fd);
	return (tempfile);
}
