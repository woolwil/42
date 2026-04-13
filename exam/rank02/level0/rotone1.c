#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        char *args = argv[1];

        while (args[i])
        {
            if (args[i] == 'z')
                args[i] = 'a';
            else if (args[i] == 'Z')
                args[i] = 'A';
            else if ((args[i] >= 'a' && args[i] <= 'y') || (args[i] >= 'A' && args[i] <= 'Y'))
                args[i] += 1;
            write(1, &args[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
