/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:29 by pjimenez          #+#    #+#             */
/*   Updated: 2024/02/06 16:13:01 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char	**read_map(char *argv)
{
	int		fd;
	char	map[1001];
	char	**splited_map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error de lectura de mapa\n");
		exit(1);
	}
	map[read(fd, map, 1000)] = 0;
	close(fd);
	splited_map = ft_split(map, '\n');
	if (!chars_ok(splited_map) || !items_ok(map))
	{
		ft_printf("Caracteres del mapa incorrectos\n");
		free_matrix(splited_map);
		exit(1);
	}
	return (splited_map);
}

int	its_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'r')
		return (0);
	else if (file[i - 2] != 'e')
		return (0);
	else if (file[i - 3] != 'b')
		return (0);
	else if (file[i - 4] != '.')
		return (0);
	return (1);
}

// void    ft_leaks()
// {
//     system("leaks SO_LONG");
// }

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc > 1)
	{
		if (its_ber(argv[1]))
		{
			map = malloc(sizeof(t_map));
			init_map(map, argv);
		}
		else
		{
			perror("Extension o archivo incorrecta");
			exit(1);
		}
		if (valid_map(map))
			execute_game(map);
		else
			ft_printf("Mapa incorrecto\n");
		free_things(map);
	}
	return (EXIT_SUCCESS);
}
