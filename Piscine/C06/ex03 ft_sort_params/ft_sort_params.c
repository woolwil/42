/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:15:17 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/15 00:47:14 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char *argv[])
{
    int		i;
    int		j;
    char	*temp;

    i = 1;
    if (argc < 2)
        return (0);
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            int p = 0;
            int cmp = 0;
            while (argv[i][p] && argv[j][p] && argv[i][p] == argv[j][p])
                p++;
            cmp = argv[i][p] - argv[j][p];
            if (cmp > 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
            j++;
        }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        int k = 0;
        while (argv[i][k])
        {
            ft_putchar(argv[i][k]);
            k++;
        }
        ft_putchar('\n');
        i++;
    }
    return (0);
}