/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:56:56 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 16:57:20 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		else
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
