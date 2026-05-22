# Rank 02 - Level 3 Solutions

A comprehensive guide to all Level 3 exercises with code implementations and pseudocode explanations.

---

## 1. flood_fill

**Description:** Implement a flood fill algorithm (like a paint bucket tool in image editors).

### Code
```c
typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;
 
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
```

### Pseudocode
```
STRUCTURE t_point
    integer x
    integer y
END STRUCTURE

FUNCTION fill(2D array tab, t_point size, t_point cur, character to_fill)
    IF cur.y < 0 OR cur.y >= size.y OR cur.x < 0 OR cur.x >= size.x
        RETURN (out of bounds)
    
    IF tab[cur.y][cur.x] != to_fill
        RETURN (different color, stop filling)
    
    tab[cur.y][cur.x] = 'F' (mark as filled)
    
    CALL fill(tab, size, (cur.x-1, cur.y), to_fill) (left)
    CALL fill(tab, size, (cur.x+1, cur.y), to_fill) (right)
    CALL fill(tab, size, (cur.x, cur.y-1), to_fill) (up)
    CALL fill(tab, size, (cur.x, cur.y+1), to_fill) (down)
END FUNCTION

FUNCTION flood_fill(2D array tab, t_point size, t_point begin)
    character original_color = tab[begin.y][begin.x]
    CALL fill(tab, size, begin, original_color)
END FUNCTION
```

---

## 2. fprime

**Description:** Find and print the prime factors of a number separated by asterisks.

### Code
```c
#include <stdio.h>
#include <stdlib.h>

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

void	fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n = n / factor;
		}
		else
			++factor;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);

	printf("\n");
	return (0);
}
```

### Pseudocode
```
FUNCTION is_prime(integer n)
    DECLARE integer i = 2
    WHILE i < n
        IF n % i equals 0
            RETURN 0 (not prime)
        INCREMENT i
    RETURN 1 (is prime)
END FUNCTION

FUNCTION fprime(string str)
    DECLARE integers n = convert str to int, factor = 2, first = 1
    
    IF n equals 1
        PRINT "1"
    
    WHILE factor <= n
        IF n is divisible by factor AND is_prime(factor)
            IF first equals 1
                PRINT factor
            ELSE
                PRINT "*" + factor
            first = 0
            n = n / factor (divide out this prime factor)
        ELSE
            INCREMENT factor
        END IF
    END WHILE
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc equals 2
        CALL fprime(argv[1])
    PRINT newline
    RETURN 0
END FUNCTION
```

---

## 3. ft_itoa

**Description:** Convert an integer to a string representation (handles negative numbers).

### Code
```c
#include <stdlib.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
{
	int len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';

	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}
```

### Pseudocode
```
FUNCTION absolute_value(integer nbr)
    IF nbr < 0
        RETURN -nbr
    RETURN nbr
END FUNCTION

FUNCTION get_len(integer nbr)
    DECLARE integer len = 0
    IF nbr <= 0
        INCREMENT len (for negative sign or extra for 0)
    
    WHILE nbr != 0
        INCREMENT len
        nbr = nbr / 10
    
    RETURN len
END FUNCTION

FUNCTION ft_itoa(integer nbr)
    DECLARE string result
    DECLARE integer len
    
    len = get_len(nbr)
    result = allocate memory for len + 1 characters
    result[len] = null terminator
    
    IF nbr < 0
        result[0] = '-'
    ELSE IF nbr equals 0
        result[0] = '0'
    
    WHILE nbr != 0
        DECREMENT len
        result[len] = absolute_value(nbr % 10) + '0'
        nbr = nbr / 10
    
    RETURN result
END FUNCTION
```

---

## 4. ft_list_foreach

**Description:** Apply a function to every element in a linked list.

### Code
```c
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
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
FUNCTION ft_list_foreach(node begin_list, function f)
    DECLARE node list_ptr = begin_list
    
    WHILE list_ptr is not NULL
        CALL function f with list_ptr->data
        list_ptr = list_ptr->next
    END WHILE
END FUNCTION
```

