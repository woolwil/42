/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:06 by ngvo              #+#    #+#             */
/*   Updated: 2026/01/24 18:31:18 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_BONUS
# define GET_NEXT_LINE_H_BONUS

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  error "BUFFER SIZE MUST BE A POSITIVE INTEGER"
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

#endif