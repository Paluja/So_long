/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:41:03 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/11 17:08:56 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*cpy;
	size_t		i;
	size_t		full_len;

	i = 0;
	full_len = ft_strlen(s1) + ft_strlen(s2);
	cpy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cpy)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		cpy[i] = s1[i];
		i++;
	}
	while (i < full_len)
	{
		cpy[i] = *s2++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
