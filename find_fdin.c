/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:56:24 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/17 22:39:40 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_fd(char *line)
{
	char	*filename;
	int		fd;

	if (!line[0])
	{
		ft_printf("minishell: syntax error near unexpected token `newline'");
		return (-1);
	}
	if (line[0] == '<')
		fd = here_doc(ft_firstword(line + 1, ' ')); // ! le firstword devra etre quoted cleaned
	else
	{
		filename = ft_firstword(line, ' ');
		ft_printf("filename = %s\n", filename);
		if (is_infile(filename) == FALSE)
		{
			free(filename);
			return(-1);
		}
		fd = open(filename, O_RDONLY);
		close(fd);
		free(filename);
	}
	return (fd);
}

int	is_fd_inline(int fd, char *line, int pos, char *full_line)
{
	int		pos_inline;

	pos_inline = ft_strchri(line, '<');
	pos = pos + pos_inline;
	while (pos_inline != -1 && pos_inline < (int) ft_strlen(line))
	{
		fd = define_fd(full_line + pos + 1);
		if (fd == -1)
			return (-1);
		ft_printf("line = %s, pos_inline = %d, pos = %d\n", line, pos_inline, pos);
		ft_printf("char = %c, pos = %d\n", full_line[pos], pos);
		line = line + pos_inline + 1;
		pos_inline = ft_strchri(line, '<');
		pos = pos + pos_inline + 1;
	}
	return (pos);
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
	ft_printf("fd = %d\n");
	return (fd);
}

int	main(void)
{
	char	*str;
	t_arg	*tab;

	str = ft_strdup("\"bullshit<bullshit\"hello<note.txt << lim < main.c ");
	tab = select_quoted_str(str);
	find_fdin(str, tab, tab_size_arg(tab));
	free(str);
	free_tab_arg(tab);
}
