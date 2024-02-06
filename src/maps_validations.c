/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:03 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/05 18:42:40 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	its_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->full_map[i])
	{
		if (map->width != ft_strlen(map->full_map[i]))
			return (0);
		i++;
	}
	if (map->height == map->width)
		return (0);
	return (1);
}

int	its_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->full_map[++i])
	{
		j = 0;
		if (map->full_map[i][0] != '1')
			return (0);
		while (map->full_map[i][j])
		{
			if (map->full_map[0][j] != '1')
				return (0);
			j++;
		}
		if (map->full_map[i][j - 1] != '1')
			return (0);
	}
	j = 0;
	while (map->full_map[i - 1][++j])
	{
		if (map->full_map[i - 1][j] != '1')
			return (0);
	}
	return (1);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->height || y >= map->width
		|| map->ops_map[x][y] == '1' || map->ops_map[x][y] == 'F')
		return ;
	if (((map->ops_map[x + 1][y] == 'E') || (map->ops_map[x - 1][y] == 'E'))
		&& ((map->ops_map[x][y + 1] == '1') || (map->ops_map[x][y - 1] == '1')))
		return ;
	if (((map->ops_map[x][y + 1] == 'E') || (map->ops_map[x][y - 1] == 'E'))
		&& ((map->ops_map[x + 1][y] == '1') || (map->ops_map[x - 1][y] == '1')))
		return ;
	if (map->ops_map[x][y] == 'E' || map->ops_map[x][y] == 'C')
		map->ops_map[x][y] = '0';
	map->ops_map[x][y] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int	path_ok(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->full_map[i])
	{
		j = 0;
		while (map->full_map[i][j])
		{
			if (map->full_map[i][j] == 'E')
			{
				flood_fill(map, i, j);
				if (map->ops_map[map->player_y][map->player_x] == 'F')
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_map(t_map *map)
{
	if (its_close(map) && its_rectangle(map) && path_ok(map))
	{
		if (objects_ok(map))
			return (1);
	}
	return (0);
}
