/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:08:51 by codespace         #+#    #+#             */
/*   Updated: 2025/10/16 18:46:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 1 || argc > 2)
	{
		write (1, "use double quotes for string input, and only one parameter\n", 60);	
		return (0);
	}
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (!((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == 32))
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			else
			{
				write (1, "\n", 1);
				return 0;
			}
		}
	}
	return (0);
}