/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:35:48 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/15 00:29:53 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_print_program_name(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	write(1, str, i);
// 	write(1, "\n", 1);
// }

int	main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	
	(void)argc;
	// ft_print_program_name(argv[0]);
	while (argv[i][j] != '\0')
	{
		write(1, &argv[i][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
