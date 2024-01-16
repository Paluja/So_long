/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:03 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/16 20:11:58 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
    if (!player || !exit || !obj)
        return (0);
    return (1);
}




void valid_map(char **argv)
{
    int fd;
    char buffer[1024];
    fd = open(argv[1],O_RDONLY,0777);
    
    read(fd,buffer,1024);
    if (chars_ok(buffer))
        ft_printf("%s",buffer);
    
}