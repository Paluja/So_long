/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:11:04 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/19 16:00:55 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_lib.h"

char	*new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr_gnl(buffer, '\n');
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	tmp++;
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen_gnl(tmp) + 1));
	if (!new_buffer)
		return (NULL);
	while (*tmp != '\0')
	{
		new_buffer[i] = *tmp;
		tmp++;
		i++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		buffer_tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n_bytes = 1;
	while (!(ft_strchr_gnl(stack, '\n')) && n_bytes > 0)
	{
		n_bytes = read(fd, buffer_tmp, BUFFER_SIZE);
		if (n_bytes < 0)
			return (free(stack), stack = NULL, NULL);
		buffer_tmp[n_bytes] = '\0';
		stack = ini_stack(stack, buffer_tmp);
		if (!stack)
			return (NULL);
	}
	line = new_line(stack);
	stack = update_buffer(stack);
	return (line);
}
