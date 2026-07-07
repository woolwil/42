#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int ac, char **av)
{
	int i = 0, printed = 0, start, end;

	if (ac == 2)
	{
        while (av[1][i])
            ++i;
        while (i > 0)
        {
            while (i > 0 && is_space(av[1][i - 1]))
                --i;
            end = i;
            while (i > 0 && !is_space(av[1][i - 1]))
                --i;
            start = i;
            if (printed)
                ft_putchar(' ');
            while (start < end)
                ft_putchar(av[1][start++]);
            printed = 1;
        }
	}
	ft_putchar('\n');
	return (0);
}