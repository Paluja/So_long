/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:42 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/05 18:49:57 by pjimenez         ###   ########.fr       */
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
	ft_printf("¡Ganaste!, Ahora eres un Goblin libre de impuestos\n");
	mlx_terminate(map->mlx);
	free_things(map);
}

void	free_things(t_map *map)
{
	free_matrix(map->full_map);
	free_matrix(map->ops_map);
	free(map->obj_x);
	free(map->obj_y);
	free(map);
}
