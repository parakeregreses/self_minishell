/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/18 10:40:10 by jlaine-b         ###   ########.fr       */
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
	ft_printf("\n\n%s\n", filename);
	if (is_infile(filename) == FALSE)
	{
		free(filename);
		return(-1);
	}
	i = open(filename, O_RDONLY);
	close(i);
	free(filename);
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

static t_coord2d	last_chevron(t_arg *tab, int n)
{
	int 		i;
	t_coord2d	pos;
	
	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == FALSE && ft_strrchri((tab[i]).str, '<') != -1)
		{
			pos.x = i;
			pos.y = ft_strrchri((tab[i]).str, '<');
			return (pos);
		}
		i++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	parse_fdin(t_arg *tab)
{
	int			fdin;
	int			n;
	t_coord2d	pos;

	n = tab_size_arg(tab);
	if (triple_chevron(tab, n) ==  TRUE)
		return (-1);
	if (no_chevron(tab, n) == TRUE)
		return (0);
	pos = last_chevron(tab, n);
	ft_printf("%d, %d\n", pos.x, pos.y);
	if (pos.y == 0 || (tab[pos.x]).str[pos.y - 1] == '<')
		return (0);
	fdin = define_fdin(pos, tab);
	return(fdin);
}