---

## 5. ft_list_remove_if

**Description:** Remove all nodes from a linked list where the comparison function returns 0.

### Code
```c
#include <stdlib.h>
#include "ft_list.h"

int cmp(void *a, void *b);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&cur->next, data_ref, cmp);
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
FUNCTION ft_list_remove_if(pointer to node begin_list, void data_ref, comparison function cmp)
    IF begin_list is NULL OR *begin_list is NULL
        RETURN
    
    DECLARE node cur = *begin_list
    
    IF cmp(cur->data, data_ref) equals 0 (match found)
        *begin_list = cur->next (skip this node)
        FREE cur
        RECURSIVELY CALL ft_list_remove_if on updated begin_list
    ELSE
        RECURSIVELY CALL ft_list_remove_if on cur->next
    END IF
END FUNCTION
```

---

## 6. ft_split

**Description:** Split a string into an array of words (separated by spaces, tabs, or newlines).

### Code
```c
#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}
```

### Pseudocode
```
FUNCTION ft_wordlen(string str)
    DECLARE integer i = 0
    WHILE str[i] is not null AND not space AND not tab AND not newline
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION word_dupe(string str)
    DECLARE integers i = 0, len = ft_wordlen(str)
    DECLARE string word = allocate memory for len + 1 characters
    word[len] = null terminator
    
    WHILE i < len
        word[i] = str[i]
        INCREMENT i
    
    RETURN word
END FUNCTION

FUNCTION fill_words(string array, string str)
    DECLARE integer word_index = 0
    
    SKIP all whitespace (space, tab, newline)
    WHILE *str is not null terminator
        array[word_index] = word_dupe(str)
        INCREMENT word_index
        SKIP all non-whitespace characters
        SKIP all whitespace characters
    END WHILE
END FUNCTION

FUNCTION count_words(string str)
    DECLARE integer num_words = 0
    
    SKIP all whitespace at start
    WHILE *str is not null terminator
        INCREMENT num_words
        SKIP all non-whitespace characters
        SKIP all whitespace characters
    END WHILE
    
    RETURN num_words
END FUNCTION

FUNCTION ft_split(string str)
    DECLARE integers num_words
    DECLARE string array
    
    num_words = count_words(str)
    array = allocate memory for num_words + 1 string pointers
    array[num_words] = NULL (null-terminate array)
    CALL fill_words(array, str)
    
    RETURN array
END FUNCTION
```

---

## 7. rev_wstr

**Description:** Print the words of a string in reverse order.

### Code
```c
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp);
		rev = NULL;
		len--;
		while (tmp[len])
		{
			if (tmp[len - 1] == ' ')
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				ft_putchar(' ');
			}
			else if (len == 0)
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
			}
			len--;
		}
	}
	ft_putchar('\n');
}
```

### Pseudocode
```
FUNCTION ft_putchar(character c)
    WRITE c to stdout
END FUNCTION

FUNCTION ft_strlen(string str)
    DECLARE integer i = 0
    WHILE str[i] exists
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION main(argc, argv[])
    DECLARE strings tmp, rev
    DECLARE integer len
    
    IF argc equals 2
        tmp = argv[1]
        len = ft_strlen(tmp)
        len-- (start from last character)
        
        WHILE tmp[len] exists
            IF tmp[len - 1] is space (found word boundary)
                rev = pointer to start of current word
                WHILE *rev exists AND *rev is not space
                    CALL ft_putchar(*rev)
                    INCREMENT rev
                CALL ft_putchar(' ')
            
            ELSE IF len equals 0 (first word)
                rev = pointer to start of first word
                WHILE *rev exists AND *rev is not space
                    CALL ft_putchar(*rev)
                    INCREMENT rev
            
            DECREMENT len
        END WHILE
    
    CALL ft_putchar(newline)
END FUNCTION
```

