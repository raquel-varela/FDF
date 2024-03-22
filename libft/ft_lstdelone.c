/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:02:19 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/27 16:26:40 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*lst - the node to free
frees the memory of the node’s content..
..using the function ’del’ given as a parameter..
..and free the node. The memory of ’next’ must not be freed.
(lst->content implicitly cast to void*)*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free (lst);
}
