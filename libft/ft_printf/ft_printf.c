/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:32:25 by rvarela-          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:45 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_spec(va_list args, const char *format, int i, int *count)
{
	if (format[i] == '%')
		ft_putchar('%', count);
	if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr_base(va_arg(args, int), 10, count,
			"0123456789");
	if (format[i] == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), 10, count,
			"0123456789");
	if (format[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	if (format[i] == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), 16, count,
			"0123456789abcdef");
	if (format[i] == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), 16, count,
			"0123456789ABCDEF");
	if (format[i] == 'p')
		ft_putptr(va_arg(args, unsigned long), 16, count,
			"0123456789abcdef");
}

/*write the output under the control of a
       format string that specifies how subsequent arguments (or
       arguments accessed via the variable-length argument facilities of
       stdarg(3)) are converted for output.*/
int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			check_spec(args, format, i, &count);
			i++;
		}
		else
		{
			ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
