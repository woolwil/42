/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:24 by ngvo              #+#    #+#             */
/*   Updated: 2025/12/09 16:52:24 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	str = (char *)malloc(len1 + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	if (s1)
		free((void *)s1);
	return (str);
}
