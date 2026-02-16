/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:05:31 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/05 20:15:31 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
// {
// 	write(1, &c, 1);
// }

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}

// int	main(void)
// {
// 	int a = 1;
// 	int b = -1;
// 	int	c = 0;
// 	ft_is_negative(a);
// 	ft_is_negative(b);
// 	ft_is_negative(c);
// 	return (0);
// }