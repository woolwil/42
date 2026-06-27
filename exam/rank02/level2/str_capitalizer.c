#include <unistd.h>

void str_capitalizer(char *c)
{
    while(*c)
    {
        while(*c && (*c == ' ' || *c == '\t'))
        {
            write(1, c, 1);
            ++c;
        }
        if(*c)
        {
            if(*c >= 'a' && *c <= 'z')
                *c -= 32;
            write(1, c, 1);
            ++c;
        }
        while(*c && *c != ' ' && *c != '\t')
        {
            if(*c >= 'A' && *c <= 'Z')
                *c += 32;
            write(1, c, 1);
            ++c;
        }
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while(i < ac)
        {
            str_capitalizer(av[i]);
            ++i;
        }
    }
    write(1, "\n", 1);
}