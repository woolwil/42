/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:03:26 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:03:26 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	n;
	int	capnext;

	n = 0;
	capnext = 1;
	while (str[n] != '\0')
	{
		if (capnext && (str[n] >= 'a' && str[n] <= 'z'))
			str[n] -= 32;
		else if (!capnext && (str[n] >= 'A' && str[n] <= 'Z'))
			str[n] += 32;
		if (str[n] < '0' || (str[n] > '9' && str[n] < 'A')
			|| (str[n] > 'Z' && str[n] < 'a')
			|| str[n] > 'z')
			capnext = 1;
		else
		{
			capnext = 0;
		}
		n++;
	}
	return (str);
}

// int	main(void)
// {
// 	// char	str[100] = "hi, how are you? 42words forty-two; fifty+and+one";
// 	char	str[100] = "HI, HOW ARE YOU? 42WORDS FORTY-TWO; FIFTY+AND+ONE";
// 	printf("%s\n", ft_strcapitalize(str));
// 	return (0);
// }
