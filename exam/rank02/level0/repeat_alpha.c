#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int c = 0;
    char *args = av[1];

    if (ac == 2)
    {
        while(args[i])
        {
            if (args[i] >= 'a' && args[i] <= 'z')
                c = args[i] - 'a' + 1;
            else if (args[i] >= 'A' && args[i] <= 'Z')
                c = args[i] - 'A' + 1;
            else
                c = 1;
            while (j != c)
            {
                write(1, &args[i], 1);
                j++;
            }
            j = 0;
            i++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}
