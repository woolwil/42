/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:26:18 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/25 22:57:09 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>

static char	*remainder;

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*temp_old;
	size_t 	nbyte;
	size_t	bytesread;

	nbyte = 4;
	buffer = malloc(nbyte);
	if (!buffer)
		return (NULL);
	bytesread = 1;
	bytesread = read(fd, buffer, nbyte);
		if (bytesread <= 0)
		{
			if (bytesread == -1)
			{
				free(remainder);
				return (NULL);
			}
			break ;
		}
	temp_old = remainder;
	free(remainder);
	remainder = ft_strjoin(temp_old, buffer);
	read_and_join();
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = malloc(4);
	if (!buffer)
		return (NULL);
	if (read_and_join(fd, remainder, buffer, BUFFER_SIZE) == NULL)
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line(&remainder);
	return (line);
}
