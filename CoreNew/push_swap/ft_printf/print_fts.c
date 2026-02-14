/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:21:49 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/19 02:21:49 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write (1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_unsigned(unsigned long long n, int base, int is_upper)
{
	int			count;
	const char	*lo;
	const char	*up;

	lo = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (base < 2)
		return (-1);
	if (n < (unsigned long long)base)
	{
		if (is_upper)
			return (print_char(up[n]));
		else
			return (print_char(lo[n]));
	}
	count = print_unsigned(n / base, base, is_upper);
	return (count + print_unsigned(n % base, base, is_upper));
}

int	print_digit(long n, int base)
{
	int		count;
	char	*low;

	low = "0123456789abcdef";
	if (base < 2)
		return (-1);
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	if (n < base)
		return (print_char(low[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}
