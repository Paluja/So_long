/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printUn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:29:11 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/14 13:42:13 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nulength(unsigned int n)
{
	int	cont;

	cont = 0;
	while (n != 0)
	{
		n /= 10;
		cont++;
	}
	return (cont);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = nulength(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_printunbr(unsigned int n)
{
	char			*num;
	unsigned int	i;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		num = ft_uitoa((unsigned int)n);
		i = ft_printstr(num);
		free(num);
	}
	return (i);
}
