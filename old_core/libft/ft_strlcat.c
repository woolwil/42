/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:32:20 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/17 11:53:31 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	dest_len = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (dest[dest_len] != '\0')
		dest_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (src[j] != '\0' && (dest_len + j + 1) < size)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	if (dest_len < size)
		dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}
