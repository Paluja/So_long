/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:59:14 by pjimenez          #+#    #+#             */
/*   Updated: 2023/09/23 20:56:43 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char const format, va_list args)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print += ft_printptr(va_arg(args, t_uintptr));
	else if (format == 'd' || format == 'i')
		print += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print += ft_printunbr(va_arg(args, int));
	else if (format == 'x')
		print += ft_printx(va_arg(args, unsigned int), format);
	else if (format == 'X')
		print += ft_printx(va_arg(args, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%%", 1);
		print++;
	}
	return (print);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		print;
	va_list	args;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_format(str[i + 1], args);
			i++;
		}
		else
		{
			print += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (print);
}
