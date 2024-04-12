/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/12 15:36:31 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int ac, char **av)
{
	t_map	*data_map;
	int		i;

	input_check(ac, av);
	data_map = (t_map *)malloc(sizeof(t_map));
	if (!data_map)
		error_msg("Failed to create data!");
	get_char_map(data_map, av[1]);
	get_z(data_map);
	i = 0;
	/*ft_printf("width = %i\n", (data_map->width));
	ft_printf("height = %i\n", (data_map->height));
	while (i < 5)
	{
		ft_printf("x = %i\n", (data_map->z_matrix[0][i]).x);
		ft_printf("y = %i\n", (data_map->z_matrix[0][i]).y);
		ft_printf("z = %i\n", (data_map->z_matrix[2][i]).z);
		i++;
	}*/
}
