/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printUn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:29:11 by pjimenez          #+#    #+#             */
/*   Updated: 2023/08/28 19:05:10 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nUlength(unsigned int n)
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

static char	*ft_Uitoa(unsigned int n)
{
	char	*str;
	size_t	len;
	long	ln;

	ln = (long)n;
	len = nUlength(ln);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (ln == 0)
		str[0] = '0';
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[len] = (ln % 10) + '0';
		ln /= 10;
		len--;
	}
	return (str);
}

int	ft_printUnbr(unsigned int n)
{
	char			*num;
	unsigned int	i;

	num = ft_Uitoa((unsigned int)n);
	i = ft_printstr(num);
	free(num);
	return (i);
}
