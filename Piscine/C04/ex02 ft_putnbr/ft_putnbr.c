/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:47:49 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/20 00:33:55 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc < 2)
	{
		int number = -2025;
		ft_putnbr(number);
		ft_putchar('\n');
		return (0);
	}
	else if (argc == 2)
	{
		while (argv[1][j] != '\0')
		{
			ft_putchar(argv[1][j]);
			j++;
		}
		ft_putchar('\n');
	}
}