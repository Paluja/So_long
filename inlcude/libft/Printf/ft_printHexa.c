/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printHexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:32:17 by pjimenez          #+#    #+#             */
/*   Updated: 2023/09/23 20:56:26 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printx(unsigned int n, char const str)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (str == 'x')
		ft_putnbr_hexa(n, "0123456789abcdef");
	else if (str == 'X')
		ft_putnbr_hexa(n, "0123456789ABCDEF");
	return (ft_hexalen(n));
}
