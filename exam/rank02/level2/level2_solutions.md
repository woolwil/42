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

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int		add_prime_sum(int n)
{
	int sum = 0;
	int i = 2;

	while (i <= n)
	{
		if (is_prime(i) == 1)
			sum += i;
		++i;
	}
	return (sum);
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

### Pseudocode
```
FUNCTION ft_atoi(string str)
    DECLARE integer n = 0
    WHILE *str is digit ('0' to '9')
        n = n * 10
        n = n + (*str - '0')
        INCREMENT str
    RETURN n
END FUNCTION

FUNCTION ft_putnbr(integer n)
    IF n is >= 10
        CALL ft_putnbr(n / 10)
    character c = (n % 10) + '0'
    WRITE c to stdout
END FUNCTION

FUNCTION is_prime(integer n)
    DECLARE integer i = 2
    WHILE i < n
        IF n % i equals 0
            RETURN 0 (not prime)
        INCREMENT i
    RETURN 1 (is prime)
END FUNCTION

FUNCTION add_prime_sum(integer n)
    DECLARE integers sum = 0, i = 2
    WHILE i <= n
        IF is_prime(i) is 1
            sum = sum + i
        INCREMENT i
    RETURN sum
END FUNCTION

FUNCTION main(argc, argv[])
    DECLARE integer n
    IF argc equals 2 AND n = ft_atoi(argv[1])
        CALL ft_putnbr(add_prime_sum(n))
    ELSE
        CALL ft_putnbr(0)
    WRITE newline to stdout
    RETURN 0
END FUNCTION
```

---

## 2. epur_str

**Description:** Remove extra whitespace - keep only single spaces between words.

### Code
```c
#include <unistd.h>

int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	epur_str(char *str)
{
	int i = 0;
	int first_word = 1;
	int word_len;

	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		if (first_word == 0)
			write(1, " ", 1);
		word_len = ft_wordlen(str + i);
		write(1, str + i, word_len);
		i = i + word_len;
		first_word = 0;
		i = skip_whitespace(str, i);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
```

### Pseudocode
```
FUNCTION skip_whitespace(string str, integer i)
    WHILE str[i] is space or tab
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION ft_wordlen(string str)
    DECLARE integer i = 0
    WHILE str[i] is not null AND str[i] is not space AND str[i] is not tab
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION epur_str(string str)
    DECLARE integers i = 0, first_word = 1, word_len
    
    i = skip_whitespace(str, i)
    WHILE str[i] is not null terminator
        IF first_word equals 0
            WRITE " " to stdout
        word_len = ft_wordlen(str + i)
        WRITE word_len characters from str+i to stdout
        i = i + word_len
        first_word = 0
        i = skip_whitespace(str, i)
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL epur_str(argv[1])
    WRITE newline to stdout
    RETURN 0
END FUNCTION
```

---

## 3.   

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

### Pseudocode
```
FUNCTION word_len(string str)
    DECLARE integer i = 0
    WHILE str[i] is not null AND str[i] is not space AND str[i] is not tab
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION expand_str(string str)
    DECLARE integers len, first_word = 1
    
    WHILE *str is not null terminator
        WHILE *str is space or tab
            INCREMENT str
        len = word_len(str)
        IF len > 0 AND first_word equals 0
            WRITE "   " (3 spaces) to stdout
        first_word = 0
        WRITE len characters from str to stdout
        str = str + len
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL expand_str(argv[1])
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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
    else if(c >= 'A' && c <= 'F')
        digit = c - 'A' + 10;

    if(digit != -1 && digit < base)
        return digit;
    else
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
    return (n * sign);
}
```

### Pseudocode
```
FUNCTION to_lower(character c)
    IF c is uppercase (A-Z)
        RETURN c + difference between 'a' and 'A'
    RETURN c
END FUNCTION

FUNCTION get_digit(character c, integer digits_in_base)
    DECLARE integer max_digit
    IF digits_in_base <= 10
        max_digit = digits_in_base + '0'
    ELSE
        max_digit = digits_in_base - 10 + 'a'
    
    IF c in range '0'-'9' AND c <= max_digit
        RETURN c - '0'
    ELSE IF c in range 'a'-'f' AND c <= max_digit
        RETURN 10 + c - 'a'
    
    RETURN -1
END FUNCTION

FUNCTION ft_atoi_base(string str, integer str_base)
    DECLARE integers result = 0, sign = 1, digit
    
    IF *str is '-'
        sign = -1
        INCREMENT str
    
    WHILE (digit = get_digit(to_lower(*str), str_base)) >= 0
        result = result * str_base
        result = result + (digit * sign)
        INCREMENT str
    
    RETURN result
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_list_size(node begin_list)
    IF begin_list is NULL
        RETURN 0
    ELSE
        RETURN 1 + ft_list_size(begin_list->next)
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_range(integer start, integer end)
    DECLARE integers size, i = 0
    DECLARE integer array res
    
    size = absolute value of (end - start) + 1
    res = allocate memory for size integers
    
    IF memory allocation fails
        RETURN NULL
    
    IF start < end
        WHILE start <= end
            res[i] = start
            INCREMENT start
            INCREMENT i
        END WHILE
    ELSE
        WHILE start >= end
            res[i] = start
            DECREMENT start
            INCREMENT i
        END WHILE
    
    RETURN res
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_rrange(integer start, integer end)
    DECLARE integers number_of_ints, step, i = 0
    DECLARE integer array
    
    number_of_ints = 1 + absolute_value(end - start)
    array = allocate memory for number_of_ints integers
    
    IF start > end
        step = 1
    ELSE
        step = -1
    
    WHILE i < number_of_ints
        array[i] = end
        end = end + step
        INCREMENT i
    
    RETURN array
END FUNCTION
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

### Pseudocode
```
FUNCTION hidenp(string probe, string target)
    WHILE *probe is not null terminator
        WHILE *probe != *target AND *target is not null terminator
            INCREMENT target
        
        IF *target is null terminator
            WRITE "0" to stdout (not hidden)
            RETURN
        
        INCREMENT target
        INCREMENT probe
    
    WRITE "1" to stdout (all characters found in order)
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 3
        CALL hidenp(argv[1], argv[2])
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION lcm(unsigned integer a, unsigned integer b)
    DECLARE unsigned integer n
    
    IF a equals 0 OR b equals 0
        RETURN 0
    
    IF a > b
        n = a
    ELSE
        n = b
    
    LOOP indefinitely
        IF n is divisible by both a and b
            RETURN n
        INCREMENT n
    END LOOP
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_putnbr(integer n)
    DECLARE character digit
    
    IF n >= 10
        CALL ft_putnbr(n / 10)
    
    digit = (n % 10) + '0'
    WRITE digit to stdout
END FUNCTION

FUNCTION main(argc, argv[])
    CALL ft_putnbr(argc - 1) (subtract 1 for program name)
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION pgcd(integer a, integer b)
    DECLARE integer n = a
    
    WHILE n > 0
        IF a % n equals 0 AND b % n equals 0
            PRINT n
            RETURN
        DECREMENT n
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 3
        CALL pgcd(convert argv[1] to int, convert argv[2] to int)
    PRINT newline
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_atoi(string str)
    DECLARE integer n = 0
    WHILE *str is not null terminator
        n = n * 10
        n = n + (*str - '0')
        INCREMENT str
    RETURN n
END FUNCTION

FUNCTION print_hex(integer n)
    DECLARE string hex_digits = "0123456789abcdef"
    
    IF n >= 16
        CALL print_hex(n / 16)
    WRITE hex_digits[n % 16] to stdout
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL print_hex(ft_atoi(argv[1]))
    WRITE newline to stdout
END FUNCTION
```

---

## 13. rstr_capitalizer

**Description:** Capitalize the last character of each word, lowercase all others.

### Code
```c
#include <unistd.h>

void	str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'a' && *str <= 'z' && (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\t'))
				*str = *str - ('a' - 'A');
			else if (*str >= 'A' && *str <= 'Z' && *(str + 1) != '\0' && *(str + 1) != ' ' && *(str + 1) != '\t')
				*str = *str + ('a' - 'A');
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			++i;
		}
	}

	return (0);
}
```

### Pseudocode
```
FUNCTION str_capitalizer(string str)
    WHILE *str is not null terminator
        WHILE *str is not null AND (*str is space or tab)
            WRITE *str to stdout
            INCREMENT str
        
        WHILE *str is not null AND *str is not space AND *str is not tab
            IF *str is lowercase AND next char is end or space or tab
                *str = convert to uppercase
            ELSE IF *str is uppercase AND next char is not end and not space and not tab
                *str = convert to lowercase
            
            WRITE *str to stdout
            INCREMENT str
        END WHILE
    END WHILE
    WRITE newline to stdout
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 1
        WRITE newline to stdout
    ELSE
        FOR i = 1 to i < argc
            CALL str_capitalizer(argv[i])
    
    RETURN 0
