/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:12:21 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/30 11:41:02 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstcpy(t_list *lst, void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*start_list;

	new_list = ft_lstnew(lst->content);
	if (!new_list)
		return (NULL);
	start_list = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next ;
		new_elem = ft_lstnew(lst->content);
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_list->next = new_elem;
		new_list = new_list->next;
	}
	return (start_list);
}

static t_list	*ft_full_del(void *ctn, t_list *list, void (*del)(void *))
{
	if (ctn)
		del(ctn);
	ft_lstclear(&list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*start_list;
	void	*ctn;

	if (lst == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_lstcpy(lst, del));
	ctn = f(lst->content);
	new_list = ft_lstnew(ctn);
	if (!new_list || !ctn)
		return (ft_full_del(ctn, new_list, del));
	start_list = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		ctn = f(lst->content);
		new_elem = ft_lstnew(ctn);
		if (!new_elem || !ctn)
			return (ft_full_del(ctn, start_list, del));
		new_list->next = new_elem;
		new_list = new_list->next;
	}
	return (start_list);
}
