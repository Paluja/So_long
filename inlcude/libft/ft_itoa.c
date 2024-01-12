/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:21:28 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 18:06:23 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlength(int n)
{
	int	cont;

	cont = 0;
	if (n <= 0)
	{
		cont++;
	}
	while (n != 0)
	{
		n /= 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	ln;

	ln = (long)n;
	len = nlength(ln);
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
