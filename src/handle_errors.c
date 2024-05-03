/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:44:23 by rvarela-          #+#    #+#             */
/*   Updated: 2024/05/03 15:19:09 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_msg(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit (EXIT_FAILURE);
}

void	input_check(int ac, char **av)
{
	int	fd;
	int	len;

	if (ac != 2)
		error_msg("The input file should be: <name>.fdf");
	fd = open(av[1], O_RDONLY, 0);
	if (fd == -1)
		error_msg("Failed to open the file!");
	else
		close(fd);
	len = ft_strlen(av[1]);
	if (len < 4)
		error_msg("The input file name is very short.");
	if (ft_strncmp(av[1] + len - 4, ".fdf", 4) != 0)
		error_msg("Wrong extension. Not a .fdf file!");
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_matrix(t_map *data, int i)
{
	free_tab(data->char_map);
	while (i >= 0)
	{
		if (data->z_matrix[i])
		{
			free(data->z_matrix[i]);
			i--;
		}
	}
	free(data->z_matrix);
	free(data);
}

void	free_matrix_error(t_map	*data, int i, char *msg)
{
	free_matrix(data, i);
	error_msg(msg);
}
