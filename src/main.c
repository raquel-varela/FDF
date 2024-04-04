/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/01 21:48:40 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

char	read_map(char *file)
{
	char	*line;
	int		fd;
	t_map	**map;
	int		i;

	line = NULL;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		error_msg("Failed to open the file!");
	i = 0;
	while (line)
	{
		map[i] = ft_split(line);
		line = get_next_line(fd);
		i++;
	}

}





int	main(int ac, char **av)
{
	t_map	*data_map;

	input_check(ac, av);
	data_map = (t_map *)malloc(sizeof t_map);
	if (!data_map)
		error_msg("Failed to create data!");
	get_char_map(data_map, av[1]);
	get_z(data_map);


	

		

		
	read_map(av[1]);


		
    if (error_check(ac, av) == 0)
		//Function DRAW MAP
		//read map
			//read line
			//split line
			//matrix


			
	else
		return (0);
}