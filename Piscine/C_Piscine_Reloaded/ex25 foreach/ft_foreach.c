#include <unistd.h>

// Function to apply f to each element of tab
void	ft_foreach(int *tab, int length, void (*f)(int)) 
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

// Function to print an integer followed by a newline
void ft_print_item(int n) 
{
    ft_putnbr(n); 
    ft_putchar('\n');
}

int	main(void)
{
	int	tab[20];
	int	len = 20;
	int	j = 0;
	
	while (j < len)
	{
		tab[j] = j + 1;
		j++;
	}
	ft_foreach(tab, len, &ft_print_item);
	return (0);
}