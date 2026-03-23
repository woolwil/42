#include <unistd.h>

int	main(int ac, char **av)
{
	int		i = 0;
	char	*str;
	int		c = 0;
	int		j = 0;

	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				c = str[i] - 'a' + 1;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				c = str[i] - 'A' + 1;
			else 
				c = 1;
			while (j != c)
			{
				write (1, &str[i], 1);
				j++;
			}
			j = 0;
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
