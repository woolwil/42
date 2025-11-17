/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:41:20 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/12 15:14:47 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] >= 'a' && str[n] <= 'z')
		{
			str[n] -= 32;
		}
		n++;
	}
	return (str);
}

int	main(void)
{
	char	str[100] = "HeLLo42";
	char	str1[100] = "hello";
	char	str2[100] = "alreadyUPPER";
	char	str3[100] = "";
	printf("%s\n", ft_strupcase(str));
	printf("%s\n", ft_strupcase(str1));
	printf("%s\n", ft_strupcase(str2));
	printf("%s\n", ft_strupcase(str3));
	return (0);
}
