/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:48:10 by fgalan-n          #+#    #+#             */
/*   Updated: 2023/01/19 11:31:10 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_file_reader(int fd, char *buffer)
{
	int		bytes;
	char	*aux;

	aux = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!aux)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(aux);
			return (NULL);
		}
		aux[bytes] = '\0';
		buffer = ft_strjoin(buffer, aux);
		if (ft_strchr(aux, '\n'))
			break ;
	}
	free(aux);
	return (buffer);
}

char	*ft_upcoming_buffer(char *buffer)
{
	int		aux;
	int		xua;
	char	*backup;

	aux = 0;
	xua = 0;
	while (buffer[aux] && buffer[aux] != '\n')
		aux++;
	if (!buffer[aux])
	{
		free(buffer);
		return (NULL);
	}
	backup = ft_calloc(ft_strlen(buffer) - aux + 1, sizeof(char));
	if (!backup)
		return (NULL);
	aux++;
	while (buffer[aux])
	{
		backup[xua] = buffer[aux];
		aux++;
		xua++;
	}
	free(buffer);
	return (backup);
}

char	*ft_new_line(char *buffer)
{
	char	*backup;
	int		aux;

	aux = 0;
	if (!buffer[aux])
		return (NULL);
	while (buffer[aux] && buffer[aux] != '\n')
		aux++;
	backup = ft_calloc(aux + 2, sizeof(char));
	if (!backup)
		return (NULL);
	aux = 0;
	while (buffer[aux] && buffer[aux] != '\n')
	{
		backup[aux] = buffer[aux];
		aux++;
	}
	if (buffer[aux] && buffer[aux] == '\n')
		backup[aux] = '\n';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*static_buffer[1024];

	if (!static_buffer[fd])
		static_buffer[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer[fd] = ft_file_reader(fd, static_buffer[fd]);
	if (!static_buffer[fd])
		return (NULL);
	buffer = ft_new_line(static_buffer[fd]);
	static_buffer[fd] = ft_upcoming_buffer(static_buffer[fd]);
	return (buffer);
}
