/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:29 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/02 18:11:20 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char    **read_map(char *argv)
{
    int     fd;
    char    map[1001];
    char **splited_map;
    fd = open(argv,O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error de lectura de mapa\n");
        exit(1);
    }
    map[read(fd,map,1000)] = 0;
    close(fd);
    splited_map = ft_split(map,'\n');
    if (!chars_ok(splited_map) || !items_ok(map))
    {
        ft_printf("Caracteres del mapa incorrectos\n");
        free_matrix(splited_map);
        exit(1);
    }
    return(splited_map);
}

void    close_win(mlx_key_data_t keycode,void   *param)
{
    t_map *map;
    map = param;
    if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
    {
        mlx_terminate(map->mlx);
        free_things(map);
        exit(EXIT_SUCCESS);
    }
    return ;
}


void    ft_leaks()
{
    system("leaks SO_LONG");
}

int main(int argc, char **argv)
{
    if (argc > 1)
	{
        t_map *map;
        map = malloc(sizeof(t_map));
        init_map(map,argv);
        if (valid_map(map))
        {
            int i = 0;
            while (i <= map->obj)
            {
                ft_printf("X: %d, Y: %d\n",map->obj_x[i],map->obj_y[i]);
                i++;
            }
            map->mlx = mlx_init(map->width * 64, map->height * 64, "Test", true);

            atexit(ft_leaks);
            load_map(map);
            draw_map(map);
            
            mlx_key_hook(map->mlx, &move, map);
            // mlx_key_hook(map->mlx, &close_win, map);
            mlx_loop(map->mlx);
        }
            free_things(map);
    }       


	return (EXIT_SUCCESS);
}