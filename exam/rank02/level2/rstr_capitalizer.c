#include <unistd.h>

int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void rstr_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		// Lowercase all letters by default
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

		// If a character is a letter and is followed by a separator,
		// it's the last letter of a word, so capitalize it.
		if ((str[i] >= 'a' && str[i] <= 'z') && is_separator(str[i + 1]))
			str[i] -= 32;

		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}