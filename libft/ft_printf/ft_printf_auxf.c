/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_auxf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:07 by rvarela           #+#    #+#             */
/*   Updated: 2023/11/17 15:28:20 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putnbr_base(long nbr, int base_len, int *count, char *base)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', count);
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base_len, count, base);
	ft_putchar(base[nbr % base_len], count);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr_ptr(unsigned long ptr, int base_len, int *count, char *base)
{
	if (ptr < (unsigned int)base_len)
		ft_putchar(base[ptr], count);
	if (ptr >= (unsigned int)base_len)
	{
		ft_putnbr_ptr(ptr / base_len, base_len, count, base);
		ft_putnbr_ptr(ptr % base_len, base_len, count, base);
	}
}

void	ft_putptr(unsigned long ptr, int base_len, int *count, char *base)
{
	if (ptr == 0)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_ptr(ptr, base_len, count, base);
	}
}
