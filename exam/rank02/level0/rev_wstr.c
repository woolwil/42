#include <stdio.h>

int ft_strlen(char *s)
{
    int len = 0;
    while(s[len])
        ++len;
    return len;
}

char *rev_wstr(const char *s)
{
    static char str[1000];
    int i = 0;
    int len = ft_strlen((char *)s);
    while(i < len)
    {
        str[i] = s[len - 1 - i];
        ++i;
    }
    str[i] = '\0';
    return str;
}

int main(int ac, char **av)
{
    if (ac > 1)
        printf("%s\n", rev_wstr(av[1]));
    return 0;
}