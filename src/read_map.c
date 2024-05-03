/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:53:03 by rvarela           #+#    #+#             */
/*   Updated: 2024/05/01 22:23:01 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	free(line);
	return (height - 1);
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
	data_map->char_map[0] = "init";
	while (i < data_map->height)
	{
		tmp = get_next_line(fd);
		data_map->char_map[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		i++;
	}
	data_map->char_map[i] = NULL;
	close (fd);
}

static void	z_line_split(t_point *matrix, char *line)
{
	char	**z_coord;
	int		i;

	z_coord = ft_split(line, ' ');
	i = 0;
	while (z_coord[i])
	{
		matrix[i].x = 0;
		matrix[i].y = 0;
		matrix[i].z = ft_atoi(z_coord[i]);
		if (!ft_strchr(z_coord[i], ','))
			matrix[i].color = WHITE;
		else
			matrix[i].color = ft_atoi_hex(ft_strchr(z_coord[i], ',') + 3);
		i++;
	}
	free_tab(z_coord);
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
		curr_znbr = count_words(data_map->char_map[i], ' ');
		if (first_znbr == 0)
			first_znbr = curr_znbr;
		else if (curr_znbr != first_znbr)
			free_matrix_error(data_map, i - 1, "Error:Diff size between rows.");
		data_map->z_matrix[i] = (t_point *)malloc(sizeof(t_point) * curr_znbr);
		if (!data_map->z_matrix[i])
			free_matrix_error(data_map, i - 1, "Fail alloc for points line.");
		z_line_split(data_map->z_matrix[i], data_map->char_map[i]);
		i++;
	}
	free_tab(data_map->char_map);
	data_map->width = curr_znbr;
}
