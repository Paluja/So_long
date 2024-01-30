/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:29 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 19:40:27 by pjimenez         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (argc > 1)
	{
        init_map(map,argv);
        
        if (valid_map(map))
        {
            ft_printf("Width: %d\n",map->width);
            ft_printf("Height: %d\n",map->height);
            ft_printf("Objetos: %d\n",map->obj);
        }
        free_matrix(map->full_map);
        free_matrix(map->ops_map);
        free(map);
        
    }
    
	return (0);	
}
