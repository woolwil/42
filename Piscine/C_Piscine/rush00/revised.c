/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:44:44 by ngvo              #+#    #+#             */
/*   Updated: 2025/09/28 15:44:55 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int length, int height);
void	first_row(int length);
void	middle_row(int length, int height);
void	last_row(int length, int height);

int	main(void)
{
	rush(1, 5);
	return (0);
}

//Prototype to input a character to print
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Rush prototype that takes all other functions
void	rush(int length, int height)
{
	if	(length != 0 && height !=0)
	{
	first_row(length);
	middle_row(length, height);
	last_row(length, height);
	}
}

void	first_row(int length)
{
	int	l;

	l = 0;
	//First Row print code
	//Print 'A' on first line
	if	(length > 1)
	{ 
		ft_putchar('A');
	}
	else if	(length == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	//Print 'B', where length - 2 = to save 2 characters for 'A' and 'B'
	while	(l < length - 2)
	{
		ft_putchar('B');
		l++;
	}
	//Print 'C' when B loop finishes
	if (length > 1)
	{
	ft_putchar('C');
	ft_putchar('\n');
	}
}

void	middle_row(int length, int height)
{
	//Column print code
	int h;
	int d;

	h = 0;
	d = 0;
	
	while	(d < height - 2)
	{
	if  (length >= 1)
	{
	ft_putchar('B');
	}
	while	(h < length -2)
	{
	ft_putchar(' ');
	h++;
	}
	if	(length > 1)
	{
	ft_putchar('B');
	}
	ft_putchar('\n');
	d++;
	h = 0;
	}
}

void	last_row(int length, int height)
{
	//Last Row print code
	//Print 'A' on first line
	int l;

	l = 0;
	//l variable reset -> allows for last line to loop with the same code
	if	(height != 1)
	{
	if	(length > 0)
	{ 
	ft_putchar('C');
	}
	//Print 'B', where length - 2 = to save 2 characters for 'A' and 'B'
	while  (l < length - 2)
		{
			ft_putchar('B');
			l++;
		}
		//Print 'A' when B loop finishes
		if (length > 1)
		{
			ft_putchar('A');
			ft_putchar('\n');
		}
	}
	if (length == 1 && height != 1)
	ft_putchar('\n');
}
