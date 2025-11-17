/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:22:58 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/13 16:32:24 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] != '\0' && s2[n] != '\0')
	{
		n++;
	}
	return (s1[n] - s2[n]);
}

int	main(void)
{
	char s1[] = "cats";
	char s2[] = "catsdogs";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("result: %d\n", ft_strcmp(s1, s2));
	return (0);
}
