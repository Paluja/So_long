/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:42 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:47 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	gets_wdith_height(t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map->full_map[i]);
	while (map->full_map[i])
		i++;
	map->height = i;
}

void	free_matrix(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
}

void	finish_game(t_map *map)
{
	ft_printf("¡LLegaste a Andorra!, elusion fiscal conseguida \n");
	mlx_terminate(map->mlx);
	free_things(map);
	exit(EXIT_SUCCESS);
}

void	load_exit(t_map *map, int x, int y)
{
	map->exit_x = x;
	map->exit_y = y;
	mlx_image_to_window(map->mlx, map->img_exit, x * 64, y * 64);
}
