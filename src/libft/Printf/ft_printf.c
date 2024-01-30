/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:59:14 by pjimenez          #+#    #+#             */
/*   Updated: 2023/08/28 19:01:21 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//meter algo para comprobar el %

//devuleve un int que es la cantidad de caracteres, estos deveran ser contado
//en la misma funcion que los printea(write)

static int	ft_format(char const format, va_list args)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print += ft_printPtr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print += ft_printUnbr(va_arg(args, int));
	else if (format == 'x')
		print += ft_printxX(va_arg(args, unsigned int), format);
	else if (format == 'X')
		print += ft_printxX(va_arg(args, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%", 1);
		print++;
	}
	return (print);
}

//TIENES QUE CONTROLAR EL NULL EN CASO DEL S
//==3737== error calling PR_SET_PTRACER, vgdb might block

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
			//al no poner el i++ haria lo cambios correpondientes en el indice
			//del propio % pero el i++ haria los cambios en el mismo porcentaje
			//y los siguientes cambios correspondientes se haran en la (Format) letra
			i++;
		}
		else
		{
			//por lo tanto al incrementar el indice se saltaria directamente el indice
			//del formato para continuar printeando el string justo despues de la letra de formato
			//ya que los cambios se harian en el propio porcentaje
			print += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (print);
}
