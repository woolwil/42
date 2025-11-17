/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:49:55 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/13 11:01:07 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	valid_base(char *base)
{
	int len = ft_strlen(base);
	if (len < 2)
		return (0);
	for (int i = 0; i < len; i++)
	{
		char c = base[i];
		if (c == '+' || c == '-' || is_space(c))
			return (0);
		for (int j = i + 1; j < len; j++)
			if (base[j] == c)
				return (0);
	}
	return (len);
}

int	index_in_base(char c, char *base)
{
	for (int i = 0; base[i]; i++)
		if (base[i] == c)
			return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int blen;
	int i;
	int sign;
	int idx;
	long result;

	blen = valid_base(base);
	if (!blen)
		return (0);
	i = 0;
	while (str && is_space(str[i]))
		i++;
	sign = 1;
	while (str && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	idx = index_in_base(str[i], base);
	if (idx == -1)
		return (0);
	while (str && (idx = index_in_base(str[i], base)) != -1)
	{
		result = result * blen + idx;
		i++;
	}
	return ((int)(result * sign));
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("42", "0123456789"));
	printf("%d\n", ft_atoi_base("  \t\n   -2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("101010", "01"));
	printf("%d\n", ft_atoi_base("-101010", "01"));
	/* invalid bases -> should print 0 */
	printf("%d\n", ft_atoi_base("42", ""));
	printf("%d\n", ft_atoi_base("42", "0"));
	printf("%d\n", ft_atoi_base("42", "01234+6789"));
	printf("%d\n", ft_atoi_base("42", "01234456789"));
	return (0);
}