---

## 8. rostring

**Description:** Rotate string - move the first word to the end of the string.

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

int		print_word(char *str, int i, int *is_first)
{
	int word_len;

	i = skip_whitespace(str, i);
	word_len = ft_wordlen(str + i);
	if (*is_first == 0)
		write(1, " ", 1);
	write(1, str + i, word_len);
	*is_first = 0;
	return (i + word_len);
}

int		epur_str(char *str)
{
	int i = 0;
	int is_first = 1;

	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		i = print_word(str, i, &is_first);
		i = skip_whitespace(str, i);
	}
	return (is_first);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		char *str = argv[1];
		int i = 0;
		int is_first;

		i = skip_whitespace(str, i);
		i = i + ft_wordlen(str + i);
		is_first = epur_str(str + i);
		print_word(str, 0, &is_first);
	}
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
    WHILE str[i] is not null AND not space AND not tab
        INCREMENT i
    RETURN i
END FUNCTION

FUNCTION print_word(string str, integer i, pointer is_first)
    DECLARE integer word_len
    
    i = skip_whitespace(str, i)
    word_len = ft_wordlen(str + i)
    
    IF *is_first equals 0
        WRITE " " to stdout
    
    WRITE word_len characters from str+i to stdout
    *is_first = 0
    RETURN i + word_len
END FUNCTION

FUNCTION epur_str(string str)
    DECLARE integers i = 0, is_first = 1
    
    i = skip_whitespace(str, i)
    WHILE str[i] is not null terminator
        i = print_word(str, i, &is_first)
        i = skip_whitespace(str, i)
    
    RETURN is_first
END FUNCTION

FUNCTION main(argc, argv[])
    IF argc >= 2
        str = argv[1]
        i = skip_whitespace(str, 0)
        i = i + ft_wordlen(str + i) (skip first word)
        is_first = epur_str(str + i) (print remaining words)
        print_word(str, 0, &is_first) (print first word at end)
    
    WRITE newline to stdout
    RETURN 0
END FUNCTION
```

---

## 9. sort_int_tab

**Description:** Sort an array of integers in ascending order using bubble sort.

### Code
```c
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
```

### Pseudocode
```
FUNCTION sort_int_tab(integer array tab, unsigned integer size)
    DECLARE unsigned integer i = 0
    DECLARE integer temp
    
    WHILE i < (size - 1)
        IF tab[i] > tab[i + 1]
            temp = tab[i]
            tab[i] = tab[i + 1]
            tab[i + 1] = temp
            i = 0 (restart from beginning after swap)
        ELSE
            INCREMENT i
        END IF
    END WHILE
END FUNCTION
```

---

## 10. sort_list

**Description:** Sort a linked list of integers using a comparison function.

### Code
```c
#include "ft_list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
```

### ft_list.h Structure
```c
typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
```

### Pseudocode
```
FUNCTION sort_list(node lst, comparison function cmp)
    DECLARE integer swap
    DECLARE node tmp = lst
    
    WHILE lst->next is not NULL
        IF cmp(lst->data, lst->next->data) equals 0 (swap needed)
            swap = lst->data
            lst->data = lst->next->data
            lst->next->data = swap
            lst = tmp (restart from beginning after swap)
        ELSE
            lst = lst->next
        END IF
    END WHILE
    
    lst = tmp (reset to head)
    RETURN lst
END FUNCTION
```

---

## Summary

| Exercise | Purpose |
|----------|---------|
| flood_fill | Flood fill algorithm (paint bucket) |
| fprime | Prime factorization of a number |
| ft_itoa | Integer to string conversion |
| ft_list_foreach | Apply function to list elements |
| ft_list_remove_if | Remove matching nodes from list |
| ft_split | Split string into word array |
| rev_wstr | Print words in reverse order |
| rostring | Rotate string (move first word to end) |
| sort_int_tab | Sort integer array (bubble sort) |
| sort_list | Sort linked list using comparison function |
