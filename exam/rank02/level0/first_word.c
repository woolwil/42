#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' && av[1][i] != '\t')
		{
			i++;
		}
		while (av[1][i] && av[1][i] != ' ')
		{
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

#include <unistd.h>

int main(int ac, char **av)
{
    char *args = av[1];
    int i = 0;

    if (ac == 2)
    {
        while(args[i] == ' ')
            i++;
        while(args[i])
        {
            if (args[i] == ' ')
                break ;
            else
                write(1, &args[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}