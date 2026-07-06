# Rank 02 - Level 0 Solutions

A comprehensive guide to all Level 0 exercises with code implementations and pseudocode explanations.

---

## 1. first_word

**Description:** Print the first word of the first argument (skip leading whitespace).

### Code
```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
		{
			ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
```


---

## 2. fizzbuzz

**Description:** Print numbers 1 to 100, with "fizz" for multiples of 3, "buzz" for multiples of 5, and "fizzbuzz" for multiples of both.

### Code
```c
#include <unistd.h>

int	main(void)
{
	int	i;
	int k;
	int l;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 5);
		else if (i > 10)
		{
			k = i / 10 + '0';
			l = i % 10 + '0';
			write (1, &k, 1);
			write (1, &l, 1);
		}
		else
		{
			k = i + '0';
			write(1, &k, 1);
		}
		write(1,"\n", 1);
		i++;
	}		
}
```


---

## 3. ft_putstr

**Description:** Output a string character by character to stdout.

### Code
```c
#include <unistd.h>

void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
```


---

## 4. ft_strcpy

**Description:** Copy a source string to a destination string (manual string copy).

### Code
```c
#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
```


---

## 5. ft_strlen

**Description:** Calculate the length of a string (count characters before null terminator).

### Code
```c
int     ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
```


---

## 6. ft_swap

**Description:** Swap the values of two integers using pointers.

### Code
```c
#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
```


---

## 7. repeat_alpha

**Description:** Repeat each alphabetic character by its position in the alphabet (a=1, b=2, ..., z=26).

### Code
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:36:24 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 11:57:20 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int k;
	char *str;

	i = 0;
	k = 1;
	if (ac ==2)
	{
		str = av[1];
		while (str[i] != '\0')
		{
			k = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
				k = str[i] - 64;
			if (str[i] >= 'a' && str[i] <= 'z')
				k = str[i] - 96;
			while (k >= 1)
			{
				write(1, &str[i], 1);
				k--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```


---

## 8. rev_print

**Description:** Print the input string in reverse order.

### Code
```c
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i += 1;
		while (i)
			write(1, &argv[1][--i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
```


---

## 9. rot_13

**Description:** Apply ROT13 cipher to the input string (rotate letters by 13 positions).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i] != '\0')
		{
			if ((av[1][i] >= 'a' && av[1][i]<= 'm') || (av[1][i] >= 'A' && av[1][i]<= 'M'))
				av[1][i] = av[1][i] + 13;
			else if ((av[1][i] >= 'n' && av[1][i]<= 'z') || (av[1][i] >= 'N' && av[1][i]<= 'Z'))
				av[1][i] = av[1][i] - 13;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);	
}
```


---

## 10. rotone

**Description:** Rotate each letter by 1 position ('a' becomes 'b', 'z' becomes 'a').

### Code
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:43:34 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 15:50:34 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i]!= '\0')
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'y') || (av[1][i] >= 'A' && av[1][i] <= 'Y'))
				av[1][i] = av[1][i] + 1;
			else if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] = av[1][i] - 25;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n",1);
}
```


---

## 11. search_and_replace

**Description:** Replace all occurrences of a character with another character in a string.

### Code
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchandreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:58:51 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 16:15:57 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 4)
	{
		if(((av[2][0] >= 'a' && av[2][0]<= 'z') || (av[2][0] >= 'A' && av[2][0]<= 'Z')) && av[2][1] == '\0')
			if (((av[3][0] >= 'a' && av[2][0]<= 'z') || (av[3][0] >= 'A' && av[3][0]<= 'Z')) && av[3][1] == '\0')
			{
				while (av[1][i] != '\0')
				{
					if (av[1][i] == av[2][0])
							av[1][i] = av[3][0];
					write(1, &av[1][i], 1);
					i++;
				}
			}
	}
	write(1, "\n", 1);
}
```


---

## 12. ulstr

**Description:** Convert uppercase letters to lowercase and lowercase letters to uppercase (toggle case).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = av[1][i] - 32;
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = av[1][i] + 32;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
```


---

## Summary

| Exercise | Purpose |
|----------|---------|
| first_word | Extract first word from argument |
| fizzbuzz | Classic FizzBuzz algorithm |
| ft_putstr | Output string to stdout |
| ft_strcpy | Manual string copy |
| ft_strlen | Count string length |
| ft_swap | Swap two integer values |
| repeat_alpha | Repeat letters by alphabet position |
| rev_print | Print string in reverse |
| rot_13 | ROT13 cipher encoding |
| rotone | Caesar cipher (shift by 1) |
| search_and_replace | Character replacement |
| ulstr | Toggle letter case |
