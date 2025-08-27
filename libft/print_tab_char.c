/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:32:07 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 18:53:39 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab_char(char **text)
{
	int	i;

	i = 0;
	while (text[i] != NULL)
		ft_printf("%s$\n", text[i++]);
	if (text[i] == NULL)
		ft_printf("(null)\n");
}
