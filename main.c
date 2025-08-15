/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/02 16:37:48 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/13 15:38:39 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	***our_envp;

	(void)argv;
	if (argc == 1)
	{
		get_signal();
		our_envp = malloc(sizeof(char ***) * 1);
		*our_envp = ft_copy_env(envp);
		launching(our_envp);
	}
	else
	{
		ft_printf("Usage: ./minishell");
		return (1);
	}
	return (0);
}
