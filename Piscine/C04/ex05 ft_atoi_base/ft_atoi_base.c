/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:49:55 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/18 00:00:00 by nyevonam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	valid_base(char *base)
{
	int		len;
	int		i;
	int		j;
	char	c;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		c = base[i];
		if (c == '+' || c == '-' || is_space(c))
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		blen;
	int		i;
	int		sign;
	long	result;
	int		idx;

	blen = valid_base(base);
	if (!blen)
		return (0);
	i = 0;
	while (str && is_space(str[i]))
		i++;
	sign = 1;
	while (str && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			sign = -sign;
	result = 0;
	idx = index_in_base(str[i], base);
	while (str && idx != -1)
	{
		result = result * blen + idx;
		idx = index_in_base(str[++i], base);
	}
	return ((int)(result * sign));
}
