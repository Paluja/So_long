/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:42 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 19:40:05 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    free_matrix(char **str)
{
    char **tmp;

    tmp = str;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(str);
}

// void free_full_map(t_map *map) {
//     char **temp = map->full_map;
//     while (*temp) {
//         free(*temp);
//         temp++;
//     }
//     free(map->full_map);
// }