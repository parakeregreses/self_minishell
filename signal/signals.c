/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:22:12 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 13:51:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

int	g_finished = 0;

void	disable_sigquit(int i)
{
	struct sigaction		sa;
	static struct termios	orig_termios;
	struct termios			new_termios;

	if (i == 1)
	{
		memset(&sa, 0, sizeof(sa));
		sa.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &sa, NULL);

		tcgetattr(STDIN_FILENO, &orig_termios);
		new_termios = orig_termios;
		new_termios.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
	}
	if (i == 2)
	{
		memset(&sa, 0, sizeof(sa));
		sa.sa_handler = SIG_DFL;
		sigaction(SIGQUIT, &sa, NULL);
		tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
	}
}

static void	signal_handler(int signal)
{
	pid_t	pid;

	g_finished = signal;
	if (signal == SIGINT)
	{
		pid = waitpid(-1, NULL, 0);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

//static void	signal_handler(int signal)
//{
//	if (signal == SIGINT)
//	{
//		printf("\n");
//		rl_on_new_line();
//#ifdef __APPLE__
//		rl_set_prompt("");
//		rl_redisplay();
//		rl_set_prompt("minishell$ ");
//#else
//		rl_replace_line("", 0);
//		rl_redisplay();
//#endif
//	}
//	else if (signal == SIGQUIT)
//	{
//		rl_on_new_line();
//		rl_redisplay();
//	}
//}

static void	signal_handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		g_finished = signal;
		write(1, "^C\n", 3);
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
		sigaction(SIGQUIT, &handler, &old_handler);
	}
	if (here_doc == 1)
	{
		handler.sa_handler = signal_handler_heredoc;
		old_handler.sa_handler = signal_handler;
		sigaction(SIGINT, &handler, &old_handler);
	}
}
