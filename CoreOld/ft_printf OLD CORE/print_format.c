/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:25:40 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/19 12:15:58 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pointer(va_list *ap)
{
	unsigned long long	ptr;
	int					count;

	ptr = (unsigned long long)va_arg(*ap, void *);
	if (ptr == 0)
		return (write (1, "0x0", 3));
	count = write (1, "0x", 2);
	return (count + print_unsigned(ptr, 16, 0));
}

static int	handle_unsigned(char specifier, va_list *ap)
{
	unsigned int	n;
	int				is_upper;

	n = va_arg(*ap, unsigned int);
	is_upper = (specifier == 'X');
	if (specifier == 'u')
		return (print_unsigned((unsigned long long)n, 10, 0));
	return (print_unsigned((unsigned long long)n, 16, is_upper));
}

int	print_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(*ap, char *));
	else if (specifier == 'p')
		count += handle_pointer(ap);
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(*ap, int)), 10);
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		count += handle_unsigned(specifier, ap);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write (1, &specifier, 1);
	return (count);
}
