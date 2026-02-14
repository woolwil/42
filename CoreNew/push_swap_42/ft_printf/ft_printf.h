/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:28:07 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/19 02:28:07 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_char(int c);

int	print_str(char *str);

int	print_unsigned(unsigned long long n, int base, int is_upper);

int	print_digit(long n, int base);

int	print_format(char specifier, va_list *ap);

int	ft_printf(const char *format, ...);

#endif