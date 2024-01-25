/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:29 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/25 22:26:35 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;
	int	x = 0;
	int	y = 0;
	map = malloc(sizeof(t_map));
	if (argc > 1)
		valid_map(map,argv);
	while (map->full_map[y])
    {
        x = 0;
        while(map->full_map[y][x])
        {
           ft_printf("%c",map->full_map[y][x]);
            x++;
        }
        y++;
    }
    free(map);
	return (0);	
}



