#include <unistd.h>

int main(int ac, char **av)
{
    if(ac == 3)
    {
        unsigned char c;
        int i = 0, j = 0;
        int seen[256] = {0};

        while(av[1][i])
        {
            c = av[1][i];
            j = 0;
            
            while(av[2][j])
            {
                if(c == av[2][j] && seen[c] == 0)
                {
                    write(1, &c, 1);
                    seen[c] = 1;
                    break ;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}