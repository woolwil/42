#include <unistd.h>

int main(int ac, char **av)
{
    char *arg1 = av[1];
    char *arg2 = av[2];
    char *arg3 = av[3];
    int i = 0;

    if (ac == 4)
    {
        while (arg2[i] && arg3[i])
        {
            if (i > 1)
                return (write(1, "\n", 1));
            i++;
        }
        i = 0;
        while (arg1[i])
        {
            if (arg1[i] == arg2[0])
                arg1[i] = arg3[0];
            write(1, &arg1[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}