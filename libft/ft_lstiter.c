/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:59:25 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 09:23:02 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Iterates the list and applies the function ’f’ on the content 
of each node.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
