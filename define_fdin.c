/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 15:56:52 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// on avance dans le texte, en excluant les "". Si chevron simple : on verifie que le fichier existe/access, et fdin = fd fichier, puis on continue quitte a changer fdin ! Si chevron double, hd = 1 et fdin = 0.
int	define_fdin(char *str, t_arg *tab)
{
	int			fdin;
	int			n;

	n = tab_size_arg(tab);
	if (triple_chevron(tab, n) ==  TRUE)
		return (-1);
	if (no_chevron(tab, n) == TRUE)
		return (0);
	fdin = find_fdin(str, tab, n);
	return(fdin);
}