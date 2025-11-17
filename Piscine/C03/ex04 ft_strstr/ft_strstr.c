/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:32:55 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/15 00:10:54 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{	
		j = 0;
		while (to_find[j] != '\0' && (to_find[j] == str[i + j]))
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	str[100] = "hair enjoyer, yes i love my hair, i love yours too";
	char	to_find[100] = "enjoyer";

	printf("str: %s\n", str);
	printf("to_find: %s\n", to_find);
	char *result = ft_strstr(str, to_find);
	printf("strstr: %s\n", result);
	return (0);
}
