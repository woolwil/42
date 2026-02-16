#include <string.h>
#include <stdio.h>

int	is_longer_than_3(char *str)
{
	int	len = strlen(str);
	if (len > 3)
		return (1);
	else
		return (0);
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	i;
	int	fd;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		fd = f(tab[i]);
		if (fd == 1)
			count++;
		i++;
	}
	return (count);
}

// int	ft_count_if(char **tab, int (*f)(char*))
// {
// 	int	count;

// 	count = 0;
// 	while (*tab)
// 		count += f(*tab++);
// 	return (count);
// }

int	main()
{
	char	*str_arr[] = 
	{
		"car",     // Length 3 (Not counted)
        "house",   // Length 5 (COUNTED)
        "desk",    // Length 4 (COUNTED) <-- Added
        "a",       // Length 1 (Not counted)
        "laptop",  // Length 6 (COUNTED) <-- Added
		NULL
	};
	printf("%d\n", ft_count_if(str_arr, &is_longer_than_3));
	return (0);
}
