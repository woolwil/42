#include <stdlib.h>

int abs_val(int n)
{
    return(n < 0) ? -n : n;
}

int len(int n)
{
    int i = 0;
    if(n < 0)
        ++i;
    while(n != 0)
    {
        ++i;
        n /= 10;
    }
    return i;
}

char *ft_itoa(int n)
{
    int i = len(n);
    char *res = malloc(sizeof(char) * (i + 1));
    res[i] = '\0';
    if(n < 0)
        res[0] = '-';
    else if(n == 0)
        res[0] = '0';
    while(n != 0)
    {
        --i;
        res[i] = abs_val(n % 10) + '0';
        n /= 10;
    }
    return res;
}