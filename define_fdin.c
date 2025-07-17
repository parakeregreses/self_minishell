/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/17 14:31:51 by jlaine-b         ###   ########.fr       */
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

#include <stdio.h>

// return the position of the last chevron, with x as line number and y as char number in line x
static int	last_chevron(char *str, t_arg *tab, int n)
{
	int i;
	int	j;
	int	fd;
	char *filename;
	char	*line;
	
	if (str == NULL)
		return (-100);
	
	i = 0;
	fd = 0;
	filename = NULL;
	// ft_printf("n = %d\n", n);
	while (i < n)
	{
		j = 0;
		if ((tab[i]).quote == FALSE)
		{
			line = (tab[i]).str;
			// ft_printf("%d\n", ft_strchri(line, '<'));
			while (ft_strchri(line, '<') != -1)
			{
				line = line + j;
				j = ft_strchri(line, '<');
				line = line + j;
				// ft_printf("line = %s, j = %d, filename = %s\n", line, j, filename);
				if (j != -1)
				{
					free(filename);
					filename = ft_firstword(line + 1, ' ');
					// ft_printf("line = %s, j = %d, filename = %s\n", line, j, filename);
					if (access(filename, F_OK | R_OK) != 0)
						perror(filename);
					else
					{
						fd = open(filename, O_RDONLY);
						close(fd);
					}
				}
				j++;
			}
		}
		i++;
	}
	ft_printf("filename = %s\n", filename);
	free(filename);
	return (fd);
}

// on avance dans le texte, en excluant les "". Si chevron simple : on verifie que le fichier existe/access, et fdin = fd fichier, puis on continue quitte a changer fdin ! Si chevron double, hd = 1 et fdin = 0.
int	parse_fdin(char *str, t_arg *tab)
{
	int			fdin;
	int			n;

	n = tab_size_arg(tab);
	if (triple_chevron(tab, n) ==  TRUE)
		return (-1);
	if (no_chevron(tab, n) == TRUE)
		return (0);
	fdin = last_chevron(str, tab, n);
	return(fdin);
}