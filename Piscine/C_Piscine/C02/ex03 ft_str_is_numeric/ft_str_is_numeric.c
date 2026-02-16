/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:57:08 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:01:24 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", ft_str_is_numeric(""));
	printf("%d\n", ft_str_is_numeric("1234567890"));
	printf("%d\n", ft_str_is_numeric("#@!"));
	printf("%d\n", ft_str_is_numeric("abc"));
	printf("%d\n", ft_str_is_numeric("a1b2c"));
	printf("%d\n", ft_str_is_numeric("1a2b3c"));
	printf("%d\n", ft_str_is_numeric("-1234567890"));
	printf("%d\n", ft_str_is_numeric("12345!@#$"));
	return (0);
}
