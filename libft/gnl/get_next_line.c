/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:34:10 by rvarela-          #+#    #+#             */
/*   Updated: 2024/05/01 22:28:42 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function to get text from the buffer_tmp until \n
char	*get_till_n(char *buffer_tmp)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer_tmp[i])
		return (NULL);
	while (buffer_tmp[i] != '\0' && buffer_tmp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer_tmp[i] != '\0' && buffer_tmp[i] != '\n')
	{
		line[i] = buffer_tmp[i];
		i++;
	}
	if (buffer_tmp[i] == '\n')
	{
		line[i] = buffer_tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*function to join buffers of repeated reads in 
buffer_tmp till there's no chars to read or there's \n*/
static char	*ft_get_line(int fd, char *buffer_tmp)
{
	char	*buffer;
	int		n_chars;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	n_chars = 1;
	while (n_chars != 0 && !ft_strchr_gnl(buffer_tmp, '\n'))
	{
		n_chars = read(fd, buffer, BUFFER_SIZE);
		if (n_chars == -1)
		{
			free(buffer);
			free(buffer_tmp);
			return (NULL);
		}
		buffer[n_chars] = '\0';
		buffer_tmp = ft_strjoin_gnl(buffer_tmp, buffer);
	}
	free(buffer);
	return (buffer_tmp);
}

//function to get the remainer after /n of buffer_tmp
static char	*ft_get_last(char *buffer_tmp)
{
	char	*last;
	int		i;
	int		j;

	i = 0;
	while (buffer_tmp[i] != '\0' && buffer_tmp[i] != '\n')
		i++;
	if (!buffer_tmp[i] || !buffer_tmp[i + 1] || buffer_tmp[i + 1] == '\n')
	{
		free (buffer_tmp);
		return (NULL);
	}
	last = (char *)malloc(sizeof(char) * (strlen_gnl(buffer_tmp) - i + 1));
	if (!last)
		return (NULL);
	j = 0;
	while (buffer_tmp[++i] != '\0')
	{
		last[j] = buffer_tmp[i];
		j++;
	}
	last[j] = '\0';
	free(buffer_tmp);
	return (last);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer_tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer_tmp);
		return (NULL);
	}
	buffer_tmp = ft_get_line(fd, buffer_tmp);
	if (!buffer_tmp)
		return (NULL);
	line = get_till_n(buffer_tmp);
	buffer_tmp = ft_get_last(buffer_tmp);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("42.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file!\n");
		return (1);
	}
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("Line %i: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/