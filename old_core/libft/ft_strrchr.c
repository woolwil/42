/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:32:48 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/11 19:30:12 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = ft_strlen(s);
	while (1)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)(s + i));
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
