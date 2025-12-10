/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:26:06 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/25 23:00:26 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
char	*extract_line(char **remainder_ptr);
char	*read_and_join(int fd, char *remainder, char *buffer, size_t nbyte);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif
