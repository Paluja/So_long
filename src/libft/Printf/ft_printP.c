/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:18:08 by pjimenez          #+#    #+#             */
/*   Updated: 2023/08/28 19:04:45 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexaPtr(uintptr_t n, char *base)
{
	unsigned int	j;

	j = 0;
	if (n >= 16)
	{
		ft_hexaPtr((n / 16), base);
		ft_hexaPtr((n % 16), base);
	}
	else
	{
		while (base[j])
		{
			if (j == n)
			{
				write(1, &base[j], 1);
			}
			j++;
		}
	}
}

static int	ft_hexalen(uintptr_t n)
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

int	ft_printPtr(uintptr_t n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		ft_hexaPtr(n, "0123456789abcdef");
		i += ft_hexalen(n);
	}
	return (i);
}
