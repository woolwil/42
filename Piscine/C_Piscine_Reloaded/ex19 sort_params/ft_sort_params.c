/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:41:20 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/07 20:50:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	sort_params(int argc, char **argv)
{
    int		i;
    int		j;
    int		p;
    char	*tmp;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            p = 0;
            while (argv[i][p] && argv[j][p] && argv[i][p] == argv[j][p])
                p++;
            if (argv[i][p] > argv[j][p])
            {
                tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int	main(int argc, char **argv)
{
    int	i;
    int	k;

    sort_params(argc, argv);
    i = 1;
    while (i < argc)
    {
        k = 0;
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
