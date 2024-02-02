/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:22:59 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/02 18:20:06 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    up_move(t_map *map)
{
    if (map->full_map[map->player_y - 1][map->player_x] != 1)
    {
        map->full_map[map->player_y - 1][map->player_x] = 'P';
        // map->full_map[map->player_y][map->player_x] = '0';
        draw_map(map);
    }
    
}
void    down_move(t_map *map)
{
    if (map->full_map[map->player_y + 1][map->player_x] != 1)
    {
        map->full_map[map->player_y + 1][map->player_x] = 'P';
        // map->full_map[map->player_y][map->player_x] = '0';
        draw_map(map);
    }
    else
        return ;
    
}
void    right_move(t_map *map)
{
    if (map->full_map[map->player_y][map->player_x + 1] != 1)
    {
        map->full_map[map->player_y][map->player_x + 1] = 'P';
        // map->full_map[map->player_y][map->player_x] = '0';
        draw_map(map);
    }
    else
        return ;
    
}
void    left_move(t_map *map)
{
    if (map->full_map[map->player_y][map->player_x - 1] != 1)
    {
        map->full_map[map->player_y][map->player_x - 1] = 'P';
        // map->full_map[map->player_y][map->player_x] = '0';
        draw_map(map);
    }
    else
        return ;
    
}

void move(mlx_key_data_t keycode, void *param)
{
    t_map   *map;
    map = param;
    if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
    {
       up_move(map);
    } 
    if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
    {
       down_move(map);
    } 
    if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
    {
       right_move(map);
    } 
    if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
    {
       left_move(map);
    } 
}