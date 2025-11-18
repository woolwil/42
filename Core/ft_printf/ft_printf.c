/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:06:43 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/18 19:41:16 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	print_char(int c)
{
	return (write (1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char((int)*str + count);
		count++;
	}
	return (count);
}

// int	print_digit(long n, base)
// {
// }

int	print_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
	{
		count += print_char (va_arg(*ap, int));
	}
	else if (specifier == 's')
	{
		count += print_str (va_arg(*ap, char *));
	}
	// else if (specifier == 'd')
	// {
	// 	count += print_digit (va_arg(ap, int));
	// }
	// else if (specifier == 'x')
	// {
	// 	count += print_digit (va_arg(ap, unsigned int));
	// }
	else
		count += write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;

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

int	main(void)
{
	ft_printf("%s", "hello");
	return (0);
}