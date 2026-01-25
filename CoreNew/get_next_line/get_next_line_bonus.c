/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:14:14 by ngvo              #+#    #+#             */
/*   Updated: 2026/01/24 19:10:09 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buff[bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free (buff);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;
	int		len;

	if (!ft_strchr(stash, '\n'))
	{
		free (stash);
		return (NULL);
	}
	i = ft_strchr(stash, '\n') - stash;
	j = 0;
	len = ft_strlen(stash + i + 1);
	new_stash = malloc(len + 1);
	i++;
	while (stash[i] && stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free (stash);
	return (new_stash);
}
