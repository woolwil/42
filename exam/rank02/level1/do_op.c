#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int do_op(int one, char  two, int three)
{
    if(two == '+')
        return(one + three);
    else if(two == '-')
        return(one - three);
    else if(two == '*')
        return(one * three);
    else if(two == '/')
        return(one / three);
    else if(two == '%')
        return(one % three);
    else
        return 0;
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        int one = atoi(av[1]);
        char *two = av[2];
        int three = atoi(av[3]);
        int result = 0;
        
        result = do_op(one, two[0], three);
        printf("%d\n", result);
    }
    else
        write(1, "\n", 1);
}