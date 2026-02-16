/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:22:13 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:01:05 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", ft_str_is_uppercase(""));
	printf("%d\n", ft_str_is_uppercase("ABCDEFGH"));
	printf("%d\n", ft_str_is_uppercase("ABCD!@#$"));
	printf("%d\n", ft_str_is_uppercase("abcde!@#$"));
	printf("%d\n", ft_str_is_uppercase("!@#$abcd"));
	printf("%d\n", ft_str_is_uppercase("    "));
	printf("%d\n", ft_str_is_uppercase("....."));
	return (0);
}
