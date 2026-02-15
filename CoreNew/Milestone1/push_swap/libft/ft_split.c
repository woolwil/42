/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:25 by ngvo              #+#    #+#             */
/*   Updated: 2025/11/14 14:23:18 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free_all(char **s, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*ft_split_word(char const *s, char c, size_t *s_idx)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[*s_idx] && s[*s_idx] == c)
		(*s_idx)++;
	while (s[len + *s_idx] != '\0' && s[len + *s_idx] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*s_idx + i];
		i++;
	}
	word[i] = '\0';
	*s_idx += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**split_arr;
	size_t	i;
	size_t	s_idx;

	if (!s)
		return (NULL);
	i = 0;
	s_idx = 0;
	word_count = ft_count_words(s, c);
	split_arr = malloc((word_count + 1) * sizeof(*split_arr));
	if (!split_arr)
		return (NULL);
	while (i < word_count)
	{
		split_arr[i] = ft_split_word(s, c, &s_idx);
		if (!split_arr[i])
		{
			ft_free_all(split_arr, i);
			return (NULL);
		}
		i++;
	}
	split_arr[i] = NULL;
	return (split_arr);
}
