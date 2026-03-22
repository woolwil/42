#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2) // s1 = dest | s2 = src
{
	int i = 0;

	if (!s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	char dest[100];
	char *src = "aylol";

	ft_strcpy(dest, src);
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);
	return (0);
}