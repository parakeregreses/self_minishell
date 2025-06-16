/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:08:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 17:27:39 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_segment
{
	int		start;
	int		end;
}			t_segment;

enum e_booleen
{
        FALSE=0,
        TRUE=1
};

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_filetostr(char *pathname);
void		free_tab(void **tab);
char		**ft_insert_last_line(char **text, char *line);
void		ft_print_tab_char(char **text);
char		*ft_strjoinfree(char *s1, char *s2);
int			ft_printf(const char *s, ...);
int			ft_parsing_printf(const char *s);
int			ft_charinstr(char *s, char c);
int			ft_chose_printf(char s, va_list list);
int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_print_ptr(void *ptr);
int			ft_print_int(int nb);
int			ft_print_udec(unsigned int nb);
int			ft_print_lowhex(unsigned int nb);
int			ft_print_uphex(unsigned int nb);
char		*get_next_line(int fd);
int			ft_abs(int i);
int			tab_size(char **tab);
char		**append_tabs_and_free(char **tab1, char **tab2);
char		**cut_tab_head(char **tab, int n);
char		**cut_tab_tail(char **tab, int n);
char		**delete_line_in_tab(char **old_tab, int i);
t_segment	find_segment(char *str, char c);
int			is_x_char_in_str(char *str, char c, int x);
int			ft_iswhitespace(char c);
int			does_char_end_line(char *line, char c);
int			does_char_start_line(char *line, char c);
char		*ft_firstword(char *str, char c);

#endif
