/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:25:40 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/19 02:25:40 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list *ap)
{
	int					count;
	int					is_upper;
	unsigned long long	ptr;

	count = 0;
	is_upper = 0;
	if (specifier == 'c')
		count += print_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(*ap, char *));
	else if (specifier == 'p')
	{
		ptr = (unsigned long long)va_arg(*ap, void *);
		if (ptr == 0)
			return (write (1, "0x0", 3));
		else
		{
			count += write (1, "0x", 2);
			count += print_unsigned((unsigned long long)ptr, 16, 0);
		}
	}
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(*ap, int)), 10);
	else if (specifier == 'u')
		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 10, 0);
	else if (specifier == 'x')
		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 16, 0);
	else if (specifier == 'X')
	{
		is_upper = 1;
		count += print_unsigned((unsigned long long)(va_arg(*ap, unsigned int)), 16, is_upper);
	}
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write (1, &specifier, 1);
	return (count);
}