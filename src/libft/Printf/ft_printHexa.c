/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printHexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:32:17 by pjimenez          #+#    #+#             */
/*   Updated: 2023/08/28 19:03:28 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// // static int	str_valid(char *str)
// // {
// // 	int	i;
// // 	int	j;

// // 	i = 0;
// // 	while (str[i])
// // 	{
// // 		if ((str[i] == '+' || str[i] == '-'))
// // 			return (0);
// // 		j = i + 1;
// // 		while (str[j])
// // 		{
// // 			if (str[j] == str[i])
// // 			{
// // 				return (0);
// // 			}
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // 	if (i <= 1)
// // 	{
// // 		return (0);
// // 	}
// // 	return (1);
// // }

//para el formato de la p utilizar esta fincion pero escribiendo el 
//0x delante,poco mas
static void	ft_putnbr_hexa(unsigned int nbr, const char *base)
{
	unsigned int	j;

	j = 0;
	if (nbr >= 16)
	{
		ft_putnbr_hexa((nbr / 16), base);
		ft_putnbr_hexa((nbr % 16), base);
	}
	else
	{
		while (base[j])
		{
			if (j == nbr)
			{
				write(1, &base[j], 1);
			}
			j++;
		}
	}
}

static int	ft_hexalen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_printxX(unsigned int n, char const str)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (str == 'x')
		ft_putnbr_hexa(n, "0123456789abcdef");
	else if (str == 'X')
		ft_putnbr_hexa(n, "0123456789ABCDEF");
	return (ft_hexalen(n));
}

// #include "ft_printf.h"

// void	ft_puthex(unsigned int num, const char format)
// {
// 	if (num >= 16)
// 	{
// 		ft_puthex(num / 16, format);
// 		ft_puthex(num % 16, format);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_putchar_fd((num + '0'), 1);
// 		else
// 		{
// 			if (format == 'x')
// 				ft_putchar_fd((num - 10 + 'a'), 1);
// 			if (format == 'X')
// 				ft_putchar_fd((num - 10 + 'A'), 1);
// 		}
// 	}
// }

// int	ft_hexlen(unsigned	int num)
// {
// 	int	len;

// 	len = 0;
// 	while (num != 0)
// 	{
// 		len++;
// 		num = num / 16;
// 	}
// 	return (len);
// }

// int	ft_printxX(unsigned int num, const char format)
// {
// 	if (num == 0)
// 		return (write(1, "0", 1));
// 	else
// 		ft_puthex(num, format);
// 	return (ft_hexlen(num));
// }
