/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:25:06 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/07 11:35:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab_arg(t_arg *text)
{
	int	i;

	if (text == NULL)
	{
		ft_printf("(null)\n");
		return ;
	}
	i = 0;
	while ((text[i]).str != NULL)
	{
		ft_printf("%d | %s\n", (text[i]).quote, (text[i]).str);
		i++;
	}
	ft_printf("(null)\n");
}
