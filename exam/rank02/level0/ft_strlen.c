int	ft_strlen(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		j++;
		i++;
	}
	return (j);
}