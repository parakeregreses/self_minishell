/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/15 14:31:07 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	define_fdin(char *str)
// {
// 	int		i;
// 	char	*filename;

// 	filename = ft_firstword(str + 1, ' ');
// 	if (is_infile(filename) == FALSE)
// 	{
// 		free(filename);
// 		return(-1);
// 	}
// 	i = open(filename, O_RDONLY);
// 	close(i);
// 	free(filename);
// 	return (i);
// }

int	define_fdin(t_coord2d pos, t_arg *tab)
{
	int		i;
	char	*filename;
	char	*str;

	str = reglue_quoted(&(tab[pos.x]));
	filename = ft_firstword(&(str[pos.y + 1]), ' ');
	ft_printf("filename = %s\n", filename);
	if (is_infile(filename) == FALSE)
	{
		free(filename);
		return(-1);
	}
	i = open(filename, O_RDONLY);
	close(i);
	free(filename);
	free(str);
	return (i);
}

static int	triple_chevron(t_arg *tab, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == FALSE && is_x_char_in_str((tab[i]).str, '<', 3) == TRUE)
		{
			ft_printf("bash: syntax error near unexpected token `<'");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static int	no_chevron(t_arg *tab, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == FALSE && is_x_char_in_str((tab[i]).str, '<', 1) == FALSE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

// return the position of the last chevron, with x as line number and y as char number in line x
static int	last_chevron(t_arg *tab, int n)
{
	int i;
	int	pos;
	int	fd;
	char *filename;
	char	*line;
	
	i = 0;
	fd = 0;
	while (i < n)
	{
		pos = 0;
		if ((tab[i]).quote == FALSE)
		{
			line = (tab[i]).str;
			// while (ft_strchri(line + pos, '<') != -1)
			// {
				pos = ft_strchri(line + pos, '<');
				if (pos != -1)
				{
					filename = ft_firstword(line + pos + 1, ' ');
					ft_printf("line = %s, pos = %d, filename = %s\n", line + pos, pos, filename);
					if (access(filename, F_OK | R_OK) != 0)
						perror(ft_strjoin("perror", filename));
					else
					{
						fd = open(filename, O_RDONLY);
						close(fd);
					}
				}
				pos++;
		}
		i++;
	}
	return (fd);
}

// on avance dans le texte, en excluant les "". Si chevron simple : on verifie que le fichier existe/access, et fdin = fd fichier, puis on continue quitte a changer fdin ! Si chevron double, hd = 1 et fdin = 0.
int	parse_fdin(t_arg *tab)
{
	int			fdin;
	int			n;

	n = tab_size_arg(tab);
	if (triple_chevron(tab, n) ==  TRUE)
		return (-1);
	if (no_chevron(tab, n) == TRUE)
		return (0);
	
	// pos = last_chevron(tab, n);
	// if (pos.x == -1 || pos.y == -1)
	// 	return (-1);
	// if (pos.y == 0 || (tab[pos.x]).str[pos.y - 1] == '<')
	// 	return (0);
	fdin = last_chevron(tab, n);
	return(fdin);
}