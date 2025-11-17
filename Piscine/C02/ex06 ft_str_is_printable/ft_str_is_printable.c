/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:31:34 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:02:24 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_printable(""));
// 	printf("%d\n", ft_str_is_printable("ABCDEFGH"));
// 	printf("%d\n", ft_str_is_printable("abcdefgh"));
// 	printf("%d\n", ft_str_is_printable("!@#$"));
// 	printf("%d\n", ft_str_is_printable("....."));
// 	printf("%d\n", ft_str_is_printable("    "));
// 	printf("%d\n", ft_str_is_printable("\n"));
//	return (0);
// }