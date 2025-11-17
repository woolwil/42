#include <unistd.h>
#include <stdio.h>

//Prototypes

void	ft_putchar(int length, int height); // remember to edit and remove the variables and put in void maybe?
void	rush(int length, int height); // remember to edit the ft_putchar and move the rest except write to here from ft_putchar

int	main(void)
{
	ft_putchar(3, 1);
	return (0);
}

void    ft_putchar(int length, int height)
{

	// integer for length
	int  l;
	// integer for (length - 2) to give space for 'A' and 'B'
	int  s;
	// integer for 'B' loop within line 1
	int b; 
	// integer for height
	int  h;
	// integer for height loop
	int hloop;
	// integer for (height - 1) to give space for the last 'B'
	int space;

	l = length;
	h = height;
	s = l -= 2;
	b = 0;
	hloop = 0;
	space = h -= 1;
	// First Line

	write(1, "A", 1);
	while	(b < s)
	{
		write(1, "B", 1);
		b++;
		if ( b == s)
		{
			write(1, "C\n", 3);
		}
	}

	// Lines based on height
	write(1, "B", 1);
	while	(hloop < h)
	{
		write(1, " ", 1);
		hloop++;
		if	(hloop == space)
		{
			write(1, "B\n", 1);
		}
	}
}
