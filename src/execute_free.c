/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:49 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:52 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	execute_game(t_map *map)
{
	map->mlx = mlx_init(map->width * 64, map->height * 64, "Gombling",
			true);
	load_map(map);
	draw_map(map);
	mlx_key_hook(map->mlx, &move, map);
	mlx_loop(map->mlx);
}

void	free_things(t_map *map)
{
	free_matrix(map->full_map);
	free_matrix(map->ops_map);
	free(map->obj_x);
	free(map->obj_y);
	free(map);
}
