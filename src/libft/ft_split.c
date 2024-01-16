/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:00:04 by pjimenez          #+#    #+#             */
/*   Updated: 2023/06/06 17:08:58 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *str, char c)
{
	int		i;
	int		cont;
	int		ctrl;

	i = 0;
	cont = 0;
	ctrl = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && ctrl == 0)
		{
			cont++;
			ctrl = 1;
		}
		if (str[i] == c && ctrl == 1)
			ctrl = 0;
		i++;
	}
	return (cont);
}

static int	char_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static char	**memory_allocate(char const *s, char c)
{
	char	**str;
	int		rows;

	rows = word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!s || !str)
	{
		return (NULL);
	}
	return (str);
}

static void	ft_free(char **str, int i)

{
	while (i-- > 0)
	{
		free(str[i]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;
	int		ctrl;

	j = 0;
	ctrl = 0;
	str = memory_allocate(s, c);
	if (!str || !s)
		return (free(str), NULL);
	while (*s != '\0')
	{
		if (*s != c && ctrl == 0)
		{
			str[j] = ft_substr(s, 0, char_count(s, c));
			if (!str[j])
				return (ft_free(str, j), NULL);
			ctrl = 1;
			j++;
		}
		if (*s == c && ctrl == 1)
			ctrl = 0;
		s++;
	}
	str[j] = NULL;
	return (str);
}
