/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:24:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 12:29:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// delete leftover pipe signs at the end of segments
t_arg	*trim_arg(t_arg *arg)
{
	int		i;
	char	*line;

	i = 0;
	while (arg[i].str != NULL)
	{
		line = arg[i].str;
		arg[i].str = ft_strtrim(line, "|");
		free(line);
		i++;
	}
	return (arg);
}
