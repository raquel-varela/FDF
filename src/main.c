/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by rvarela-          #+#    #+#             */
/*   Updated: 2024/03/23 09:52:59 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"







int main(int ac, char **av)
{
	int	fd;
	
	if (ac != 2)
    	error_msg("The input file should be: <name>.fdf");
	fd = open(av[1], O_RDONLY, 0);
	if (fd == -1)
		error_msg("Failed to open the file!");
	else
		close(fd);
		



		
    if (error_check(ac, av) == 0)
		//Function DRAW MAP
		//read map
			//read line
			//split line
			//matrix


			
	else
		return (0);
}