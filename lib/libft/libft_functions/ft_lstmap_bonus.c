/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:49:44 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/18 13:28:02 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function takes a list (lst) and applies the function (f) to each of its
**	elements content.
**	It creates a new list with each of the modified nodes from the original one
**
**	If at some point, the creation of a new node fails, the entire list is
**	cleared, and the function returns NULL.
**
**	- "lst" is the original list.
**	- "f" is the function that transforms the content of each node.
**	- "del" is a function that deletes the content of a node if needed
**	The result is a new list with the transformed content.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode->content = (*f)(lst->content);
		newnode->next = NULL;
		ft_lstadd_back(&newlst, newnode);
		if (newlst == NULL)
			newlst = newnode;
		lst = lst->next;
	}
	return (newlst);
}
