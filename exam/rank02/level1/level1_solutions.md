# Rank 02 - Level 1 Solutions

A comprehensive guide to all Level 1 exercises with code implementations and pseudocode explanations.

---

## 1. alpha_mirror

**Description:** Mirror the alphabet - convert letters based on their distance from the ends (a↔z, b↔y, etc).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        
        while(av[1][i])
        {
            if(av[1][i] >= 'a' && av[1][i] <= 'z')
                av[1][i] = 'a' + 'z' - av[1][i];
            else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
                av[1][i] = 'A' + 'Z' - av[1][i];
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
```


---

## 2. camel_to_snake

**Description:** Convert camelCase to snake_case (insert underscore before uppercase letters and convert to lowercase).

### Code
```c
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i += 1)
		{
			if (argv[1][i] >= 'A' 
			&& argv[1][i] <= 'Z')
			{
				write(STDOUT_FILENO, "_", 1);
				argv[1][i] += 32;
			}
			write(STDOUT_FILENO, &argv[1][i], 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return EXIT_SUCCESS;
}
```


---

## 3. do_op

**Description:** Perform arithmetic operations (+, -, *, /, %) on two numbers based on an operator argument.

### Code
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n1 = 0;
	int n2 = 0;
	int	res = 0;

	if (ac == 4)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[3]);
		if (av[2][0] == '+')
			res = n1 + n2;
		else if (av[2][0] == '-')
			res = n1 - n2;
		else if (av[2][0] == '*')
			res = n1 * n2;
		else if (av[2][0]== '/')
			res = n1 / n2;
		else if (av[2][0] == '%')
			res = n1 % n2;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
}
```


---

## 4. ft_atoi

**Description:** Convert a string representation of a number to an integer (handles optional +/- sign).

### Code
```c
#include <stdio.h>

int     ft_atoi(const char *str)
{
	int	nbr;
	int sig;
	int	i;

	nbr = 0;
	sig = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sig = -1;
		i += 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sig);
}
```


---

## 5. ft_strcmp

**Description:** Compare two strings lexicographically and return the difference.

### Code
```c
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
```


---

## 6. ft_strcspn

**Description:** Find the length of the initial segment of a string that doesn't contain any characters from a reject set.

### Code
```c
#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (reject[k])
		{
			if (reject[k] == s[i])
				return (i);
			k++;
		}
		k = 0;
		i++;
	}
	return (i);
}
```


---

## 7. ft_strdup

**Description:** Allocate memory and create a duplicate of a string.

### Code
```c
#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int	i;
	char *dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
```


---

## 8. ft_strrev

**Description:** Reverse a string in place by swapping characters from start and end.

### Code
```c
char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}
```


---

## 9. inter

**Description:** Print the intersection of two strings (common characters that appear in both, without duplicates).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0, j;
    unsigned char seen[256] = {0};

    if (ac == 3)
    {
        while(av[1][i])
        {
            if(!seen[(unsigned char)av[1][i]])
            {
                j = 0;
                while(av[2][j])
                {
                    if(av[1][i] == av[2][j])
                    {
                        write(1, &av[1][i], 1);
                        seen[(unsigned char)av[1][i]] = 1;
                        break ;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
```


---

## 10. is_power_of_2

**Description:** Check if an unsigned integer is a power of 2.

### Code
```c
#include <stdio.h>

int         is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			return (0);
	}
	return (1);
}
```


---

## 11. last_word

**Description:** Print the last word of the input string (word is defined as printable characters).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while(av[1][i])
            i++;
        i--;
        while(i && av[1][i] == ' ')
            i--;
        while(i && av[1][i] != ' ')
            i--;
        while(av[1][i + 1] && av[1][i + 1] != ' ')
        {
            write(1, &av[1][i + 1], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
```


---

## 12. max

**Description:** Find the maximum value in an array of integers.

### Code
```c
int	max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);
	int res = tab[0];
	for (unsigned int i = 0; i < len; i += 1)
	{
		if (res < tab[i])
			res = tab[i];
	}
	return (res);
}
```


---

## 13. print_bits

**Description:** Print the binary representation of an unsigned char (8 bits).

### Code
```c
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
```


---

## 14. reverse_bits

**Description:** Reverse the bits of an unsigned char (e.g., 00000001 becomes 10000000).

### Code
```c
unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

unsigned char	reverse_bits(unsigned char octet)
{
    int		i = 8;
    unsigned char	res = 0;

    while (i > 0)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
        i--;
    }
    return (res);
}
```


---

## 15. snake_to_camel

**Description:** Convert snake_case to camelCase (remove underscores and capitalize next letter).

### Code
```c
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        for(int i = 0; av[1][i]; i++)
        {
            if(av[1][i] == '_')
            {
                i++;
                av[1][i] -= 32;
            }
            write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
}
```


---

## 16. swap_bits

**Description:** Swap the high 4 bits and low 4 bits of an unsigned char.

### Code
```c
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
```


---

## 17. union

**Description:** Print all unique characters from the concatenation of two strings (without duplicates).

### Code
```c
#include <unistd.h>

int check(char c, char *str, int idx)
{
    for(int i = 0; i < idx; i++)
        if(str[i] == c)
            return 0;
    return 1; 
}

int main(int ac, char **av)
{
    int i = 0, j = 0, k = 0;

    if (ac == 3)
    {
        while (av[1][i])
            i++;
        while (av[2][j])
            av[1][i++] = av[2][j++];
        i--;
        for(k = 0; k <= i; k++)
        {
            if(check(av[1][k], av[1], k) == 1)
                write(1, &av[1][k], 1);
        }
    }
    write(1, "\n", 1);
}
```


---

## 18. wdmatch

**Description:** Check if all characters of the second string appear in the first string in the same order.

### Code
```c
#include <unistd.h>

void ft_putstr(char const *str)
{
	int i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i++;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
```


---

## Summary

| Exercise | Purpose |
|----------|---------|
| alpha_mirror | Mirror alphabet (a↔z, b↔y) |
| camel_to_snake | Convert camelCase to snake_case |
| do_op | Arithmetic operations (+, -, *, /, %) |
| ft_atoi | String to integer conversion |
| ft_strcmp | String comparison |
| ft_strcspn | Find span not containing reject chars |
| ft_strdup | Allocate and duplicate string |
| ft_strrev | Reverse string in place |
| inter | Find common characters in two strings |
| is_power_of_2 | Check if number is power of 2 |
| last_word | Extract last word from string |
| max | Find maximum in array |
| print_bits | Display binary representation |
| reverse_bits | Reverse bits of unsigned char |
| snake_to_camel | Convert snake_case to camelCase |
| swap_bits | Swap high and low 4 bits |
| union | Print unique characters from two strings |
| wdmatch | Check if chars of 2nd string in 1st (in order) |
