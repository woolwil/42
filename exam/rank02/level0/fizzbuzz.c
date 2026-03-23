#include <unistd.h>

void	putnbr(int n);

int	main(void)
{
	int	i = 1;

	while (i != 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write (1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		putnbr(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}


void putnbr(int n)
{
	if (n > 9)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}
