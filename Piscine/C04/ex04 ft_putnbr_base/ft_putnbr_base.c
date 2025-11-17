/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:48:35 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/13 11:48:33 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		blen; // base length
	long	num;
	char	c;

	blen = 0;
	while (base[blen])
		blen++;
	if (blen < 2)
		return ;
	num = nbr;
	if (num < 0)
	{
		putchar('-');
		num = -num;
	}
	if (num >= blen)
		ft_putnbr_base(num / blen, base);
	c = base[num % blen];
	putchar(c);
}

int	main(void)
{
	ft_putnbr_base(42, "0123456789ABCDEF");
	ft_putnbr_base(-42, "0123456789ABCDEF");
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	ft_putnbr_base(255, "01");
	ft_putnbr_base(-255, "01");
	ft_putnbr_base(2147483647, "01");
	ft_putnbr_base(-2147483648, "01");
	ft_putnbr_base(0, "0123456789");
	ft_putnbr_base(-0, "0123456789");
	ft_putnbr_base(100, "0123456789");
	ft_putnbr_base(-100, "0123456789");
	ft_putnbr_base(2147483647, "0123456789");
	ft_putnbr_base(-2147483648, "0123456789");
	ft_putnbr_base(123456, "poneyvif");
	ft_putnbr_base(-123456, "poneyvif");
	ft_putnbr_base(42, "");
	ft_putnbr_base(42, "0");
	ft_putnbr_base(42, "01234+6789");
	ft_putnbr_base(42, "01234456789");
	return (0);
}