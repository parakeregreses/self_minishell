/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:56:24 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 15:38:01 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_here_doc(int fd, char *line)
{
	char	*lim;

	if (fd != 0)
		close(fd);
	lim = ft_firstword(line + 1, ' '); // ! le firstword devra etre quoted cleaned
	fd = here_doc(lim);
	free(lim);
	return (fd);
}

int	define_fd(char *line, int fd)
{
	char	*filename;

	if (!line[0])
	{
		ft_printf("minishell: syntax error near unexpected token `newline'");
		return (-1);
	}
	if (line[0] == '<')
		return (fd_here_doc(fd, line));
	filename = ft_firstword(line, ' ');
	if (is_infile(filename) == FALSE)
	{
		free(filename);
		return (-1);
	}
	if (fd != 0)
		close(fd);
	fd = open(filename, O_RDONLY);
	free(filename);
	return (fd);
}

int	find_fdin(char *str, t_arg *tab, int n)
{
	int		pos;
	int		i;
	int		fd;

	pos = 0;
	i = 0;
	fd = 0;
	while ((tab[i]).str != NULL && i < n)
	{
		if ((tab[i]).quote == TRUE)
			pos = pos + ft_strlen((tab[i]).str);
		else
		{
			fd = is_fd_inline(fd, (tab[i]).str, pos, str);
		}
		i++;
	}
	return (fd);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	t_arg	*tab;
// 	int		fd;

// 	str2 = calloc(sizeof(char), 47);
// 	str = ft_strdup("\"bullshit<bullshit
// 		\"hello<main.c < Makefile < note.txt << lin");
// 	tab = select_quoted_str(str);
// 	fd = find_fdin(str, tab, tab_size_arg(tab));
// 	// fd = open("tempfile11111", O_RDONLY);
// 	ft_printf("read : %d\n", read(fd, str2, 46));
// 	write(1, str2, 46);
// 	free(str);
// 	free_tab_arg(tab);
// 	free(str2);
// 	close(fd);
// }
