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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 2
        WHILE argv[1][i] is not null terminator
            IF argv[1][i] is lowercase letter (a-z)
                argv[1][i] = 219 - argv[1][i] (mirror: a↔z, b↔y, etc)
            ELSE IF argv[1][i] is uppercase letter (A-Z)
                argv[1][i] = 155 - argv[1][i] (mirror uppercase)
            
            WRITE argv[1][i] to stdout
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    IF argc equals 2
        FOR each character i in argv[1]
            IF argv[1][i] is uppercase letter (A-Z)
                WRITE "_" to stdout
                argv[1][i] = argv[1][i] + 32 (convert to lowercase)
            
            WRITE argv[1][i] to stdout
        END FOR
    END IF
    
    WRITE newline to stdout
    RETURN EXIT_SUCCESS
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integers n1 = 0, n2 = 0, res = 0
    
    IF argc equals 4
        n1 = convert argv[1] to integer
        n2 = convert argv[3] to integer
        
        IF argv[2][0] is '+'
            res = n1 + n2
        ELSE IF argv[2][0] is '-'
            res = n1 - n2
        ELSE IF argv[2][0] is '*'
            res = n1 * n2
        ELSE IF argv[2][0] is '/'
            res = n1 / n2
        ELSE IF argv[2][0] is '%'
            res = n1 % n2
        
        PRINT res with newline
    ELSE
        WRITE newline to stdout
    END IF
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_atoi(string str)
    DECLARE integers nbr = 0, sig = 1, i = 0
    
    IF str[0] is '-' or '+'
        IF str[0] is '-'
            sig = -1
        INCREMENT i
    END IF
    
    WHILE str[i] exists AND str[i] is digit ('0'-'9')
        nbr = (nbr * 10) + (ASCII value of str[i] - ASCII '0')
        INCREMENT i
    END WHILE
    
    RETURN nbr * sig
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strcmp(string s1, string s2)
    DECLARE integer i = 0
    
    WHILE s1[i] equals s2[i] AND s1[i] is not null AND s2[i] is not null
        INCREMENT i
    END WHILE
    
    RETURN (ASCII value of s1[i]) - (ASCII value of s2[i])
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strcspn(string s, string reject)
    DECLARE size_t i = 0, k = 0
    
    WHILE s[i] is not null terminator
        WHILE reject[k] is not null terminator
            IF reject[k] equals s[i]
                RETURN i
            INCREMENT k
        END WHILE
        
        k = 0
        INCREMENT i
    END WHILE
    
    RETURN i
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strdup(string src)
    DECLARE integer i = 0
    DECLARE string dest
    
    WHILE src[i] is not null terminator
        INCREMENT i
    END WHILE
    
    dest = allocate memory for (i + 1) characters
    
    IF memory allocation fails
        RETURN NULL
    END IF
    
    i = 0
    WHILE src[i] is not null terminator
        dest[i] = src[i]
        INCREMENT i
    END WHILE
    
    dest[i] = src[i] (copy null terminator)
    RETURN dest
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strrev(string str)
    DECLARE integers i = -1, length = 0
    DECLARE character temporary
    
    WHILE str[length] exists
        INCREMENT length
    END WHILE
    
    WHILE ++i is less than (length / 2)
        temporary = str[i]
        str[i] = str[length - 1 - i]
        str[length - 1 - i] = temporary
    END WHILE
    
    RETURN str
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integers i = 0, k = 0, l = 0
    DECLARE strings s1, s2
    
    IF argc equals 3
        s1 = argv[1]
        s2 = argv[2]
        
        WHILE s1[i] is not null terminator
            k = 0
            WHILE s2[k] is not null terminator
                IF s1[i] equals s2[k]
					l = 0
					WHILE s1[l] is not equal to s1[i]
						INCREMENT l
					END WHILE

					IF l equals i
						l = 0
						WHILE s2[l] is not equal to s2[k]
							INCREMENT l
						END WHILE

						IF l equals k
							WRITE s1[i] to stdout
						END IF
                    END IF
                END IF
                INCREMENT k
            END WHILE
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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
			n = n / 2;
		else
			return (0);
	}
	return (1);
}
```

### Pseudocode
```
FUNCTION is_power_of_2(unsigned integer n)
    IF n equals 0
        RETURN 0 (zero is not a power of 2)
    END IF
    
    WHILE n is greater than 1
        IF n is divisible by 2
            n = n / 2
        ELSE
            RETURN 0 (not divisible by 2, so not a power of 2)
        END IF
    END WHILE
    
    RETURN 1 (successfully reduced to 1, so it is a power of 2)
