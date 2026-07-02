#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        int n = a;
        while(n)
        {
            if(a % n == 0 && b % n == 0)
            {
                printf("%d", n);
                break ;
            }
            --n;
        }
    }
    printf("\n");
}