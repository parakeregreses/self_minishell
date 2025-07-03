/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:24:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/03 12:27:16 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*trim_arg(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg[i].str != NULL)
	{
		arg[i].str = ft_strtrim(arg[i].str, "|");
		i++;
	}
	return (arg);
}