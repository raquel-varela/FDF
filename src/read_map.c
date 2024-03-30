/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:53:03 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/30 09:10:01 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error_msg("Failed to open the file!");
	line = get_next_line(fd);
	if (line)
		height++;
	while (line)
	{
		line = get_next_line(fd);
		height++;
		free(line);
	}
	close (fd);
	return (height);
}

get_map(t_map *data_map, char *file)
{
	int	fd;
	int	i;
	char *tmp;

	i = 0;
	data_map->height = get_height(file);








	
}