/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:53:03 by rvarela           #+#    #+#             */
/*   Updated: 2024/04/01 22:33:37 by rvarela          ###   ########.fr       */
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

void	get_char_map(t_map *data_map, char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	data_map->height = get_height(file);
	data_map->char_map = malloc(sizeof(char *) * (data_map->height + 1));
	if (!data_map->char_map)
		error_msg("Failled allocation of memory for char array map");
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error_msg("Failed to open the file!");
	data_map->char_map[0] = get_next_line(fd);
	while (data_map->char_map[i])
	{
		tmp = get_next_line(fd);
		data_map->char_map[++i] = ft_strtrim(tmp, "\n");
		free (tmp);
	}
	//dont have to put de null?
	close (fd);
}

void	z_line_split(t_map *z_matrix, char *line)
{
	



	
}


void	get_z(t_map *data_map)
{
	int	i;
	int	first_znbr;
	int	curr_znbr;

	data_map->z_matrix = (t_point **)malloc(sizeof(t_point *)
			* data_map->height);
	if (!data_map->z_matrix)
		error_msg("Failled allocation of memory for point Z matrix");
	i = 0;
	first_znbr = 0;
	while (data_map->char_map[i])
	{
		curr_znbr = count_words(data_map->char_map[i], " ");
		if (first_znbr == 0)
			first_znbr = curr_znbr;
		if (curr_znbr != first_znbr)
		{
			free_matrix(data_map, i - 1);
			error_msg("Invalid map! Different size between rows.");
		}
		data_map->z_matrix[i] = (t_point *)malloc(sizeof(t_point) * curr_znbr);
		if (!data_map->z_matrix[i])
		{
			free_matrix(data_map, i);
			error_msg("Failled allocation of memory for line of points.");
		}
		z_line_split(data_map->z_matrix[i], data_map->char_map[i]);
		i++;
	}
}
