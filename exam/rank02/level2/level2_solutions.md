# Rank 02 - Level 2 Solutions

A comprehensive guide to all Level 2 exercises with code implementations and pseudocode explanations.

---

## 1. add_prime_sum

**Description:** Sum all prime numbers up to and including a given number.

### Code
```c
#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int is_prime(int n)
{
    if(n < 2)
        return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int add_prime_sum(int n)
{
    int sum = 0;
    for(int i = 2; i <= n; i++)
        if(is_prime(i) == 1)
            sum += i;
    return sum;
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2 && (n = ft_atoi(argv[1])))
		ft_putnbr(add_prime_sum(n));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
```


---

## 2. epur_str

**Description:** Remove extra whitespace - keep only single spaces between words.

### Code
```c
#include <unistd.h>

int word_len(char *s)
{
    int len = 0;
    while(s[len] && s[len] != ' ' && s[len] != '\t')
        ++len;
    return len;
}

void epur_str(char *s)
{
    int len;
    int first_word = 1;

    while(*s)
    {
        while(*s == ' ' || *s == '\t')
            ++s;
        len = word_len(s);
        if(len > 0 && first_word == 0)
            write(1, " ", 1);
        first_word = 0;
        write(1, s, len);
        s = s + len;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        epur_str(av[1]);
    }
    write(1, "\n", 1);
}
```


---

## 3.   expand_str

**Description:** Expand spacing - replace single spaces with three spaces between words.

### Code
```c
#include <unistd.h>

int		word_len(char *str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	expand_str(char *str)
{
	int len;
	int first_word = 1;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		len = word_len(str);
		if (len > 0 && first_word == 0)
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str = str + len;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);

	write(1, "\n", 1);
	return (0);
}
```


---

## 4. ft_atoi_base

**Description:** Convert a string in a given base to a decimal integer.

### Code
```c
int get_digit(char c, int base)
{
    int digit = -1;

    if(c >= '0' && c <= '9')
        digit = c - '0';
    else if(c >= 'a' && c <= 'f')
        digit = c - 'a' + 10;
    else if(c >= 'A' && c <= 'f')
        digit = c - 'A' + 10;
    
    if(digit >= 0 && digit < base)
        return digit;
    return -1;
}

int ft_atoi_base(const char *str, int str_base)
{
    int n = 0;
    int sign = 1;
    int digit;

    if(*str == '-')
    {
        sign = -sign;
        ++str;
    }
    while((digit = get_digit(*str, str_base)) >= 0)
    {
        n = n * str_base + digit;
        ++str;
    }
    return(n * sign);
}
```


---

## 5. ft_list_size

**Description:** Count the number of nodes in a linked list.

### Code
```c
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}
```

### ft_list.h Structure
```c
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
```


---

## 6. ft_range

**Description:** Create an array of integers from start to end (inclusive).

### Code
```c
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = abs((end - start)) + 1;
	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start += 1;
			i += 1;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start -= 1;
			i += 1;
		}
	}
	return (res);
}
```


---

## 7. ft_rrange

**Description:** Create an array of integers from start to end in reverse order.

### Code
```c
#include <stdlib.h>

int		absolute_value(int n);

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);

	if (start > end)
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
	return (array);
}
```


---

## 8. hidenp

**Description:** Check if all characters of the first string appear in the second string in the same order.

### Code
```c
#include <unistd.h>

void	hidenp(char *probe, char *target)
{
	while (*probe != '\0')
	{
		while (*probe != *target && *target != '\0')
			++target;
		if (*target == '\0')
		{
			write(1, "0", 1);
			return;
		}
		++target;
		++probe;
	}
	write(1, "1", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
```


---

## 9. lcm

**Description:** Calculate the least common multiple of two numbers.

### Code
```c
unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}
```


---

## 10. paramsum

**Description:** Count the number of command-line arguments (excluding the program name).

### Code
```c
#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n > 9)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error

	ft_putnbr(argc - 1);
	write(1, "\n", 1);

	return (0);
}
```


---

## 11. pgcd

**Description:** Calculate the greatest common divisor (GCD) of two numbers.

### Code
```c
#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));

	printf("\n");
	return (0);
}
```


---

## 12. print_hex

**Description:** Convert a decimal number to hexadecimal and print it.

### Code
```c
#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));

	write(1, "\n", 1);
}
```


---

## 13. rstr_capitalizer

**Description:** Capitalize the last character of each word, lowercase all others.

### Code
```c
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
```


---

## 14. str_capitalizer

**Description:** Capitalize the first character of each word, lowercase the rest.

### Code
```c
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
```


---

## 15. tab_mult

**Description:** Print a multiplication table for a given number (1x to 9x).

### Code
```c
// Passed Moulinette 2019.09.02

#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}

void	tab_mult(char *str)
{
	int n;
	int i = 1;

	n = ft_atoi(str);
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
```


---

## Summary

| Exercise | Purpose |
|----------|---------|
| add_prime_sum | Sum all prime numbers up to n |
| epur_str | Remove extra whitespace |
| expand_str | Expand spacing (1 space → 3 spaces) |
| ft_atoi_base | Convert string in base to decimal |
| ft_list_size | Count linked list nodes |
| ft_range | Create array from start to end |
| ft_rrange | Create array from start to end (reversed) |
| hidenp | Check if chars in order (subsequence) |
| lcm | Least common multiple |
| paramsum | Count command-line arguments |
| pgcd | Greatest common divisor (GCD) |
| print_hex | Decimal to hexadecimal conversion |
| rstr_capitalizer | Capitalize last char of words |
| str_capitalizer | Capitalize first char of words |
| tab_mult | Print multiplication table (1-9) |
