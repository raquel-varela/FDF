/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:42:17 by rvarela-          #+#    #+#             */
/*   Updated: 2023/11/17 15:27:42 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Main Functions
int		ft_printf(const char *format, ...);

//Auxiliar Printf Functions
void	ft_putchar(char c, int *count);
void	ft_putnbr_base(long nbr, int base_len, int *count, char *base);
void	ft_putstr(char *str, int *count);
void	ft_putnbr_ptr(unsigned long ptr, int base_len, int *count, char *base);
void	ft_putptr(unsigned long ptr, int base_len, int *count, char *base);
#endif