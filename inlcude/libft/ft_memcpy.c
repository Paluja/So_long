/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:09:16 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 16:57:15 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*sorc;
	unsigned char		*dest;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	while (n--)
	{
		*dest++ = *sorc++;
	}
	return (dst);
}
