/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:07 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/13 14:53:48 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	len1;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	str = (char *)malloc(len1 + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 		str[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		str[j++] = s2[i++];
// 	str[j] = '\0';
// 	if (s1)
// 		free((void *)s1);
// 	return (str);
// }