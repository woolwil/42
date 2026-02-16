/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:33:15 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/16 19:16:56 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len < little_len)
		return (NULL);
	i = 0;
	while (i + little_len <= len && big[i])
	{
		if (ft_memcmp(big + i, little, little_len) == 0)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
