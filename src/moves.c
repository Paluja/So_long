/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:59 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/05 18:50:27 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up_move(t_map *map)
{
	if (map->full_map[map->player_y - 1][map->player_x] != '1'
		&& (map->full_map[map->player_y][map->player_x - 1] != 'E'
			|| map->obj == 0))
	{
		map->full_map[map->player_y][map->player_x] = '0';
		if (map->full_map[map->player_y - 1][map->player_x] == 'C')
			map->obj--;
		if (map->full_map[map->player_y - 1][map->player_x] == 'E'
			&& map->obj == 0)
			finish_game(map);
		map->player_y--;
		map->full_map[map->player_y][map->player_x] = 'P';
		ft_printf("Moves: %d\n", map->moves++);
		draw_map(map);
	}
}

void	down_move(t_map *map)
{
	if (map->full_map[map->player_y + 1][map->player_x] != '1'
		&& (map->full_map[map->player_y][map->player_x - 1] != 'E'
			|| map->obj == 0))
	{
		map->full_map[map->player_y][map->player_x] = '0';
		if (map->full_map[map->player_y + 1][map->player_x] == 'C')
			map->obj--;
		if (map->full_map[map->player_y + 1][map->player_x] == 'E'
			&& map->obj == 0)
			finish_game(map);
		map->player_y++;
		map->full_map[map->player_y][map->player_x] = 'P';
		ft_printf("Moves: %d\n", map->moves++);
		draw_map(map);
	}
}

void	right_move(t_map *map)
{
	if (map->full_map[map->player_y][map->player_x + 1] != '1'
		&& (map->full_map[map->player_y][map->player_x + 1] != 'E'
			|| map->obj == 0))
	{
		map->full_map[map->player_y][map->player_x] = '0';
		if (map->full_map[map->player_y][map->player_x + 1] == 'C')
			map->obj--;
		if (map->full_map[map->player_y][map->player_x + 1] == 'E'
			&& map->obj == 0)
			finish_game(map);
		map->player_x++;
		map->full_map[map->player_y][map->player_x] = 'P';
		ft_printf("Moves: %d\n", map->moves++);
		draw_map(map);
	}
}
void	left_move(t_map *map)
{
	if (map->full_map[map->player_y][map->player_x - 1] != '1'
		&& (map->full_map[map->player_y][map->player_x - 1] != 'E'
			|| map->obj == 0))
	{
		map->full_map[map->player_y][map->player_x] = '0';
		if (map->full_map[map->player_y][map->player_x - 1] == 'C')
			map->obj--;
		if (map->full_map[map->player_y][map->player_x - 1] == 'E'
			&& map->obj == 0)
			finish_game(map);
		map->player_x--;
		map->full_map[map->player_y][map->player_x] = 'P';
		ft_printf("Moves: %d\n", map->moves++);
		draw_map(map);
	}
}

void	move(mlx_key_data_t keycode, void *param)
{
	t_map *map;
	map = param;
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		up_move(map);
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		down_move(map);
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		right_move(map);
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		left_move(map);
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
	{
		mlx_terminate(map->mlx);
		free_things(map);
		exit(EXIT_SUCCESS);
	}
}