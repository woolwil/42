/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:06:43 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/19 02:45:06 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_char(int c)
// {
// 	return (write (1, &c, 1));
// }

// int	print_unsigned(unsigned long long n, int base, int is_upper)
// {
// 	int			count;
// 	const char	*lo;
// 	const char	*up;

// 	lo = "0123456789abcdef";
// 	up = "0123456789ABCDEF";
// 	if (base < 2)
// 		return (-1);
// 	if (n < (unsigned long long)base)
// 	{
// 		if (is_upper)
// 			return (print_char(up[n]));
// 		else
// 			return (print_char(lo[n]));
// 	}
// 	count = print_unsigned(n / base, base, is_upper);
// 	return (count + print_unsigned(n % base, base, is_upper));
// }

// int	print_str(char *str)
// {
// 	int	count;

// 	count = 0;
// 	if (!str)
// 		return (write(1, "(null)", 6));
// 	while (*str)
// 	{
// 		print_char((int)*str);
// 		++count;
// 		++str;
// 	}
// 	return (count);
// }

// int	print_digit(long n, int base)
// {
// 	int		count;
// 	char	*low;

// 	low = "0123456789abcdef";
// 	if (base < 2)
// 		return (-1);
// 	if (n < 0)
// 	{
// 		write (1, "-", 1);
// 		return (print_digit(-n, base) + 1);
// 	}
// 	if (n < base)
// 		return (print_char(low[n]));
// 	else
// 	{
// 		count = print_digit(n / base, base);
// 		return (count + print_digit(n % base, base));
// 	}
// }

// int	print_format(char specifier, va_list *ap)
// {
// 	int					count;
// 	int					is_upper;
// 	unsigned long long	ptr;

// 	count = 0;
// 	is_upper = 0;
// 	if (specifier == 'c')
// 		count += print_char(va_arg(*ap, int));
// 	else if (specifier == 's')
// 		count += print_str(va_arg(*ap, char *));
// 	else if (specifier == 'p')
// 	{
// 		ptr = (unsigned long long)va_arg(*ap, void *);
// 		if (ptr == 0)
// 			return (write (1, "0x0", 3));
// 		else
// 		{
// 			count += write (1, "0x", 2);
// 			count += print_unsigned((unsigned long long)ptr, 16, 0);
// 		}
// 	}
// 	else if (specifier == 'd' || specifier == 'i')
// 		count += print_digit((long)(va_arg(*ap, int)), 10);
// 	else if (specifier == 'u')
// 		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 10, 0);
// 	else if (specifier == 'x')
// 		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 16, 0);
// 	else if (specifier == 'X')
// 	{
// 		is_upper = 1;
// 		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 16, is_upper);
// 	}
// 	else if (specifier == '%')
// 		count += write(1, "%", 1);
// 	else
// 		count += write (1, &specifier, 1);
// 	return (count);
// }

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), &ap);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	total = 0;
// 	int	len;
// 	len = ft_printf("c: %c\n", 'A');                       total += len;
// 	len = ft_printf("s: %s\n", "hello");                   total += len;
// 	len = ft_printf("p: %p\n", (void *)0x1234abcd);        total += len;
// 	len = ft_printf("d: %d\n", -42);                       total += len;
// 	len = ft_printf("i: %i\n", 123);                       total += len;
// 	len = ft_printf("u: %u\n", 4294967295u);               total += len;
// 	len = ft_printf("x: %x\n", 3735928559u);               total += len;
// 	len = ft_printf("X: %X\n", 3735928559u);               total += len;
// 	len = ft_printf("percent: %%\n");                      total += len;
// 	ft_printf("Total printed across all calls: %d\n", total);
// 	len = ft_printf("Just this string\n");
// 	ft_printf("Length of previous output: %d\n", len);
// 	return 0;
// }