END FUNCTION
```

---

## 14. str_capitalizer

**Description:** Capitalize the first character of each word, lowercase the rest.

### Code
```c
#include <unistd.h>

void	str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}

		if (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - ('a' - 'A');
			write(1, str, 1);
			++str;
		}

		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'A' && *str <= 'Z')
				*str = *str + ('a' - 'A');
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			++i;
		}
	}

	return (0);
}
```

### Pseudocode
```
FUNCTION str_capitalizer(string str)
    WHILE *str is not null terminator
        WHILE *str is not null AND (*str is space or tab)
            WRITE *str to stdout
            INCREMENT str
        
        IF *str is not null
            IF *str is lowercase
                *str = convert to uppercase
            WRITE *str to stdout
            INCREMENT str
        
        WHILE *str is not null AND *str is not space AND *str is not tab
            IF *str is uppercase
                *str = convert to lowercase
            
            WRITE *str to stdout
            INCREMENT str
        END WHILE
    END WHILE
    WRITE newline to stdout
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 1
        WRITE newline to stdout
    ELSE
        FOR i = 1 to i < argc
            CALL str_capitalizer(argv[i])
    
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_atoi(string str)
    DECLARE integer n = 0
    WHILE *str is digit ('0' to '9')
        n = n * 10
        n = n + (*str - '0')
        INCREMENT str
    RETURN n
END FUNCTION

FUNCTION ft_putnbr(integer n)
    IF n >= 10
        CALL ft_putnbr(n / 10)
    character c = (n % 10) + '0'
    WRITE c to stdout
END FUNCTION

FUNCTION tab_mult(string str)
    DECLARE integers n, i = 1
    n = ft_atoi(str)
    
    WHILE i <= 9
        CALL ft_putnbr(i)
        WRITE " x " to stdout
        CALL ft_putnbr(n)
        WRITE " = " to stdout
        CALL ft_putnbr(i * n)
        WRITE newline to stdout
        INCREMENT i
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL tab_mult(argv[1])
    ELSE
        WRITE newline to stdout
    RETURN 0
END FUNCTION
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
