#include <unistd.h>

int ft_atoi(char *s)
{
    int n = 0;

    while(*s && (*s >= '0' || *s <= '9'))
    {
        n *= 10;
        n += *s - '0';
        ++s;
    }
    return n;
}

void ft_putnbr(int n)
{
    if(n > 9)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

void tab_mult(char *s)
{
    int i = 1, n = ft_atoi(s);

    while(i <= 9)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(n);
        write(1, " = ", 3);
        ft_putnbr(i * n);
        write(1, "\n", 1);
        ++i;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        tab_mult(av[1]);
    else
        write(1, "\n", 1);
}