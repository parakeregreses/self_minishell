/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:13:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/11/30 15:14:04 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charinstr(char *s, char c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
