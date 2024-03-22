/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:32:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 22:32:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Appends the NUL-terminated string src to the end of dst. It will append at
 most size - strlen(dst) - 1 bytes, NUL-terminating the result. Returns the 
 total length of the initial length of dst plus the length of src. */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (i < (size - dest_len - 1) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
