/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:08:53 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 17:07:08 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (0);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
