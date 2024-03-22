/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:17:07 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:31:50 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies the function ’f’ on the content of each node of lst. 
result is stored in a new list. 
The ’del’ function is used to delete the content of a node if needed.
lst - address of a pointer to a node.
f - address of the function used to iterate on the list.
del - address of the function to delete the content of a node if needed.
Return the new list, NULL if allocation fails*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp_node;

	new_list = NULL;
	while (lst)
	{
		tmp_node = ft_lstnew((*f)(lst->content));
		if (!tmp_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp_node);
		lst = lst->next;
	}
	return (new_list);
}
