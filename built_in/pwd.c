/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:25:19 by liulm             #+#    #+#             */
/*   Updated: 2025/09/03 17:42:23 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd(int *status)
{
	char	new_pwd[PATH_MAX];

	if (!getcwd(new_pwd, PATH_MAX))
	{
		ft_putstr_fd("pwd: error retrieving current directory: getcwd: ", 2);
		perror("");
		return ;
	}
	else
		printf("%s\n", new_pwd);
	*status = 0;
}
