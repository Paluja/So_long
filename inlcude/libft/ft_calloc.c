/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:43:22 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 16:58:49 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = (void *) malloc(count * size);
	if (temp == NULL)
	{
		return (NULL);
	}
	ft_bzero (temp, count * size);
	return (temp);
}
