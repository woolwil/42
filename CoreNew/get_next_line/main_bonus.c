/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:30:00 by ngvo              #+#    #+#             */
/*   Updated: 2026/01/25 17:28:50 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

void	print_and_free(char *prefix, char *line)
{
	if (line)
	{
		printf("%s%s", prefix, line);
		free(line);
	}
}

void	open_files(int *fd1, int *fd2, int *fd3)
{
	*fd1 = open("file1.txt", O_RDONLY);
	*fd2 = open("file2.txt", O_RDONLY);
	*fd3 = open("file3.txt", O_RDONLY);
}

void	close_files(int fd1, int fd2, int fd3)
{
	close(fd1);
	close(fd2);
	close(fd3);
}

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	i;

	open_files(&fd1, &fd2, &fd3);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("open");
		return (1);
	}
	printf("--- Alternating reads from 3 files ---\n");
	i = 0;
	while (i < 4)
	{
		print_and_free("[file1] ", get_next_line(fd1));
		print_and_free("[file2] ", get_next_line(fd2));
		print_and_free("[file3] ", get_next_line(fd3));
		i++;
	}
	close_files(fd1, fd2, fd3);
	return (0);
}
