/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:03 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/19 20:32:19 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
// # include "libft/get_next_line/get_next_line.h"


int chars_ok(const char *buffer)
{
    int i;
    int player;
    int obj;
    int exit;

    player = 0;
    exit = 0;
    obj = 0;
    i = 0;
    while (buffer[i])
    {
        if(buffer[i] != '0' && buffer[i] != '1' && buffer[i] != 'C' && buffer[i] != 'E'
        && buffer[i] != 'P' && buffer[i] != '\n')
            return (0);
        //apartir de aqui separar en otra funcion
        if (buffer[i] == 'P')
            player++;
        else if (buffer[i] == 'E')
            exit++;
        else if (buffer[i] == 'C')
            obj++;
        i++;
    }
    if (player!=1 || exit!=1 || !obj)
        return (0);
    return (1);
}

int its_rectangle(char **map)
{
    size_t i;
    size_t height;
    size_t width;

    height = 0;
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
    // j = 0;

    while (map[i])
    {
        j = 0;
        if (map[i][0] != '1') //BIEN
                return (0);
        while (map[i][j])
        {
            if (map[0][j] != '1') //BIEN
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

void valid_map(char **argv)
{
    int fd;
    char buffer[1000];
    char **map;
    fd = open(argv[1],O_RDONLY);

    read(fd,buffer,1000);

    map = ft_split(buffer,'\n');
    if (its_close(map))
        printf("%s",buffer);


    // if (chars_ok(buffer))
    //     ft_printf("%s\n",buffer);




    // ft_printf("%d\n",its_rectangle(fd));
}