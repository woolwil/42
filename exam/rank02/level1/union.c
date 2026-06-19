#include <unistd.h>

int main(int ac, char **av)
{
    unsigned char c;
    int i = 0, j = 0;
    int seen[256] = {0};
    
    if (ac == 3)
    {
        while(av[1][i])
        {
            c = av[1][i];
            if(seen[c] == 0)
            {
                write(1, &c, 1);
                seen[c] = 1;
            }
            i++;
        }
        while(av[2][j])
        {
            c = av[2][j];
            if (seen[c] == 0)
            {
                write(1, &c, 1);
                seen[c] = 1;
            }
            j++;
        }
    }
    write(1, "\n", 1);
}