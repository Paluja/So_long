/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:42 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/01 17:00:34 by pjimenez         ###   ########.fr       */
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

void    free_matrix(char **str)
{
    char **tmp;

    tmp = str;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(str);
}

void    free_things(t_map *map)
{
    free_matrix(map->full_map);
    free_matrix(map->ops_map);
    free(map->obj_x);
    free(map->obj_y);
    free(map);
	mlx_terminate(map->mlx);
}


// void free_full_map(t_map *map) {
//     char **temp = map->full_map;
//     while (*temp) {
//         free(*temp);
//         temp++;
//     }
//     free(map->full_map);
// }