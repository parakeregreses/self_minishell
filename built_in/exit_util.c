/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:44:50 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 20:44:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_close_exit_final(t_utils u, int pipe1[2], int pipe2[2], t_2d std)
{
	retrieve_std(std.in, std.out);
	close_pipes(pipe1, pipe2);
	free_tab((void **)*(u.envp));
	full_delete_minishell(u.infos, u.n);
	exit(*(u.status));
}
