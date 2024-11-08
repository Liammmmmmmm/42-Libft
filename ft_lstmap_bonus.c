/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:06 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/08 17:39:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (NULL);
	newlist = temp;
	lst = lst->next;
	while (lst != NULL)
	{
		temp->next = ft_lstnew(f(lst->content));
		temp = temp->next;
		if (!temp)
			ft_lstclear(&newlist, del);
		lst = lst->next;
	}
	return (newlist);
}
