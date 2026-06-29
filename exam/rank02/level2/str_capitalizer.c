#include <unistd.h>

int is_separator(char c)
{
	return (c == ' ' || c == '\t');
}

void str_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((i == 0 || is_separator(str[i - 1])) && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		else if (!(i == 0 || is_separator(str[i - 1])) && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] += 32;

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
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}