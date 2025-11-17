/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:14:15 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:00:47 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_lowercase("abcdefg"));
// 	printf("%d\n", ft_str_is_lowercase("abcdEFG"));
// 	printf("%d\n", ft_str_is_lowercase("abcd!#@"));
// 	printf("%d\n", ft_str_is_lowercase(""));
// 	printf("%d\n", ft_str_is_lowercase("123456"));
// 	printf("%d\n", ft_str_is_lowercase("ABCDEFG"));
// 	printf("%d\n", ft_str_is_lowercase("!@#$*^"));
// 	printf("%d\n", ft_str_is_lowercase("   "));
// return (0);
// }
