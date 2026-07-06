#include <unistd.h>

int skip(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		++i;
	return (i);
}

int len(char *s)
{
	int i = 0;

	while (s[i] && s[i] != ' ' && s[i] != '\t')
		++i;
	return (i);
}

int print_word(char *s, int i, int *first)
{
	int n;

	i = skip(s, i);
	n = len(s + i);
	if (!*first)
		write(1, " ", 1);
	write(1, s + i, n);
	*first = 0;
	return (i + n);
}

int epur(char *s)
{
	int i = 0, first = 1;

	i = skip(s, i);
	while (s[i])
	{
		i = print_word(s, i, &first);
		i = skip(s, i);
	}
	return (first);
}

int main(int ac, char **av)
{
	int i = 0, first;

	if (ac >= 2)
	{
		i = skip(av[1], i);
		i += len(av[1] + i);
		first = epur(av[1] + i);
		print_word(av[1], 0, &first);
	}
	write(1, "\n", 1);
	return (0);
}