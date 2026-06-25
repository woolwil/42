#include <unistd.h>

int main(int ac, char **av)
{
    if(ac == 3)
    {
        unsigned char seen[256] = {0};
        int i = 0, j = 0;

        while(av[1][i])
        {
            if(seen[(unsigned char)av[1][i]] == 0)
            {
                write(1, &av[1][i], 1);
                seen[(unsigned char)av[1][i]] = 1;
            }
            else
                i++;
        }
        while(av[2][j])
        {
            if(seen[(unsigned char)av[2][j]] == 0)
            {
                write(1, &av[2][j], 1);
                seen[(unsigned char)av[2][j]] = 1;
            }
            else
                j++;
        }
    }
    write(1, "\n", 1);
}