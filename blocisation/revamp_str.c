/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revamp_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:30:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 17:31:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*revamp_str(char *str)
{
	str = ft_strtrim(str, " ");
	str = delete_useless_spaces(str, "<>|");
	return (str);
}
