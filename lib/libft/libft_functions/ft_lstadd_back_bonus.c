/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:51 by emurillo          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:11 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**
**	This functions goes to the last member of the list and includes a new node.
**	First we check that the list is not empty (*lst == NULL), if true add new.
**	We use a temp variable to move in the list, and not modify the nodes.
**
**	Then we go to the end, we could use (temp = ft_lstlast(*lst)) or we can use
**	a while loop when the value of (list.next == NULL), we are in the last node.
**
**	Once there, we chance the pointer of next to the new node. (temp.next = new)
**	this will add the node to the end of the list, effectivly adding it to the
**	original list (*lst).
**
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}
