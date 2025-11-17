/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:21:44 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/10 01:03:43 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int j;
	unsigned int dest_len;
	unsigned int src_len;
	
	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
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

int	main(void)
{
	int n = 0;

	char dest[100] = "i wanna go home, ";
	char src[100] = "let me go home";
	while (src[n] != '\0')
	{
		n++;
	}
	printf("Dest: %s\n", dest);
	printf("Src: %s\n", src);
	ft_strncat(dest, src, (sizeof(dest) - (strlen(src) - 1)));
	printf("Concatenated output: %s\n", dest);
	return (0);
}
