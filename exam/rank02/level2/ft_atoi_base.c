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