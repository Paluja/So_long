/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:06:55 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 17:05:38 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	z;
	size_t	cont;

	i = ft_strlen(dest);
	z = ft_strlen(src);
	j = 0;
	if (size <= i)
	{
		return (size + z);
	}
	cont = ft_strlen(dest);
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (cont + z);
}
