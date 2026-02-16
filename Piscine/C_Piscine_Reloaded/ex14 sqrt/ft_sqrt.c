/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:49 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/05 21:23:49 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 0)
		return (0);
	if (nb < 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;
// 	int d = 4;
// 	int e = 5;
// 	int f = 10;
// 	int g = 16;
// 	printf("sqrt(%i) = %i\n", a, ft_sqrt(a));
// 	printf("sqrt(%i) = %i cuz irrational\n", b, ft_sqrt(b));
// 	printf("sqrt(%i) = %i cuz irrational\n", c, ft_sqrt(c));
// 	printf("sqrt(%i) = %i\n", d, ft_sqrt(d));
// 	printf("sqrt(%i) = %i cuz irrational\n", e, ft_sqrt(e));
// 	printf("sqrt(%i) = %i cuz irrational\n", f, ft_sqrt(f));
// 	printf("sqrt(%i) = %i\n", g, ft_sqrt(g));
// 	return (0);
// }