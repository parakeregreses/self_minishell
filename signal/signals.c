/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:22:12 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 16:58:05 by jlaine-b         ###   ########.fr       */
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
	pid_t	pid;

	if (signal == SIGINT)
	{
		pid = waitpid(-1, NULL, 0);
		g_finished = signal;
		if (pid == -1)
		{
			write(1, "\n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

static void	signal_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		g_finished = signal;
		write(1, "\n", 1);
		// rl_replace_line("", 0);
		// rl_on_new_line();
		// rl_redisplay();
	}
}

void	get_signal(int SA, int here_doc)
{
	struct sigaction	handler;
	struct sigaction	old_handler;

	sigemptyset(&handler.sa_mask);
	sigemptyset(&old_handler.sa_mask);
	handler.sa_flags = SA;
	if (here_doc == 0)
	{
		old_handler.sa_handler = signal_handler_heredoc;
		handler.sa_handler = signal_handler;
		sigaction(SIGINT, &handler, &old_handler);
	}
	if (here_doc == 1)
	{
		handler.sa_handler = signal_handler_heredoc;
		old_handler.sa_handler = signal_handler;
		sigaction(SIGINT, &handler, &old_handler);
	}
	signal(SIGQUIT, SIG_IGN);
}
