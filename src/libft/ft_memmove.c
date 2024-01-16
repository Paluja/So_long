/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:09:29 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 16:57:05 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_pnt;
	char	*src_pnt;
	size_t	i;

	dest_pnt = (char *)dst;
	src_pnt = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst > src)
	{
		while (len--)
			dest_pnt[len] = src_pnt[len];
	}
	else
	{
		while (i < len)
		{
			dest_pnt[i] = src_pnt[i];
			i++;
		}
	}
	return (dst);
}
