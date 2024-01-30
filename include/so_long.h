/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:16:40 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 19:25:58 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#include "../src/libft/libft.h"
#include "../src/MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
# define SO_LONG_H

typedef struct  s_map
{
    char    **full_map;
    char    **ops_map;
    int     width;
    int     height;
    int		player_x;
    int		player_y;
	int		exit_x;
	int		exit_y;
    int     player;
    int     exit;
    int     obj;
    
}	t_map;

int valid_map(t_map *map);
void init_map(t_map *map, char **argv);
char    **read_map(char *argv);
int items_ok(char *map);
int chars_ok(char **map);
int its_rectangle(t_map *map);
int its_close(t_map *map);
void init_map(t_map *map, char **argv);
void    free_matrix(char **str);
void free_full_map(t_map *map);
void    gets_wdith_height(t_map *map);
void	flood_fill(t_map *map, int row, int col);
void init_map(t_map *map, char **argv);
#endif