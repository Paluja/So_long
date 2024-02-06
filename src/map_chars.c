/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:55:30 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/06 16:07:17 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	items_ok(char *map)
{
	int	player;
	int	obj;
	int	exit;
	int	i;

	i = 0;
	player = 0;
	obj = 0;
	exit = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			obj++;
	}
	if (player != 1 || exit != 1 || !obj)
		return (0);
	return (1);
}

int	objects_ok(t_map *map)
{
	int	k;

	k = 0;
	while (k < map->obj)
	{
		if (map->ops_map[map->obj_y[k]][map->obj_x[k]] != 'F')
			return (0);
		k++;
	}
	return (1);
}

int	chars_ok(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10PEC", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
