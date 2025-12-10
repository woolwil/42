/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:33 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/15 16:09:36 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;
	long	nb;

	nb = (long)n;
	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static long	ft_abs_value(int n, int *is_negative)
{
	long	nb;

	nb = (long)n;
	*is_negative = 0;
	if (nb < 0)
	{
		*is_negative = 1;
		nb = -nb;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;
	int		is_negative;

	len = ft_numlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	nb = ft_abs_value(n, &is_negative);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
