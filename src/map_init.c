/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:55 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 19:06:01 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    gets_wdith_height(t_map *map)
{
    int i;

    i = 0;
    map->width = ft_strlen(map->full_map[i]);
    while (map->full_map[i])
        i++;
    map->height = i;
}

void get_player_pos(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (map->full_map[++y])
    {
        x = 0;
        while(map->full_map[y][++x])
        {
            if (map->full_map[y][x] == 'P')
            {
                map->player_x = x;
                map->player_y = y;
            }        
        }
    }
}

void get_exit_pos(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (map->full_map[++y])
    {
        x = 0;
        while(map->full_map[y][++x])
        {
            if (map->full_map[y][x] == 'E')
            {
                map->exit_x = x;
                map->exit = y;
            }        
        }
    }
}

void get_objects(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (map->full_map[++y])
    {
        x = 0;
        while(map->full_map[y][++x])
        {
            if (map->full_map[y][x] == 'C')
            {
                map->obj++;
            }        
        }
    }
}


void init_map(t_map *map, char **argv)
{
    map->full_map = read_map(argv[1]);
    map->ops_map = read_map(argv[1]);
    gets_wdith_height(map);
    get_player_pos(map);
    get_exit_pos(map);
    get_objects(map);
}



