/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:40 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:39:27 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates memory for an array of nmemb elements of size bytes each and returns
 a pointer to the allocated memory. The memory  is  set  to ZERO.  If nmemb or 
 size is 0, then calloc() returns either NULL, or a unique pointer value that 
 can later  be  successfully passed to free().  If the multiplication of nmemb 
 and size would result in integer overflow, then calloc() returns an error.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
