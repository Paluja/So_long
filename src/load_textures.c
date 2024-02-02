/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:31:34 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/02 17:59:11 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    load_map(t_map *map)
{
    mlx_texture_t   *texture;

    texture = mlx_load_png("/Users/pjimenez/Desktop/Ccursus/So_long/src/resized/goblin.png");
    map->img_player = mlx_texture_to_image(map->mlx,texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("/Users/pjimenez/Desktop/Ccursus/So_long/src/resized/gold.png");
    map->img_object = mlx_texture_to_image(map->mlx,texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("/Users/pjimenez/Desktop/Ccursus/So_long/src/resized/path3.png");
    map->img_path = mlx_texture_to_image(map->mlx,texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("/Users/pjimenez/Desktop/Ccursus/So_long/src/resized/Tree.png");
    map->img_wall = mlx_texture_to_image(map->mlx,texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("/Users/pjimenez/Desktop/Ccursus/So_long/src/resized/mine.png");
    map->img_exit = mlx_texture_to_image(map->mlx,texture);
    mlx_delete_texture(texture);
}

void    draw_map(t_map  *map)
{
    int x;
    int y;

    x = 0;
    y = 0;

      while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            mlx_image_to_window(map->mlx,map->img_path, x * 64, y * 64);
            if (map->full_map[y][x] == '1') // wall
                mlx_image_to_window(map->mlx,map->img_wall, x * 64, y * 64);
            // else if (map->full_map[y][x] == '0') // path
            //     mlx_image_to_window(map->mlx,map->img_path, x * 64, y * 64);
            else if (map->full_map[y][x] == 'P') // player
                draw_player(map,y,x);
            else if (map->full_map[y][x] == 'C') // object
                mlx_image_to_window(map->mlx,map->img_object, x * 64, y * 64);
            else if (map->full_map[y][x] == 'E') // exit
                mlx_image_to_window(map->mlx, map->img_exit, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

void draw_player(t_map *map, int y, int x)
{
    mlx_image_to_window(map->mlx, map->img_player, map->player_x * 64, map->player_y * 64);
    map->player_x = x;
    map->player_y = y;
}