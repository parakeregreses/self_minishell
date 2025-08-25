/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:22:12 by jlaine-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/25 17:59:45 by liulm            ###   ########.fr       */
=======
/*   Updated: 2025/08/25 17:57:55 by jlaine-b         ###   ########.fr       */
>>>>>>> b22fd4361ffcab9f0c17847369cc283b148ba756
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

int	g_finished = 0;

static void	signal_handler(int signal)
{
	g_finished = signal;
	
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	signal_handler_heredoc(int signal)
{
	g_finished = signal;
	
	write(1, "\n", 1);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
}

void	get_signal(int SA, int here_doc)
{
	struct sigaction	handler;

	handler.sa_handler = signal_handler;
	if (here_doc == 1)
		handler.sa_handler = signal_handler_heredoc;
	sigemptyset(&handler.sa_mask);
<<<<<<< HEAD
	handler.sa_flags = SA_RESTART;
=======
	handler.sa_flags = SA;
>>>>>>> b22fd4361ffcab9f0c17847369cc283b148ba756
	sigaction(SIGINT, &handler, NULL);
	signal(SIGQUIT, SIG_IGN);
}
