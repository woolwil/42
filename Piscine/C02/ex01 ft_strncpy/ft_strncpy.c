#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(int length, char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(int argc, char *argv[])
{
	int	strlen = ft_strlen(argc, argv[1]);
	int count = strlen;
	char *dest = (char *)malloc((count + 1) * sizeof(char)); //Alocate memory for one character, +1 for the '\0'
	if (dest == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	ft_strncpy(dest, argv[1], count);
	printf("\n");
	printf("Destination: %s\n", dest);
	printf("\n");
	printf("Strlen: %d\n", strlen);
	return (0);
}

int	ft_strlen(int length, char *str)
{
	int	n = 0;
	if (length == 2)
	{
		while (*str != '\0')
		{
			n++;
			str++;
		}
	}
	else
	{
		printf("invalid input for strlen\n");
	}
	return (n);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	char *og_ptr = dest;
	while(*src != '\0' && i < n)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	while (i < n)
	{
	dest[i] = '\0';
	i++;
	}
	return (og_ptr);
}