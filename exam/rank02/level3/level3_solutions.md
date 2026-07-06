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


---

## 2. fprime

**Description:** Find and print the prime factors of a number separated by asterisks.

### Code
```c
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return 0;
		++i;
	}
	return 1;
}

void fprime(char *str)
{
	int n = atoi(str), factor = 2, first = 1;

	if (n == 1)
		printf("1");
	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			printf(first ? "%d" : "*%d", factor);
			first = 0;
			n /= factor;
		}
		else
			++factor;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return 0;
}
```


---

## 3. ft_itoa

**Description:** Convert an integer to a string representation (handles negative numbers).

### Code
```c
#include <stdlib.h>

int abs_val(int n)
{
	return (n < 0) ? -n : n;
}

int len(int n)
{
	int i = 0;

	if (n <= 0)
		++i;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char *ft_itoa(int n)
{
	char *res;
	int i = len(n);

	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--i;
		res[i] = abs_val(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
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
	t_list *list_ptr = begin_list;
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
	t_list *cur = *begin_list;

	if (!begin_list || !*begin_list)
		return;
	if (!cmp(cur->data, data_ref))
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


---

## 6. ft_split

**Description:** Split a string into an array of words (separated by spaces, tabs, or newlines).

### Code
```c
#include <stdlib.h>

static int is_sep(char c)
{
    return(c == ' ' || c == '\t' || c == '\0' || c == '\n');
}

static int word_len(char *s)
{
    int i = 0;
    while(s[i] && !is_sep(s[i]))
        ++i;
    return i;
}

static int word_count(char *s)
{
    int i = 0;
    int count = 0;
    while(s[i])
    {
        while(s[i] && is_sep(s[i]))
            ++i;
        if(s[i])
            ++count;
        while(s[i] && !is_sep(s[i]))
            ++i;
    }
    return count;
}

static char *word_dupe(char *s)
{
    int len = word_len(s);
    int i = 0;
    char *word = malloc(sizeof(char) * (len + 1));
    if(!word)
        return 0;
    while(i < len)
    {
        word[i] = s[i];
        ++i;
    }
    word[i] = '\0';
    return word;
}

char **ft_split(char *s)
{
    int count = word_count(s);
    char **array = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    int j = 0;
    
    if(!array)
        return 0;
    while(s[i])
    {
        while(s[i] && is_sep(s[i]))
            ++i;
        if(s[i])
            array[j++] = word_dupe(s + i);
        while(s[i] && !is_sep(s[i]))
            ++i;
    }
    array[j] = 0;
    return array;
}
```


---

## 7. rev_wstr

**Description:** Print the words of a string in reverse order.

### Code
```c
#include <unistd.h>#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int ac, char **av)
{
	int i = 0, printed = 0, start, end;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (av[1][i])
		++i;
	while (i > 0)
	{
		while (i > 0 && is_space(av[1][i - 1]))
			--i;
		end = i;
		while (i > 0 && !is_space(av[1][i - 1]))
			--i;
		start = i;
		if (printed)
			ft_putchar(' ');
		while (start < end)
			ft_putchar(av[1][start++]);
		printed = 1;
	}
	ft_putchar('\n');
	return (0);
}
```

---

## 8. rostring

**Description:** Rotate string - move the first word to the end of the string.

### Code
```c
#include <unistd.h>

int skip(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		++i;
	return (i);
}

int len(char *s)
{
	int i = 0;

	while (s[i] && s[i] != ' ' && s[i] != '\t')
		++i;
	return (i);
}

int print_word(char *s, int i, int *first)
{
	int n;

	i = skip(s, i);
	n = len(s + i);
	if (!*first)
		write(1, " ", 1);
	write(1, s + i, n);
	*first = 0;
	return (i + n);
}

int epur(char *s)
{
	int i = 0, first = 1;

	i = skip(s, i);
	while (s[i])
	{
		i = print_word(s, i, &first);
		i = skip(s, i);
	}
	return (first);
}

int main(int ac, char **av)
{
	int i = 0, first;

	if (ac >= 2)
	{
		i = skip(av[1], i);
		i += len(av[1] + i);
		first = epur(av[1] + i);
		print_word(av[1], 0, &first);
	}
	write(1, "\n", 1);
	return (0);
}
```


---

## 9. sort_int_tab

**Description:** Sort an array of integers in ascending order using bubble sort.

### Code
```c
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp;

	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			++i;
	}
}
```


---

## 10. sort_list

**Description:** Sort a linked list of integers using a comparison function.

### Code
```c
#include "ft_list.h"
#include <stdlib.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swap;
	t_list *tmp = lst;

	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
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
