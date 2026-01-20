/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:23:23 by ngvo              #+#    #+#             */
/*   Updated: 2026/01/20 00:23:23 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	read_to_stash(int fd, char *stash);
char	extract_line(int fd, char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}

char	read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		{
			free(stash);
			return (NULL);
		}
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free (buff);
	return (stash);
}

char	extract_line(int fd, char *stash)
{

}
