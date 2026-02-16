/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:08:08 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/10 00:18:27 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t len;
	size_t i;
	char *dest; 
	if (!src)
		return NULL;
	len = 0;
	while (src[len])
		len++;
	dest = malloc((len + 1) * sizeof *dest);
	if (!dest)
		return NULL;
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char src[100] = "une vie a t'aimer\n";
	char *dup = ft_strdup(src);
	if (!dup)
		return (1);
	printf("source: %s", src);
	printf("strdup: %s", dup);
	free(dup);	
	return (0);
}
