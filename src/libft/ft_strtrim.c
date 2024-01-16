/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:19:16 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 18:08:36 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (s1[i] && ft_isinset(s1[i], set))
		i++;
	while (j > i && ft_isinset(s1[j - 1], set))
		j--;
	cpy = (char *)malloc(sizeof(char) * (j - i + 1));
	if (cpy == NULL)
		return (NULL);
	while (i < j)
	{
		cpy[k] = s1[i];
		i++;
		k++;
	}
	cpy[k] = 0;
	return (cpy);
}
