/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:03 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/25 23:11:15 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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





int its_rectangle(char **map)
{
    size_t i;
    // size_t height;
    size_t width;

    // height = 0;
    i = 0;
    width = ft_strlen(map[0]);
    while (map[i])
    {
        if (width != ft_strlen(map[i]))
            return(0);
        i++;
    }
    if (i == width)
        return (0);
    return (1);
}

int its_close(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        if (map[i][0] != '1')
                return (0);
        while (map[i][j])
        {
            if (map[0][j] != '1')
                return (0);
            j++;
        }
        if (map[i][j - 1] != '1')
            return(0);
        i++;
    }
    j = 0;
    while (map[i - 1][j])
    {
        if (map[i - 1][j] != '1')
            return(0);
        j++;
    }
    return (1);
}

// int gls(t_map map)
// {
//     init_map(&map);
    
// }



void init_map(t_map *map, char **argv)
{
    int y;
    int x;   
    y = 0;
    x = 0;

    map->full_map = read_map(argv[1]);
    while (map->full_map[y])
    {
        x = 0;
        while(map->full_map[y][x])
        {
            if (map->full_map[y][x] == 'P')
            {
                map->player_x = x;
                map->player_y = y;
            }
            else if (map->full_map[y][x] == 'E')
            {
                map->exit_x = x;
                map->exit_y = y;
            }
            x++;
        }
        y++;
    }
}



void valid_map(t_map *map, char **argv)
{
    char **matrix_map;

    matrix_map = read_map(argv[1]);
    if(its_close(matrix_map) && its_rectangle(matrix_map))
        init_map(map,argv);
    free_matrix(matrix_map);
    
}