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

### Pseudocode
```
FUNCTION ft_putchar(character c)
    WRITE character c to stdout (file descriptor 1)
END FUNCTION

FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF number of arguments equals 2
        WHILE argv[1][i] is space or tab
            INCREMENT i
        END WHILE
        
        WHILE argv[1][i] is not null terminator AND not space AND not tab
            CALL ft_putchar(argv[1][i])
            INCREMENT i
        END WHILE
    END IF
    
    CALL ft_putchar(newline)
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION main()
    DECLARE integer i = 1, k, l
    
    WHILE i is less than or equal to 100
        IF i is divisible by both 3 and 5
            WRITE "fizzbuzz" to stdout
        ELSE IF i is divisible by 3
            WRITE "fizz" to stdout
        ELSE IF i is divisible by 5
            WRITE "buzz" to stdout
        ELSE IF i is greater than 10
            k = (i divided by 10) + ASCII '0'
            l = (i modulo 10) + ASCII '0'
            WRITE k and l as characters to stdout
        ELSE
            k = i + ASCII '0'
            WRITE k as character to stdout
        END IF
        
        WRITE newline to stdout
        INCREMENT i
    END WHILE
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_putstr(string str)
    DECLARE integer i = 0
    
    WHILE str[i] is not null terminator
        WRITE str[i] to stdout
        INCREMENT i
    END WHILE
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strcpy(string s1, string s2)
    DECLARE integer i = 0
    
    WHILE s2[i] is not null terminator
        s1[i] = s2[i]
        INCREMENT i
    END WHILE
    
    s1[i] = null terminator
    RETURN s1
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_strlen(string str)
    DECLARE integer i = 0
    
    WHILE str[i] is not null terminator
        INCREMENT i
    END WHILE
    
    RETURN i
END FUNCTION
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

### Pseudocode
```
FUNCTION ft_swap(pointer a, pointer b)
    DECLARE integer temp
    
    temp = *a (dereference pointer a)
    *a = *b (a now points to b's value)
    *b = temp (b now points to original a's value)
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0, k = 1
    DECLARE string str
    
    IF argc equals 2
        str = argv[1]
        
        WHILE str[i] is not null terminator
            k = 1
            
            IF str[i] is uppercase letter (A-Z)
                k = str[i] - 64 (calculate position: A=1, B=2, ..., Z=26)
            
            IF str[i] is lowercase letter (a-z)
                k = str[i] - 96 (calculate position: a=1, b=2, ..., z=26)
            
            WHILE k is greater than or equal to 1
                WRITE str[i] to stdout
                DECREMENT k
            END WHILE
            
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
    RETURN 0
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 2
        WHILE argv[1][i] is not null terminator
            INCREMENT i
        END WHILE
        
        WHILE i is not zero
            DECREMENT i
            WRITE argv[1][i] to stdout
        END WHILE
    END IF
    
    WRITE newline to stdout
    RETURN 0
END FUNCTION
```

---

## 9. rot_13

**Description:** Apply ROT13 cipher to the input string (rotate letters by 13 positions).

### Code
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:44 by galpers           #+#    #+#             */
/*   Updated: 2022/04/06 15:40:03 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 2
        WHILE argv[1][i] is not null terminator
            IF argv[1][i] is in range [a-m] OR [A-M]
                argv[1][i] = argv[1][i] + 13
            ELSE IF argv[1][i] is in range [n-z] OR [N-Z]
                argv[1][i] = argv[1][i] - 13
            
            WRITE argv[1][i] to stdout
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 2
        WHILE argv[1][i] is not null terminator
            IF argv[1][i] is in range [a-y] OR [A-Y]
                argv[1][i] = argv[1][i] + 1
            ELSE IF argv[1][i] is 'z' or 'Z'
                argv[1][i] = argv[1][i] - 25 (wrap around to a or A)
            
            WRITE argv[1][i] to stdout
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 4
        IF argv[2] is a single alphabetic character AND argv[3] is a single alphabetic character
            WHILE argv[1][i] is not null terminator
                IF argv[1][i] equals argv[2][0]
                    argv[1][i] = argv[3][0]
                
                WRITE argv[1][i] to stdout
                INCREMENT i
            END WHILE
        END IF
    END IF
    
    WRITE newline to stdout
END FUNCTION
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

### Pseudocode
```
FUNCTION main(argc, argv[])
    DECLARE integer i = 0
    
    IF argc equals 2
        WHILE argv[1][i] is not null terminator
            IF argv[1][i] is lowercase letter (a-z)
                argv[1][i] = argv[1][i] - 32 (convert to uppercase)
            ELSE IF argv[1][i] is uppercase letter (A-Z)
                argv[1][i] = argv[1][i] + 32 (convert to lowercase)
            
            WRITE argv[1][i] to stdout
            INCREMENT i
        END WHILE
    END IF
    
    WRITE newline to stdout
END FUNCTION
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
