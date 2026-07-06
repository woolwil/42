#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] && !is_sep(str[i]))
		++i;
	return (i);
}

static char	*word_dupe(char *str)
{
	int		len = ft_wordlen(str);
	int		i = 0;
	char *word = malloc(sizeof(char) * (len + 1));
    if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**array;
	int		count = 0;
	int		i = 0;
	int		j = 0;

	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			++i;
		if (str[i])
			++count;
		while (str[i] && !is_sep(str[i]))
			++i;
	}
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (0);
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			++i;
		if (str[i])
			array[j++] = word_dupe(str + i);
		while (str[i] && !is_sep(str[i]))
			++i;
	}
	array[j] = 0;
	return (array);
}
