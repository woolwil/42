/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:38:01 by ngvo              #+#    #+#             */
/*   Updated: 2025/12/14 16:50:51 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
    {
        write(2, "File name missing.\n", 19);
        return (1);
    }
    else if (argc > 2)
    {
        write(2, "Too many arguments.\n", 20);
        return (1);
    }
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot open file.\n", 18);
		return (1);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}
