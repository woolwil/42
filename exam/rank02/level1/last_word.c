#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;

        while(av[1][i])
            i++;
        i--;
        while(i && av[1][i] == ' ')
            i--;
        while(i && av[1][i] != ' ')
            i--;
        while(av[1][i + 1] && av[1][i + 1] != ' ')
        {
            write(1, &av[1][i + 1], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}