END FUNCTION
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

### Pseudocode
```
FUNCTION last_word(string str)
    DECLARE integers j = 0, i = 0
    
    WHILE str[i] exists
        IF str[i] is space AND str[i+1] is printable character (ASCII 33-126)
            j = i + 1 (mark start of potential last word)
        INCREMENT i
    END WHILE
    
    WHILE str[j] is printable character (ASCII 33-126)
        WRITE str[j] to stdout
        INCREMENT j
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL last_word(argv[1])
    END IF
    
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION max(integer array tab, unsigned integer len)
    IF len equals 0
        RETURN 0
    END IF
    
    DECLARE integer res = tab[0]
    
    FOR i = 0 to i < len, INCREMENT i
        IF res is less than tab[i]
            res = tab[i]
        END IF
    END FOR
    
    RETURN res
END FUNCTION
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

### Pseudocode
```
FUNCTION print_bits(unsigned character octet)
    DECLARE integer i = 8
    DECLARE unsigned character bit
    
    WHILE i decrements (i--)
        bit = ((octet right-shift i positions) AND 1) + ASCII '0'
        WRITE bit to stdout
    END WHILE
END FUNCTION
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

### Pseudocode
```
FUNCTION reverse_bits(unsigned character octet)
    DECLARE integer i = 8
    DECLARE unsigned character res = 0
    
    WHILE i is greater than 0
        res = (res * 2) + (octet % 2) (extract last bit and shift result)
        octet = octet / 2 (remove last bit)
        DECREMENT i
    END WHILE
    
    RETURN res
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    IF argc equals 2
        FOR each character i in argv[1]
            IF argv[1][i] is underscore '_'
                INCREMENT i (skip underscore)
                argv[1][i] = argv[1][i] - 32 (convert to uppercase)
            
            WRITE argv[1][i] to stdout
        END FOR
    END IF
    
    WRITE newline to stdout
    RETURN EXIT_SUCCESS
END FUNCTION
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

### Pseudocode
```
FUNCTION swap_bits(unsigned character octet)
    high_nibble = octet right-shift 4 positions
    low_nibble = octet left-shift 4 positions
    RETURN (high_nibble) OR (low_nibble)
END FUNCTION
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

### Pseudocode
```
FUNCTION check(character c, string str, integer index)
    DECLARE integer i = 0
    
    WHILE i is less than index
        IF str[i] equals c
            RETURN 0 (character already appeared before)
        INCREMENT i
    END WHILE
    
    RETURN 1 (character is new, first occurrence)
END FUNCTION

FUNCTION main(argc, argv[])
    DECLARE integers i = 0, j = 0, k = 0
    
    IF argc equals 3
        WHILE argv[1][i] is not null terminator
            INCREMENT i
        END WHILE
        
        WHILE argv[2][j] is not null terminator
            argv[1][i] = argv[2][j]
            INCREMENT i
            INCREMENT j
        END WHILE
        
        i-- (move back from null terminator)
        
        WHILE k is less than or equal to i
            IF check(argv[1][k], argv[1], k) equals 1
                WRITE argv[1][k] to stdout
            INCREMENT k
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_putstr(string str)
    DECLARE integer i = 0
    
    WHILE str[i] exists
        WRITE str[i] to stdout
        INCREMENT i
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    DECLARE integers i = 0, j = 0
    
    IF argc equals 3
        WHILE argv[2][j] exists
            IF argv[2][j] equals argv[1][i]
                INCREMENT i (match found, move pointer in first string)
            INCREMENT j
        END WHILE
        
        IF argv[1][i] is null terminator (all characters matched)
            CALL ft_putstr(argv[1])
        END IF
    END IF
    
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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
