#include <unistd.h>

int ft_atoi(char *s)
{
    int n = 0;

    while(*s >= '0' && *s <= '9')
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
        putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int is_prime(int n)
{
    int i = 2;

    while(i < n)
    {
        if(n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int add_prime_sum(int n)
{
    int i = 2;
    int sum = 0;

    while(i <= n)
    {
        if(is_prime(i) == 1)
            sum += i;
        ++i;
    }
    return sum;
}

int main(int ac, char **av)
{
    if (ac == 2)
        add_prime_sum(ft_atoi(av[1]));
    else
        ft_putnbr(0);
    write(1, "\n", 1);
}