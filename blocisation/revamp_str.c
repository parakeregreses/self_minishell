/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revamp_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:30:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 18:49:36 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// simplifies the spaces in str. turns "word 	word < word" in "word word<word"
char	*revamp_str(char *str)
{
	str = ft_strtrim(str, " ");
	str = delete_useless_spaces(str, "<>|");
	return (str);
}
