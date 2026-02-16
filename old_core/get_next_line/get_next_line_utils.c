/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:26:13 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/25 23:00:26 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

char	*extract_line(char **remainder_ptr)
{
	size_t	line_len;
	char	*newline_ptr;
	char	*line_to_return;

	if (!*remainder_ptr)
		return (NULL);
	newline_ptr = ft_strchr(*remainder_ptr, '\n');
	if (newline_ptr)
		line_len = (newline_ptr - *remainder_ptr) + 1;
	else
		line_len = ft_strlen(*remainder_ptr);
	line_to_return = malloc(line_len + 1);
	if (!line_to_return)
		return (NULL);
	ft_memcpy(line_to_return, *remainder_ptr, line_len);
	line_to_return[line_len] = '\0';
	free(*remainder_ptr);
	if (newline_ptr)
		**remainder_ptr = ft_strdup(newline_ptr + 1);
	else
		**remainder_ptr = NULL;
	return (line_to_return);
}

char	*read_and_join(int fd, char *remainder, char *buffer, size_t nbyte)
{
	char	*temp_old;
	size_t	bytesread;

	bytesread = 1;
	while (ft_strchr(remainder, '\n') == NULL)
	{
		bytesread = read(fd, buffer, nbyte);
		if (bytesread <= 0)
		{
			if (bytesread == -1)
			{
				free(remainder);
				return (NULL);
			}
			break ;
		}
		buffer[bytesread] = '\0';
		temp_old = remainder;
		remainder = ft_strjoin(temp_old, buffer);
		if (temp_old)
			free(temp_old);
	}
	return (remainder);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == src || n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (s2);
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