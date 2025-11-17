// strcpy()
// These functions copy the string pointed to by src, into a string at the buffer pointed to by dst. 
// The programmer is responsible for allocating a destination buffer large enough, that is, strlen(src) + 1. 
// For the difference between the two functions, see RETURN VALUE.

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(int length, char *str);
char	*ft_strcpy(char *dest, char *src);

int	main(int argc, char *argv[])
{
	int	strlen = ft_strlen(argc, argv[1]);
	char destination[200];
	ft_strcpy(destination, argv[1]);
	printf("\n");
	printf("Destination: %s\n", destination);
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

char	*ft_strcpy(char *dest, char *src)
{
	char *original_pointer = dest;
	int n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (original_pointer);
}