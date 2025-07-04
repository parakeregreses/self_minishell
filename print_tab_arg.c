/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:25:06 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:25:07 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab_arg(t_arg *text)
{
	int	i;

	i = 0;
	while ((text[i]).str != NULL)
	{
		ft_printf("%d | %s\n", (text[i]).quote, (text[i]).str);
		i++;
	}
}
