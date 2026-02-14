/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:32:41 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/11 19:30:03 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			len;
	unsigned char	uc;

	len = 0;
	uc = (unsigned char)c;
	while (s[len] != '\0')
	{
		if ((unsigned char)s[len] == uc)
			return ((char *)(&(s[len])));
		len++;
	}
	if (uc == '\0')
		return ((char *)(&(s[len])));
	return (NULL);
}
