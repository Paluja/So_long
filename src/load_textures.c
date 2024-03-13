/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:31:34 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:22 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_map(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resized/goblin.png");
	map->img_player = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resized/gold.png");
	map->img_object = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resized/path3.png");
	map->img_path = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resized/Tree.png");
	map->img_wall = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resized/inactMine.png");
	map->img_exit = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			mlx_image_to_window(map->mlx, map->img_path, x * 64, y * 64);
			if (map->full_map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->img_wall, x * 64, y * 64);
			else if (map->full_map[y][x] == '0')
				mlx_image_to_window(map->mlx, map->img_path, x * 64, y * 64);
			else if (map->full_map[y][x] == 'P')
				draw_player(map, y, x);
			else if (map->full_map[y][x] == 'C')
				mlx_image_to_window(map->mlx, map->img_object, x * 64, y * 64);
			else if (map->full_map[y][x] == 'E')
			{
				load_exit(map, x, y);
			}
		}
	}
}

void	draw_player(t_map *map, int y, int x)
{
	mlx_texture_t	*texture;

	mlx_delete_image(map->mlx, map->img_player);
	if (map->full_map[y][x] == 'P')
	{
		load_player(map);
		mlx_image_to_window(map->mlx, map->img_player, map->player_x * 64,
			map->player_y * 64);
	}
	else if (map->full_map[y][x] == '0')
		mlx_image_to_window(map->mlx, map->img_path, x * 64, y * 64);
	if (map->obj == 0)
	{
		mlx_delete_image(map->mlx, map->img_exit);
		texture = mlx_load_png("./resized/mine.png");
		map->img_exit = mlx_texture_to_image(map->mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(map->mlx, map->img_exit, map->exit_x * 64,
			map->exit_y * 64);
	}
	map->player_x = x;
	map->player_y = y;
}

void	load_player(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resized/goblin.png");
	map->img_player = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}
