/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:41:10 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 11:17:34 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc (1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
	{
		len = ft_strlen(s) - start;
	}
	cpy = malloc(sizeof(char) * (len + 1));
	if (s == NULL || cpy == NULL)
		return (NULL);
	while (i < (int)len)
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}
