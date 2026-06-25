int ft_atoi(const char *str)
{
    int nbr = 0;
    int sign = 1;
    int i = 0;
    
    if(str[0] == '-' || str[0] == '+')
    {
        if(str[0] == '-')
            sign = -sign;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9' && str[i])
        nbr = (nbr * 10) + (str[i++] - '0');
    return (nbr * sign);
}