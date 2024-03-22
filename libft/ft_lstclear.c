/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:16:00 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:40:35 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Deletes and frees the given node and every successor of that 
node, using the function ’del’ and free(3). Finally, the 
pointer to the list must be set to NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete the content 
of the node.*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
