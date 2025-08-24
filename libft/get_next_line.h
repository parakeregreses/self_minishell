/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:11:05 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 20:05:10 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>	

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		find_newline(char *s);
size_t	ft_strlen(const char *s);
char	*ft_fill_new_buffer(size_t len, char *str, char *buffer);
ssize_t	ft_read(char **adr_str, int fd);
char	*ft_initptr(char *rest);
char	*ft_line(char	**adr_str);
int		ft_index(char *s);

#endif
